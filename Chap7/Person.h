/*************************************************************************
	> File Name: Person.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月07日 星期六 15时52分21秒
 ************************************************************************/

//编写一个Person类

#include<iostream>
using namespace std;

class Person
{
private:
	string strName;		//姓名
	string strAddress;  //地址
public:
	//得到姓名和地址
	string getName() const { return strName; }
	string getAddress() const {	return strAddress;}
	//读取和打印
	std::istream &read(std::istream &is,Person &per)
	{
		is >> per.strName >> per.strAddress;
		return is;
	}
	std::ostream &print(std::ostream &os,const Person &per)
	{
		os << per.getName() << per.getAddress();
		return os;
	}
public:
	//构造函数
	Person() = default;
	Person(const string &name, const string &add)
	{
		strName = name;
		strAddress = add;
	}
	Person(std::istream &is) { is >> *this}
}
