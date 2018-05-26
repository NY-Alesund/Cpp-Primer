/*************************************************************************
	> File Name: 9-20.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月10日 星期二 13时01分30秒
 ************************************************************************/

/* 编写程序，从一个list<int>拷贝元素到两个deque中。
 * 值为偶数的所有元素都拷贝到一个deque中，奇数值元素都拷贝到另一个deque中 */

#include<iostream>
#include<list>
#include<deque>
using namespace std;

int main()
{
	list<int> ilist = {0,1,2,3,4,5,6,7,8,9};
	auto lb = ilist.begin();
	auto le = ilist.end();

	deque<int> ideque1;	//存放奇数
	deque<int> ideque2;	//存放偶数
	for(;lb != le; ++lb)
	{
		if(*lb % 2)
			ideque1.push_back(*lb);
		else
			ideque2.push_back(*lb);
	}
	
	cout << "奇数有: ";
	for (auto iter1 = ideque1.begin(); iter1 != ideque1.end() ; ++iter1)
		cout << *iter1 << " ";
	cout << "偶数有: ";
	for (auto iter2 = ideque2.begin(); iter2 != ideque2.end() ; ++iter2)
		cout << *iter2 << " ";
	return 0;
}
