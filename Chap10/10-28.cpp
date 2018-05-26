/*************************************************************************
	> File Name: 10-28.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月13日 星期五 16时27分28秒
 ************************************************************************/

/* 理解3种插入迭代器的差异 */

#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

int main(int argc,char *argv[])
{
	vector<int> vi = {1,2,3,4,5,6,7,8,9};
	list<int> li1,li2,li3;

	unique_copy(vi.begin(),vi.end(),inserter(li1,li1.begin()));
	for(auto v : li1)
		cout << v << " ";
	cout << endl;

	unique_copy(vi.begin(),vi.end(),back_inserter(li2));
	for(auto v : li2)
		cout << v << " ";
	cout << endl;

	unique_copy(vi.begin(),vi.end(),back_inserter(li3));
	for(auto v : li3)
		cout << v << " ";
	cout << endl;

	return 0;
}

