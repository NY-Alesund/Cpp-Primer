/*************************************************************************
	> File Name: 11-12.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月16日 星期一 08时25分49秒
 ************************************************************************/

/* 读入string和int序列，将每个string和Int存入到一个pair中，pair保存到vector中 */
#include<iostream>
#include<fstream>
#include<utility>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(int argc,char *argv[])
{
	ifstream in(argv[1]);
	if (!in) {
		cout << "打开输入文件失败!" << endl;
		exit(1);
	}

	vector<pair<string,int>> data;		//pair的vector
	string s;
	int v;
	while (in >> s && in >> v)		
		//data.push_back(make_pair(s,v));
		//data.push_back(pair<string,int> (s,v));
		data.push_back({s,v});			//三种不同初始化都行
	for (const auto &d : data)			//打印单词行号
		cout << d.first << " " << d.second << endl;
	return 0;
}
