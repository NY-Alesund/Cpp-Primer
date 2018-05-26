/*************************************************************************
	> File Name: push_back.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月01日 星期日 09时29分58秒
 ************************************************************************/
/* 使用成员函数push_back给对象尾端添加元素 ： 相当于入栈*/
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> v;
	for(int i = 0;i < 100;i++)
		v.push_back(i);
	for(auto &i : v)
		cout << i << endl;
	return 0;
}
