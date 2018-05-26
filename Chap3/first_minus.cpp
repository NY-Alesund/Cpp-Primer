/*************************************************************************
	> File Name: first_minus.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月01日 星期日 10时43分58秒
 ************************************************************************/
/* 找到数组的第一个负数并且输出 */

#include<iostream>
#include<iterator>
#include<vector>
using namespace std;

int main()
{	
	vector<int> ival;
	int i;
	while(cin >> i)
		ival.push_back(i);

	vector<int>::iterator beg = ival.begin();
	vector<int>::iterator end = ival.end() - 1;

	while(beg != end && *beg >= 0)
		beg++;
	cout << *beg << endl;
	return 0;
}
