/*************************************************************************
	> File Name: 4-10.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月04日 星期三 10时13分26秒
 ************************************************************************/

/* 从标准输入中读取数据，若输入为42则退出*/
#include<iostream>
using namespace std;

int main()
{
	int num;
	while(cin >> num && num != 42);
	
	return 0;
}
