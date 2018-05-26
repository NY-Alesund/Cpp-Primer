/*************************************************************************
	> File Name: 10-21.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月13日 星期五 14时25分19秒
 ************************************************************************/

/* 要改变捕获的变量的值，需要在参数列表之后，函数体之前加入mutable关键字 */
#include<iostream>
#include<algorithm>
using namespace std;

void mutable_lambda(void)
{
	int i = 5;
	auto f = [i] () mutable -> bool{ if(i>0) { i--;return false;} else 
		return true; };

	for (int j = 0; j < 6; j++)
		cout << f() << " ";
	cout << endl;
}

int main(int argc,char *argv[])
{
	mutable_lambda();
	return 0;
}

