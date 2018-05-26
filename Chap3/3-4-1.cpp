/*************************************************************************
	> File Name: 3-4.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年03月31日 星期六 18时33分22秒
 ************************************************************************/
//输出较大的字符串

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s1,s2;
	cin >> s1 >> s2;
	if(s1 != s2)
	{
		if(s1 > s2)
			cout << s1 << endl;
		else
			cout << s2 << endl;
		return 0;
	}
	else
		cout << "相等" << endl;

	return 0;
}
