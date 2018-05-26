/*************************************************************************
	> File Name: 9-24.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月10日 星期二 16时46分51秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> iv;	
	
	cout << iv.at(0) << endl;
	cout << iv[0] << endl;
	cout << iv.front() << endl;
	cout << *(iv.begin()) << endl;

	return 0;
}
