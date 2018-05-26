/*************************************************************************
	> File Name: 11-3.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月15日 星期日 21时58分27秒
 ************************************************************************/
/* 单词计数程序 */
#include<iostream>
#include<fstream>
#include<map>
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

	map<string,size_t> word_count;		//string到count的映射
	string word;
	while (in >> word)
		++word_count[word];			//这个单词出现次数加1

	for (const auto &w : word_count)	//对map中每个元素打印结果
		cout << w.first << " 出现了 " << w.second << " 次 "  << endl;

	return 0;
}


