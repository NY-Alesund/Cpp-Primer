/*************************************************************************
	> File Name: 9-15.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月10日 星期二 12时04分09秒
 ************************************************************************/
/* 编写程序，判断两个vector<int>是否相等 */
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> ivec  = {1,2,3,4,5,6,7};
	vector<int> ivec1 = {1,2,3,4,5,6,7};
	vector<int> ivec2 = {1,2,3,4,5};
	vector<int> ivec3 = {1,2,3,4,5,6,8};
	vector<int> ivec4 = {1,2,3,4,5,7,6};

	cout << (ivec == ivec1) << endl;
	cout << (ivec == ivec2) << endl;
	cout << (ivec == ivec3) << endl;
	cout << (ivec == ivec4) << endl;

	ivec1.push_back(8);		//vector每次需要分配新内存空间时将当前容量(capacity)翻倍。所以压入8后容量变为14
	ivec1.pop_back();		//删除尾元素。
	cout << ivec1.capacity() << " " << ivec1.size() << endl;
	cout << (ivec == ivec1) << endl;

	return 0;
}
