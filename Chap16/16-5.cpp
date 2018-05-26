/*************************************************************************
	> File Name: 16-5.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月22日 星期日 20时09分17秒
 ************************************************************************/

/* 为print函数编写模板，它接受一个数组的引用 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

template <typename T>
void print(T &a)
{
	for ( auto elem : a)
		cout << elem << " ";
	cout << endl;
}

int main()
{
	vector<int> ivec = {0,2,4,6,8};
	string s = {"Hello World !"};
	print(ivec);
	print(s);
	return 0;
}
