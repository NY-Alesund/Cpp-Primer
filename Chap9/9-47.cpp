/*************************************************************************
	> File Name: 9-47.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月10日 星期二 23时08分34秒
 ************************************************************************/

/* 首先查找数字字符，然后查找字母字符*/
#include<iostream>
#include<string>
using namespace std;

void find_char(string &s, const string &chars)
{
	cout << "在" << s << "中查找" << chars << "中字符" << endl;
	string::size_type pos = 0;
	while((pos = s.find_first_of(chars,pos)) != string::npos)			
		//在s中pos位置开始查找chars任何一个字符第一次出现的位置，返回指向字符出现的下标
	{
		//找到字符
		cout << "pos: " << pos << ",char: " << s[pos] << endl;
		pos++;			//移动到下一字符
	}
}

int main()
{
	string s = "ab2c3d7R4E6";
	cout << "查找所有数字" << endl;
	find_char(s,"0123456789");
	cout << endl << "查找所有字母" << endl;
	find_char(s,"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");

	return 0;
}
