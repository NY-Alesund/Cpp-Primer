/*************************************************************************
	> File Name: 3-10.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年03月31日 星期六 19时33分25秒
 ************************************************************************/
/* 输入一个字符串，去除掉标点符号后输出 */

#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int main()
{
	string s,result;
	//cin >> s;
	getline(cin,s);
	
	for(auto &c : s)
		if(ispunct(c));
		else
		{
			result += c;
		}
	cout << "The result without punct is : " << result << endl;
	return 0;
}
