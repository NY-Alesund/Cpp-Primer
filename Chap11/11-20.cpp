/*************************************************************************
	> File Name: 11-20.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月16日 星期一 09时02分10秒
 ************************************************************************/

/* 重写单词计数程序,使用insert代替下标操作 */
#include<iostream>
#include<fstream>
#include<string>
#include<map>
//#include<iterator>
#include<algorithm>
using namespace std;

int main(int argc,char *argv[])
{
	ifstream in(argv[1]);
	if(!in) {
		cout << "打开输入文件失败!" << endl;
		exit(1);
	}

	map<string,size_t> word_count;		//从string到count的映射
	string word;
	while (in >> word) {
		auto ret = word_count.insert({word,1});	//插入单词，次数为1
		if (!ret.second)				//插入的单词已存在
			++ret.first->second;		//计数加1
	}

	for (const auto &w : word_count)
		cout << w.first << " 出现了 " << w.second << " 次! " << endl;
	return 0;
}

