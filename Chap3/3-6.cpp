/*************************************************************************
	> File Name: 3-6.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月01日 星期日 11时30分57秒
 ************************************************************************/

/* 将字符串内的所有字符用X替代 */
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
	getline(cin,s);
	for(auto &i : s)
		i = 'X';
	cout << s << endl;
	return 0;
}
