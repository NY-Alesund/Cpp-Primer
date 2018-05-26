/*************************************************************************
	> File Name: My-StrBlob.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月17日 星期二 15时38分27秒
 ************************************************************************/

#ifndef MY_STRBLOB_H
#define MY_STRBLOB_H
#include<vector>
#include<string>
#include<initializer_list>
#include<memory>
#include<stdexcept>

using namespace std;

//提前声明,StrBlob中的友元函数所需
class StrBlobPtr;

class StrBlob {
	friend class StrBlobPtr;
	public:
		typedef vector<string>::size_type size_type;
		
		/* 构造函数初始化 */
		StrBlob();
		StrBlob(initializer_list<string> il);
		
		size_type size() const { return data->size(); }
		bool empty() const { return data->empty(); }
		
		//添加和删除元素
		void push_back(const string &t) { data->push_back(t); }
		void pop_back();					//
		
		//元素访问
		string& front();
		const string& front() const;		//const重载
		string& back();
		const string& back() const;			//const重载
		

		//提供给StrBlobPtr的接口
		StrBlobPtr begin();		//定义了SrtBlobPtr之后才能定义这两个函数
		StrBlobPtr end();
	private:
		shared_ptr<std::vector<string>> data;
		//如果data[i]不合法，抛出一个异常
		void check(size_type i, const std::string &msg) const;
};

/* 构造函数 */
inline StrBlob::StrBlob() : data(make_shared<vector<string>> ()) { }		//默认构造函数,分配一个空vector<string>
StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) { }
//接受一个initializer_list的参数il,传递给make_shared函数,创建个string的vector对象，并创建一个shared_ptr指向此对象

inline void StrBlob::check(size_type i,const string &msg) const 
{
	if (i >= data->size())
		throw out_of_range(msg);
}

inline string& StrBlob::front()
{
	//如果vector为空，check会抛出一个异常
	check(0,"front on empty StrBlob");
	return data->front();
}

//const版本front
inline const string& StrBlob::front() const
{
	check(0,"front on empty StrBlob");
	return data->front();
}

inline string& StrBlob::back()
{
	check(0,"back on empty StrBlob");
	return data->back();
}

//const版本back
inline const string& StrBlob::back()	const
{
	check(0,"back on empty StrBlob");
	return data->back();
}


inline void StrBlob::pop_back()
{
	check(0,"pop_back on empty StrBlob");
	data->pop_back();
}

//当试图访问一个不存在的元素时，StrBlobPtr抛出一个异常
class StrBlobPtr {
	friend bool eq(const StrBlobPtr&, const StrBlobPtr&);
	public:
		StrBlobPtr() : curr(0) { }
		StrBlobPtr(StrBlob &a,size_t sz = 0) : wptr(a.data), curr(sz) { }

		string& deref() const;
		StrBlobPtr& incr();		//前缀递增
		StrBlobPtr& decr();		//前缀递减
	private:
		//若检查成功，check返回一个指向vector的shared_ptr
		shared_ptr<vector<string>> check(size_t,const string&) const;
		
		//保存一个weak_ptr，意味着底层vector可能被销毁
		weak_ptr<vector<string>> wptr;
		size_t curr;			//在数组中当前位置
};

inline shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const
{
	auto ret = wptr.lock();		//vector还存在吗? lock返回一个指向wptr的对象的shared_ptr
	if (!ret)
		throw runtime_error("unbound StrBlobPtr");
	if(i >= ret->size())
		throw out_of_range(msg);
	return ret;					//否则，返回指向vector<string>的shared_ptr
}

inline string& StrBlobPtr::deref() const
{
	auto p = check(curr,"dereference past end");
	return (*p) [curr];			//(*p)是对象所指向的vector
}

//前缀递增:返回递增后的对象的引用
inline StrBlobPtr& StrBlobPtr::incr()		//incr = increase
{
	//如果curr已经指向容器的尾后位置，就不能递增它
	check(curr,"increment past end of StrBlobPtr");
	++curr;			//推进当前位置
	return *this;
}

//前缀递减:返回递减后的对象的引用
inline StrBlobPtr& StrBlobPtr::decr()		//decr = decrease
{
	//如果curr已经为0，递减它就会产生一个非法下标
	--curr;			//递减当前位置
	check(-1,"decrement past begin of StrBlobPtr");
	return *this;
}

//StrBlob的begin和end成员的定义
inline StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::end()
{
	auto ret = StrBlobPtr(*this,data->size());
	return ret;
}

//StrBlobPtr的比较操作
inline bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	auto l = lhs.wptr.lock(), r= rhs.wptr.lock();
	//若底层的vector是同一个
	if (l == r)
		//则两个指针都是空，或者指向相同元素时，它们相等
		return (!r || lhs.curr == rhs.curr);
	else
		return false;		//若指向不同vector，则不可能相等
}

inline bool neq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return !eq(lhs,rhs); /* 不相等时，返回true */
}

#endif




