/*************************************************************************
	> File Name: Person_call.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月08日 星期日 14时48分45秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct PersonInfo {
	string name;
	vector<string> phones;
};

int main()
{
	string line, word;			//分别保存来自输入的一行和单词
	vector<PersonInfo> people;	//保存来自输入的记录
	//逐行从输入读取数据，直至cin遇到文件尾或其它错误
	while(getline(cin,line)) {
		PersonInfo info;		//创建一个保存此记录数据的对象
		istringstream record(line);		//将记录绑定到刚读入的行；
		record >> info.name;		//读取名字
		while(record >> word)		//读取电话号码
			info.phones.push_back(word);	//保持它们
		people.push_back.(info);		//将此记录追加到people末尾。

	}
}

