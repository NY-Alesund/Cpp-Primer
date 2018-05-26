/*************************************************************************
	> File Name: 6-11.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月04日 星期三 19时17分11秒
 ************************************************************************/

#include<iostream>
using namespace std;

void reset(int &i)
{
	i = 0;
}

int main()
{
	int num  = 10;
	cout << "充值前:num = " << num << endl;
	reset(num);
	cout << "重置后:num = " << num << endl;
	return 0;
}
