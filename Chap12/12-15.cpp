/*************************************************************************
	> File Name: 12-15.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月17日 星期二 17时35分57秒
 ************************************************************************/

/* 用lambda代替end_connection函数 */
#include<iostream>
#include<memory>
using namespace std;

struct destination {};
struct connection {};

connection connect(destination *pd)
{
	cout << "打开连接" << endl;
	return connection();
}

void disconnect(connection c)
{
	cout << "关闭连接" << endl;
}

//未使用shared_ptr的版本
void f(destination &d)
{
	cout << "直接管理connect" << endl;
	connection c = connect(&d);
	//忘记调用disconnection关闭连接
	cout << endl;
}

//使用shared_ptr的版本
void f1(destination &d)
{
	cout << "用shared_ptr管理connect" << endl;
	connection c = connect(&d);

	shared_ptr<connection> p(&c, [](connection *p) { disconnect(*p); });	//lambda表达式为 [](connection *p) { disconnect(*p); }  
	//忘记调用disconnect关闭连接
	
	cout << endl;
}

int main(int argc,char *argv[])
{
	destination d;
	f(d);
	f1(d);

	return 0;
}

