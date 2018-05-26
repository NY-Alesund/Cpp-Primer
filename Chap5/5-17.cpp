/*************************************************************************
	> File Name: 5-17.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月04日 星期三 15时39分12秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	int i;
	string v1;
	string v2;
	getline(cin,v1);
	getline(cin,v2);
	
	auto it1 = v1.begin();   //定义v1的迭代器
	auto it2 = v2.begin();   //定义v2的迭代器

	while(it1 != v1.end() && it2!= v2.end())
	{
		if(*it1 == *it2)
		{
			it1++,it2++;
		}
		else
		{
			cout << "v1和v2之间不存在前缀关系" << endl;
			return -1;
		}
	}
	if(it1 == v1.end())
		cout << "v1是v2的前缀" << endl;
	if(it2 == v2.end())
		cout << "v2是v1的前缀" << endl;
	return 0;
}
