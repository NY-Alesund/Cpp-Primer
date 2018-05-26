/*************************************************************************
	> File Name: 6-25.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月04日 星期三 20时16分38秒
 ************************************************************************/
/* 编写函数，令其接受两个实参，把实参连接成一个string对象输出出来*/

#include<iostream>
#include<string>
using namespace std;


int main(int argc, char **argv)
{
	string str;
	for(int i = 0; i != argc; ++i)
		str += argv[i];
	cout << str << endl;
	return 0;
}

