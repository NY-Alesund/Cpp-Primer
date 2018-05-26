/*************************************************************************
	> File Name: 11-16.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月16日 星期一 08时54分00秒
 ************************************************************************/

#include<iostream>
#include<map>
using namespace std;

int main()
{
	map<int,int> m(1,1);
	auto it = m.begin();
	it->first  = 10;		//错误，因为first成员保存的是const关键字
	it->second = 11;
	cout << it->first << " " << it->second << endl;
	return 0;
}
