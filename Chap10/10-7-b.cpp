/*************************************************************************
	> File Name: 10-7-b.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月12日 星期四 21时14分23秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//使用back_inserter来让fill_n向vec中添加元素

int main(int argc,char *argv[])
{
	vector<int> vec;
	vec.reserve(10);
	fill_n(back_inserter(vec),10,0);

	for(auto iter = vec.begin(); iter != vec.end(); iter++)
		cout << *iter << " ";
	cout << endl;
}
