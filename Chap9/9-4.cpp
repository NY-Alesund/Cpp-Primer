/*************************************************************************
	> File Name: 9-4.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月10日 星期二 10时37分58秒
 ************************************************************************/

/* 接受一对指向vector<int>的迭代器和一个int值
 * 在两个迭代器指定的范围中查找给定的值
 * 返回一个布尔值指出是否找到*/

#include<iostream>
#include<vector>
using namespace std;

bool search_vec(vector<int>::iterator beg, vector<int>::iterator end, int val)	//一对指向vector<int>的迭代器和一个int值
{
	for(;beg != end; beg++)	//遍历范围
		if (*beg == val)	//检查是否与给定值相等
			return true;
	return false;
}

int main()
{
	vector<int> ilist = {1,2,3,4,5,6,7};

	cout << search_vec(ilist.begin(), ilist.end(), 3) - *ilist.begin() << endl;
	cout << search_vec(ilist.begin(), ilist.end(), 8) - *ilist.begin() << endl;

	return 0;
}

