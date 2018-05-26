/*************************************************************************
	> File Name: 5-21.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月04日 星期三 16时42分21秒
 ************************************************************************/

/*找到第一次连续出现的以大写字母开头的单词*/
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string currString,preString;
	bool b1 = true;
	cout << "请输入一组字符串:" << endl;
	while(cin >> currString)
	{
		if(!isupper(currString[0]))  //是否是大写开头
			continue;				//如果不是则直接再读取
		if(currString == preString)
		{
			b1 = false;
			cout << "连续出现的字符串是:" << currString << endl;
			break;
		}
		preString = currString;
	}
	if(b1)
		cout << "没有连续出现的字符串~" << endl;
	return 0;
}
