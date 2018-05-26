/*************************************************************************
	> File Name: word_count.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月14日 星期六 16时29分49秒
 ************************************************************************/

/* 统计每个单词在输入中出现的次数 */
#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
	map<string,size_t> word_count;		//从string到size_t的空map
	string word;
	while(cin >> word)
		++word_count[word];				//提取word的计数器并将其加1
	for(const auto &w : word_count)		//对map中的每个元素打印结果
		cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;
	/*          first对应于map的关键字，即单词；second对应于值,即出现次数									*/
	return 0;
}
