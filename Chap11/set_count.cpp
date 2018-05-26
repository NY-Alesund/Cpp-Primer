/*************************************************************************
	> File Name: set_count.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月14日 星期六 16时37分09秒
 ************************************************************************/

/* 使用set统计除忽略单词外的其它单词出现次数*/
#include<iostream>
#include<string>
#include<set>
#include<map>
using namespace std;

int main()
{
	map<string,size_t> word_count;		// string到size_t的空map
	set<string> exclude = {"The","But","And","Or","An","A","the","but","and","or","an","a"};		//除开这些单词

	string word;
	while (cin >> word)
		//只统计不在exclude的单词
		if (exclude.find(word) == exclude.end())
			++word_count[word];		//获取并递增word的计数器
	for (const auto &w : word_count)			//对统计的每个元素打印出
		cout << w.first << " 出现了 " << w.second << " 次 " << endl;
	return 0;
}
