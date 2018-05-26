/*************************************************************************
	> File Name: 8-1.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月08日 星期日 14时58分59秒
 ************************************************************************/

/* 
 * 编写一个函数，接受一个istream&参数，返回值类型是istream&
 * 本程序从标准输入读取数据，直至遇到文件结束标识时停止。将读取的数据打印在标准输出上 
 * */
#include<iostream>
#include<stdexcept>
using namespace std;

istream & f(istream & in)
{
	int v;
	while(in >> v, !in.eof()) {
		if(in.bad())
			throw runtime_error("IO流错误");
		if(in.fail()) {
			cerr << "数据错误，请重试:" << endl;
			in.clear();
			in.ignore(100,'\n');
			continue;
		}
		cout << v << endl;
	}
	in.clear();
	return in;
}

int main()
{
	cout << "请输入一些整数，以Ctrl+D结束" << endl;
	f(cin);
	return 0;
}
