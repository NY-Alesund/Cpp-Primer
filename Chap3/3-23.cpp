/*************************************************************************
	> File Name: 3-23.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月01日 星期日 13时28分38秒
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> vInt(10);
	for(auto &c : vInt)
		cin >> c;
	auto beg = vInt.begin();
	auto end = vInt.end();
	
	for(auto it = beg; it != end; it++)
	{
		*it *= 2;
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}

