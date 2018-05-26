/*************************************************************************
	> File Name: 11-38-a.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月16日 星期一 10时42分15秒
 ************************************************************************/

/* 用unordered_map重写单词计数程序 */
#include<iostream>
#include<fstream>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;

int main(int argc,char *argv[])
{
	ifstream in(argv[1]);
	if(!in) {
		cout << "打开输入文件失败!" << endl;
		exit(1);
	}

	unordered_map<string,size_t> word_count;		//从string到count的映射
	string word;
	while (in >> word)
		++word_count[word];

	for (const auto w : word_count)	
		cout << w.first << "出现了" << w.second << "次" << endl;

	return 0;
}
