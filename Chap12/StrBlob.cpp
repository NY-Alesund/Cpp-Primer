/*************************************************************************
	> File Name: StrBlob.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月16日 星期一 20时26分29秒
 ************************************************************************/

#include<iostream>
#include<memory>
using namespace std;

class StrBlob {
	public:
		typedef std::vecotr<std::string>::size_type size_type;
		StrBlob();
		StrBlob(std::initializer_list<std::string> il);
		size_type size() const { return data->size(); }
		bool empty() const { return data->empty(); }
		//添加和删除元素
		void push_back(const std::string &t) {data->push_back(t);}
		void pop_back();
		//元素访问
		std::string& front();
		std::string& back();
	private:
		std::shared_ptr<std::vector<std::string>> data;
		//如果data[i]不合法，抛出一个异常
		void check(size_type i, const std::string &msg) const;
};

//构造函数
StrBlob::StrBlob(): data(make_shared<vector<string>>()) {}
SreBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}
