/*************************************************************************
	> File Name: 5-10.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月04日 星期三 12时46分07秒
 ************************************************************************/
/* 统计输入的元音字母有多少*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
	int vowelCnt = 0;
	char ch ;
	cout << "请输入一段文本：" << endl;

	while(cin >> ch)
	{
		switch(ch)
		{
			case 'a':
			case 'A':
				++vowelCnt;
				break;
			case 'e':
			case 'E':
				++vowelCnt;
				break;
			case 'i':
			case 'I':
				++vowelCnt;
				break;
			case 'o':
			case 'O':
				++vowelCnt;
				break;
			case 'u':
			case 'U':
				++vowelCnt;
				break;
		}
	}
	cout << "元音字母有" << vowelCnt << "个！" << endl;
	return 0;
}
