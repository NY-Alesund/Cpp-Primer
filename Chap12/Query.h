/*************************************************************************
	> File Name: Query.h
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月20日 星期五 22时03分49秒
 ************************************************************************/

/* 文本查询程序再探 */

/*
 *两个操作：
 *eval:接受一个TextQuery对象并返回一个QueryResult,eval函数使用给定的TextQuery对象查找与之匹配的行
 *rep: 返回基础查询的string表示形式，eval函数使用rep创建一个表示匹配结果的QueryResult,输出运算符使用rep打印查询表达式
 */

/* 这是一个抽象基类，具体的查询类型都是从中派生，所有成员都是private的 */
class Query_base {
	friend class Query;
	protected:
		using line_no = TextQuery::line_no;		//用于eval函数
		virtual ~Query_base() = default;
	private:
		//eval返回与当前Query匹配的QueryResult
		virtual QueryResult eval(const TextQuery&) const = 0;
		//rep是表示查询的一个string
		virtual std::string rep() const = 0;
}；

/* 这是一个管理Query_base继承体系的接口类 */
class Query {
	//这些运算符需要访问接受shared_ptr的构造函数，而该函数是私有的
	friend Query operator~(const Query &);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);
public:
	Query(const std::string&);					//构建一个新的wordQuery
	//接口函数:调用对应的Query_base操作
	QueryResult eval(const TextQuery &t) const { return q->eval(t); }
	std::string rep() const { return q->rep(); }
private:
	Query(std::shared_ptr<Query_base>  query) : q(query) { }
	std::shared_ptr<Query_base> q;
};

/* WordQuery类 */
class WordQuery: public Query_base {
	friend class Query;							//Query使用WordQuery构造函数
	WordQuery(const std::string &s): query_word(s) { }
	//具体的类:WordQuery将定义所有继承而来的纯虚函数
	QueryResult eval(const TextQuery &t) const { return t.query(query_word); }
	std::string rep() const { return query_word; }
	std::string query_word;						//要查找的单词
};

/* 定义了WordQuery类之后，就能定义接受string的Query构造函数 */
inline Query::Query(const std::string &s): q(new WordQuery(s)) { }

/* NotQuery类及~运算符 */
class NotQuery: public Query_base {
	friend	Query operator~(const Query &);
	NotQuery(const Query &q): query(q) { }
	//具体的类:NotQuery将定义所有继承而来的纯虚函数
	std::string rep() const { return "~(" + query.rep() + ")" ;}
	QueryResult eval(const TextQuery&) const;
	Query query;
};

inline Query operator~(const Query &operand)
{
	return std::shared_ptr<Query_base>(new NotQuery(operand));
}

/* BinaryQuery类:抽象基类，保存操作两个运算对象的查询类型所需的函数 */
class BinaryQuery: public Query_base {
	protected:
		BinaryQuery(const Query &l, const Query &r, std::string s):
					lhs(l), rhs(r), opSym(s) { }
		//抽象类:BinaryQuery不定义eval
		std::string rep() const { return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")" ;}
		Query lhs, rhs;		//左侧和右侧运算对象
		std::string  opSym;	//运算符的名字
};

/* AndQuery类和OrQuery类以及它们的运算符：非常相似 */
class AndQuery: public BinaryQuery {
	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query &left, const Query &right): BinaryQuery(left,right,"&") { }
	//具体的类：AndQuery继承了rep并且定义了其它纯虚函数
	QueryResult eval(const TextQuery&) const;
};
inline	Query operator&(const Query &lhs, const Query &rhs)
{
	return std::shared_ptr<Query_base>(new AndQuery(lhs,rhs));
}

class OrQuery: public BinaryQuery {
	friend Query operator|(const Query&, const Query&);
	OrQuery(const Query &left, const Query &right) : BinaryQuery(left,right,"|") { }
	QueryResult eval(const TextQuery&) const;
};
inline Query operator|(const Query &lhs, const Query &rhs)
{
	return std::shared_ptr<Query_base>(new OrQuery(lhs,rhs));
}

/* eval函数：查询系统的核心。*/

/* OrQuery::eval */
//返回运算对象查询结果set的并集
QueryResult
OrQuery::eval(const TextQuery& text) const
{
	//通过Query成员lhs和rhs进行的虚调用
	//调用eval返回每个运算符对象的QueryResult
	auto right = rhs.eval(text), left = lhs.eval(text);
	//将左侧运算对象的行号拷贝到结果set中
	auto ret_lines = make_shared<set<line_no>>(left.begin(),left.end());
	//插入右侧运算对象所得的行号
	ret_lines->insert(right.begin(),right.end());
	//返回一个新的QueryResult,它表示lhs和rhs的并集
	return QueryResult(rep(),ret_lines,left.get_file());
}

/* AndQuery::eval */
//返回运算对象查询结果set的交集
QueryResult
AndQuery::eval(const TextQuery& text) const
{
	//通过Query运算对象进行的虚调用，以获得运算对象的查询结果set
	auto left = lhs.eval(text), right = rhs.eval(text);
	//保存left和right交集的set
	auto ret_lines = make_shared<set<line_no>>();
	//将两个范围的交集写入一个目的迭代器中
	//本次调用的目的迭代器向ret添加元素
	set_intersection(left.begin(),left.end(),
					right.begin(),right.end(),
					inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(),ret_lines,left.get_file());
}

/* NotQuery::eval */
//返回运算对象的结果set中不存在的行
QueryResult
NotQuery::eval(const TextQuery& text) const
{
	//通过Query运对象对eval进行虚调用
	auto result = query.eval(text);
	//开始时结果set为空
	auto ret_lines = make_shared<set<line_no>>();
	//我们必须在运算对象出现的所有行中进行迭代
	auto beg = result.begin(),end = result.end();
	//对于输入文件的每一行，如果该行不在result当中，则将其添加到ret_lines
	auto sz = result.get_file()->size();
	for (size_t n = 0; n != sz; ++n) {
		//如果我们还没有处理完result的所有行
		//检查当前行是否存在
		if (beg == end || *beg != n)
			ret_lines->insert(n);			//如果不在result当中，添加这一行
		else if (beg != end)
			++beg;			//否则继续获取result的下一行(如果有)
	}
	return QueryResult(rep(), ret_lines,result.get_file());
}
