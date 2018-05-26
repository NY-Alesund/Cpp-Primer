/*************************************************************************
	> File Name: 5-19.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月04日 星期三 16时01分02秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int main()
{
	do{
		string s1,s2;
		cout << "请输入两个字符串" << endl;
		cin >> s1 >> s2;
		//getline(cin,s1);
		//getline(cin,s2);
		if(s1.size() > s2.size())
			cout << "长度较小的字符串是:" << s2 << endl;
		else if(s1.size() < s2.size())
			cout << "长度较小的字符串是:" << s1 << endl;
		else
			cout << "两个字符串等长" << endl;
	}
	while(cin);

	return 0;

}
