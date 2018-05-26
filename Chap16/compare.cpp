/*************************************************************************
	> File Name: compare.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月22日 星期日 19时52分43秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

template <typename T>
int compare(const T &v1, const T &v2)
{
	if (v1 < v2) 
		cout << v1 << "小于" << v2 << endl;  
	if (v2 < v1)
		cout << v2 << "小于" << v1 << endl;
	return 0;
}

int main()
{
	string s1{"Lebron James"};
	string s2{"lebron james"};
	vector<int> vec1{1,2,3};
	vector<int> vec2{4,5,6};
	compare(s1,s2);
	return 0;
}
