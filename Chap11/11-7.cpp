/*************************************************************************
	> File Name: 11-7.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月15日 星期日 22时17分35秒
 ************************************************************************/
/* 定义一个map，关键字是家庭的姓，值是一个vector，保存家中孩子的名 */
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/* 添加一个家庭,vector<string>表示这个家庭的孩子名字列表 */
void add_family(map<string,vector<string>> &families, const string &family)		//family是要添加的家庭的姓
{
	if (families.find(family) == families.end())			//先检查这个家庭是否存在
		families[family] == vector<string> ();				//若不存在则添加
}

void add_child(map<string,vector<string>> &families, const string &family, const string &child)
{
	families[family].push_back(child);
}

int main(int argc,char *argv[])
{
	map<string,vector<string>> families;

	add_family(families,"张");
	add_child(families,"张","强");		//添加名为强的孩子
	add_child(families,"张","刚");		

	add_child(families,"王","五");
	add_family(families,"王");

	for (auto f : families) {
		cout << f.first << "家的孩子: ";
		for (auto c : f.second)
			cout << c << " ";
		cout << endl;
	}

	return 0;
}


