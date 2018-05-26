/*************************************************************************
	> File Name: 10-14.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月12日 星期四 22时31分18秒
 ************************************************************************/

#include<iostream>

using namespace std;
int main(int argc, char *argv[])
{
	auto sum = [] (int a, int b) { return a+b;};

	cout << sum(1,1) << endl;

	return 0;
}

