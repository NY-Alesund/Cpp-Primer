/*************************************************************************
	> File Name: HasPtr.h
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月19日 星期四 11时35分55秒
 ************************************************************************/

class HasPtr {
	public:
			//构造函数
			HasPtr(const std::string &s = std::string());
				ps(new std::string(s)),i(0) { }
			
				HasPtr(const HasPtr&);
				HasPtr& operator=(const HasPtr);
				~HasPtr();
	private:
			std::string *ps;
			int i;
};

/* 定义拷贝构造函数 */
HasPtr::HasPtr(const HasPtr &hp) {
	ps = new string(*hp.ps);		//拷贝ps指向的对象,而不是拷贝指针本身
	i = hp.i;						
}

/* 定义拷贝赋值运算符 */
HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
	auto newps = new string(*rhs.ps);		//拷贝指针指向的对象
	delete ps;								//销毁原ps
	ps = newps;								//指向新string
	i = rhs.i;								//使用内置的int赋值
	return *this;							//返回此对象的引用
}

HasPtr::~HasPtr()
{
	delete ps;
}



