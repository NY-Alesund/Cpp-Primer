/*************************************************************************
	> File Name: 8-9.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月08日 星期日 15时58分12秒
 ************************************************************************/

/* 为8-1练习打印一个istringstream对象的内容 */

#include<iostream>
#include<sstream>
#include<string>
#include<stdexcept>
using namespace std;

istream & f(istream & in)
{
	string v;
	while (in >> v,!in.eof()) {  //直到遇到文件结束符才停止读取
		if(in.bad())
			throw runtime_error("IO流错误");
		if(in.fail()) {
			cerr << "数据错误，请重试：" << endl;
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
	ostringstream msg;
	msg << "C++ Primer 第五版" << endl;
	istringstream in(msg.str());  //msg.srt()返回msg保存的string的拷贝
	f(in);
	return 0;
}
