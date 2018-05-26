/*************************************************************************
	> File Name: 8-10.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月08日 星期日 16时06分54秒
 ************************************************************************/

/* 编写程序，将来自一个文件中的行保存在一个vector<string>中
 * 然后使用一个istringstream从vector读取数据元素，每次读一个单词 */

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	ifstream in("data");		//打开文件
	if (!in) {
		cerr << "无法打开输入文件" << endl;
		return -1;
	}

	string line;
	vector<string> words;
	while(getline(in,line)) {		//从文件中读取一行
		words.push_back(line);		//添加到vector中
	}

	in.close();				//输入完毕，关闭文件

	vector<string>::const_iterator it = words.begin();	//迭代器
	while(it != words.end()) {							//遍历vector
		istringstream line_str(*it);	//将string对象*it拷贝到line_str中
		string word;
		while (line_str >> word)		//通过istringstream从vector中读取数据
			cout << word << " ";
		cout << endl;
		++it;
	}
	return 0;
}
