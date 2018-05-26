/*************************************************************************
	> File Name: 10to12.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年03月31日 星期六 19时24分03秒
 ************************************************************************/
/* 把0-15之间的10进制转化为16进制 */

#include<iostream>
#include<string>
using namespace std;

int main()
{
	const string hexdigits = "0123456789ABCDEF";
	cout << "Enter a series of numbers between 0 and 15"
		<< " separated by spaces, Hit ENTER when finished: "
		<< endl;
	string result;  //保存16进制字符串
	string::size_type n;   //保存从输入流读取的数
	while(cin >> n)
		if (n < hexdigits.size())   //忽略无效输入
			result += hexdigits[n];   //字符串和string对象相加
	cout << "Your hex number is: " << result << endl;
}

