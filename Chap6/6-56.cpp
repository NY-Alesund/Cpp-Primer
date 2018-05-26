/*************************************************************************
	> File Name: 6-55.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月04日 星期三 21时14分36秒
 ************************************************************************/

/* 分别对两个int值执行加减乘除，在上一题创建的vector对象中保存指向这些函数的指针*/
#include<iostream>
#include<vector>

using namespace std;

//加法
int func1(int a, int b)
{
	return a+b;
}

//减法
int func2(int a, int b)
{
	return a-b;
}

//乘法
int func3(int a, int b)
{
	return a*b;
}

//除法
int func4(int a, int b)
{
	return a/b;
}

void Compute(int a,int b,int (*p)(int,int))
{
	cout << p(a,b) << endl;   //调用p指向的四则运算函数
}

int main()
{
	int i = 5,j = 10;
	decltype(func1) *p1 = func1,*p2 = func2, *p3 = func3, *p4 = func4;
	vector<decltype(func1)* > vF = {p1,p2,p3,p4};
	for(auto p : vF) //遍历vector对象中的每个元素，依次调用四则运算函数
	{
		Compute(i,j,p);   //p是指向四则运算函数的指针，
	}
	return 0;
}
