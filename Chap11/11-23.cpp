/*************************************************************************
	> File Name: 11-23.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月16日 星期一 09时51分33秒
 ************************************************************************/

/* 以孩子的姓为关键字，保存它们的名的vector,用multimap重写 */
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/* 因为使用multimap，关键字可重复，所以直接添加即可*/
void add_child(multimap<string,string> &families, const string &family, const string &child)
{
	families.insert({family,child});
}

int main(int argc,char *argv[])
{
	multimap<string,string> families;

	add_child(families,"张","强");
	add_child(families,"王","刚");
	add_child(families,"王","强");

	for (auto f : families)
		cout << f.first << "家的孩子: " << f.second << endl;
	return 0;
}


