/*************************************************************************
	> File Name: 6-27.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月04日 星期三 20时24分07秒
 ************************************************************************/

#include<iostream>
using namespace std;

int iCount(initializer_list<int> i1)
{
	int count = 0;
	//遍历i1的每一个元素
	for(auto val : i1)
		count += val;
	return count;
}

int main()
{
	cout << "1,6,9的和是:" << iCount({1,6,9}) << endl;
	cout << "4,5,9,18的和是:" << iCount({4,5,9,18}) << endl;
	return 0;
}
