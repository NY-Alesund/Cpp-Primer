/*************************************************************************
	> File Name: 11-8-set.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月15日 星期日 22时57分46秒
 ************************************************************************/

/* 用set保存不重复单词 */
#include<iostream>
#include<string>
#include<set>
#include<fstream>
#include<algorithm>
using namespace std;

string &trans(string &s)
{
	for (int p = 0; p < s.size(); p++) {
		if(s[p] >= 'A' && s[p] <= 'Z')
			s[p] -= ('A' - 'a');
		else if (s[p] == ',' || s[p] == '.')
			s.erase(p,1);
	}
	return s;
}

int main(int argc, char *argv[])
{
	ifstream in(argv[1]);
	if(!in) {
		cout << "打开输入文件失败！" << endl;
		exit(1);
	}

	set<string> unique_word;		//不重复的单词
	string word;
	while (in >> word) {
		trans(word);
		unique_word.insert(word);	//添加不重复单词
	}

	for (const auto &w : unique_word)
		cout << w << " ";
	cout << endl;

	return 0;
}
