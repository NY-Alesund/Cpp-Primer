/*************************************************************************
	> File Name: 4-7.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月04日 星期三 10时07分08秒
 ************************************************************************/
/* 检测溢出 */

#include<iostream>
using namespace std;

int main()
{
	int i = 2147483647;
	int j = -100000;
	int k = 2018*2018;
	cout << i + 1 << " " << j * 300000 << " " << k*2018;
	return 0;
}
