/*************************************************************************
	> File Name: 9-42.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月10日 星期二 22时25分33秒
 ************************************************************************/

/* 每次读取一个字符存入string中，而且知道最少需要读取100个字符*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

void input_string(string &s)
{
	s.reserve(100);
	char c;
	while(cin >> c)
		s.push_back(c);
}

int main()
{
	string s;
	input_string(s);
	cout << s << endl;

	return 0;
}

