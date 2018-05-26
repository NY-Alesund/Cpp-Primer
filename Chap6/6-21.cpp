/*************************************************************************
	> File Name: 6-21.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月04日 星期三 20时02分11秒
 ************************************************************************/

/* 比较第一个实参的值和第二个实参指针所指的值*/
#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;

int myCompare(const int val,const int *p)
{
	return (val > *p) ? val : *p;
}

int main()
{
	srand((unsigned) time(NULL));
	int a[10];
	for(auto &i : a)
		i = rand() % 100;
	cout << "请输入一个数:";
	int j;
	cin >> j;
	cout << "您输入的数和数组首元素中较大的是:" << myCompare(j,a) << endl;
	cout << "数组的全部元素是:" << endl;
	for(auto i : a)
		cout << i << " ";
	cout << endl;
	return 0;
}
