/*************************************************************************
	> File Name: 11-14.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月16日 星期一 08时37分06秒
 ************************************************************************/

/* 编写孩子姓到名的map; 添加一个pair的vector,保存孩子的名字和生日 */
#include<iostream>
#include<map>
#include<utility>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

void add_family(map<string,vector<pair<string,string>>> &families, const string &family)
{
	families[family];
}

void add_child(map<string,vector<pair<string,string>>> &families, const string &family,
				const string &child, const string &birthday)
{
	families[family].push_back({child,birthday});
}

int main(int argc, char *argv[])
{
	map<string,vector<pair<string,string>>> families;

	add_family(families,"张");
	add_child(families,"张","强","1970-1-1");
	add_child(families,"张","刚","1980-1-1");
	add_child(families,"王","五","1990-1-1");
	add_family(families,"王");

	for (auto f : families) {
		cout << f.first << "家的孩子: ";
		for(auto c : f.second)
			cout << c.first << "生日是-" << c.second << " ";
		cout << endl;
	}
	return 0;
}

