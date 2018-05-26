/*************************************************************************
	> File Name: 10-9.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月12日 星期四 21时19分20秒
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

/* 实现自己的elimDups*/
inline void output_words(vector<string> &words)
{
	for (auto iter = words.begin(); iter != words.end(); iter++)
		cout << *iter << " ";
	cout << endl;
}

void elimDups(vector<string> &words)
{
	output_words(words);

	sort(words.begin(),words.end());		//按字典排序
	output_words(words);

	auto end_unique = unique(words.begin(),words.end());		//把重复元素放到末尾
	output_words(words);
	
	words.erase(end_unique,words.end());			//删除重复元素
	output_words(words);
}

int main(int argc,char *argv[])
{
	ifstream in(argv[1]);
	if (!in) {
		cout << "打开输入文件失败!" << endl;
		exit(1);
	}

	vector<string> words;
	string word;
	while (in >> word)
		words.push_back(word);

	elimDups(words);
	return 0;
}
