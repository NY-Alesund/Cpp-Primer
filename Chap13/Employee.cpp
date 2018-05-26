/*************************************************************************
	> File Name: Employee.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月19日 星期四 13时43分26秒
 ************************************************************************/

/* 定义一个Employee类,包含雇员的姓名和唯一的雇员证号 */
 
#include<iostream>
#include<string>
using namespace std;

class Employee {
	public:
		Employee () { mysn = sn++; }
		Employee (const string &s) { name = s; mysn = sn++; }
		
		//拷贝定义函数
		Employee (Employee &e) { name = e.name; mysn = sn++; }
		//拷贝赋值运算符
		Employee& operator=(Employee &rhs) { name = rhs.name; return *this; }

		const string &get_name() { return name; }
		int get_mysn() { return mysn; }

	private:
		static int sn;
		string name;
		int mysn;
};

int Employee::sn = 0;

void f(Employee &s)
{
	cout << s.get_name() << ":" << s.get_mysn() << endl;
}

int main(int argc,char **argv)
{
	Employee a("赵"), b = a , c;
	c = b;
	f(a);f(b);f(c);

	return 0;
}


