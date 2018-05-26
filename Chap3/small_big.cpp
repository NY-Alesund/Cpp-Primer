/*************************************************************************
	> File Name: small_big.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月01日 星期日 09时21分21秒
 ************************************************************************/

/* 将string对象中的小写转化为大写 */

#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int main()
{
	string s("Hello,world!~");
	for(auto &c : s)
		c = toupper(c);
	cout << s << endl;
	return 0;
}
