/*************************************************************************
	> File Name: 11-4.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月15日 星期日 22时05分19秒
 ************************************************************************/
/* 改写单词计数程序，忽略大小写和标点 */
#include<iostream>
#include<fstream>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

string &trans(string &s)
{
	for (int p = 0; p < s.size(); p++ ) {
		if (s[p] >= 'A' && s[p] <= 'Z')
			s[p] -= ('A' - 'a');				//大写变小写
		else if (s[p] == ',' || s[p] == '.')	
			s.erase(p,1);						//擦除标点
	}
	return s;
}

int main(int argc,char *argv[])
{
	ifstream in(argv[1]);
	if (!in) {
		cout << "打开输入文件失败!" << endl;
		exit(1);
	}

	map<string,size_t> word_count;			//从string到size_t的映射
	string	word;
	while (in >> word)
		++word_count[trans(word)];			//这个单词的出现次数加1

	for(const auto &w : word_count)			//对map中的每个元素打印结果
		cout << w.first << " 出现了 " << w.second << " 次 " << endl;

	return 0;
}
