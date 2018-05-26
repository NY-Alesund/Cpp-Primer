/*************************************************************************
	> File Name: small_big2.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月01日 星期日 10时09分19秒
 ************************************************************************/

/* 使用迭代器：将字符转化为大写形式 */

#include<iostream>
#include<vector>
#include<cctype>
using namespace std;

int main()
{
	string s;
	cin >> s;
	for(auto it = s.begin(); it != s.end() && !isspace(*it) ; ++it)   //直到处理完全部字符或者遇到空白
		*it = toupper(*it);
	cout << s << endl;
	return 0;
}
