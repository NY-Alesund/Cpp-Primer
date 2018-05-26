/*************************************************************************
	> File Name: 10-15.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月12日 星期四 22时32分36秒
 ************************************************************************/

#include<iostream>

using namespace std;

void add(int a)
{
	auto sum = [a] (int b) { return a + b ;};

	cout << sum(1) << endl;
}

int main(int argc, char *argv[])
{
	add(1);
	add(2);

	return 0;
}
