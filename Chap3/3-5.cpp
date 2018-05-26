/*************************************************************************
	> File Name: 3-5.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月01日 星期日 11时23分21秒
 ************************************************************************/
/* 将输入的字符串用空格隔开连接到一起*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
	char flag;

	string s,result;
	cout << "请输入第一个字符串: " <<endl;
	while(cin >> s)
	{
		result = result + " " +s;
		cout << "是否继续(y or n)? " << endl;
		cin >> flag ;
		if(flag == 'y' || flag == 'Y')
			cout << "请输入下一个字符串: " << endl;
		else
			break;
	}
	cout << result <<endl;
	return 0;
}
