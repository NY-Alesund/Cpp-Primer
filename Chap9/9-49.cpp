/*************************************************************************
	> File Name: 9-49.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月10日 星期二 23时20分53秒
 ************************************************************************/

/* 读入一个单词文件，输出最长的既不包含上出头部分，也不包含下出头部分的单词 */
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void find_longest_word(ifstream &in)
{
	string s,longest_word;
	int max_length = 0;

	while(in >> s)
	{
		if (s.find_first_of("bdfghjklpqty") != string::npos)
			continue;	//包含上出头或下出头字母
		cout << s << " ";
		if(max_length < s.size()) {			//新单词更长
			max_length = s.size();			//记录长度和单词
			longest_word = s;
		}
	}
	cout << endl << "最长字符串: " << longest_word << endl; 
}

int main(int argc, char *argv[])
{
	ifstream in(argv[1]);		//打开文件
	if (!in) {
		cerr << "无法打开输入文件" << endl;
		return -1;
	}

	find_longest_word(in);

	return 0;
}
