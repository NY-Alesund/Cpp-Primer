/*************************************************************************
	> File Name: 3-40.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月01日 星期日 15时40分33秒
 ************************************************************************/

/* 定义两个字符数组并初始化，再定义一个字符数组存放前两个数组链接后的结果。
 * 使用strcpy和strcat把前两个数组拷贝到第三个数组*/

#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	string str1;
	getline(cin,str1);

	string str2;
	getline(cin,str2);

	string result = str1 +str2;

	cout << "第一个字符串是: " << str1 << endl;
	cout << "第二个字符串是: " << str2 << endl;
	cout << "拼接后的字符串: " << result << endl;
	return 0;
}
