/*************************************************************************
	> File Name: 12-23.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月17日 星期二 19时09分18秒
 ************************************************************************/
/* 连接两个字符串字面常量,将结果保存到动态分配的char数组中。
 * 重写这个程序,连接两个标准库string对象				*/
#include<iostream>
#include<cstring>
using namespace std;

int main(int argc,char *argv[])
{
	const char *c1 = "Hello ";
	const char *c2 = "World";

	//字符串所需空间等于字符数+1
	char *r = new char[strlen(c1) + strlen(c2) + 1];
	strcpy(r,c1);		//拷贝第一个字符串常量
	strcat(r,c2);		//连接第二个字符串常量
	cout << r << endl;

	string s1 = "hello ";
	string s2 = "world";
	strcpy(r,(s1+s2).c_str());		//c.str()获取连接结果的内存地址（临时对象）,拷贝连接结果
	cout << r << endl;

	//释放动态数组
	delete [] r;
	
	return 0;
}
