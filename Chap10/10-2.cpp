/*************************************************************************
	> File Name: 10-1.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月12日 星期四 17时59分03秒
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<string>
#include<list>
#include<algorithm>
using namespace std;

int main(int argc,char *argv[])
{
	ifstream in(argv[1]);
	if (!in) {
		cout << "打开输入文件失败!" << endl;
		exit(1);
	}

	list<string> ls;
	string word;
	while(in >> word)
		ls.push_back(word);

	cout << "请输入要搜索的字符串:";
	cin >> word;

	cout << "序列中包含" << count(ls.begin(),ls.end(),word) << "个" << word << endl;   //count返回给定值在序列中出现的次数

	return 0;
}
