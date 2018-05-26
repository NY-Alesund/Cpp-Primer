/*************************************************************************
	> File Name: 8-4.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月08日 星期日 15时11分27秒
 ************************************************************************/

/* 
 * 编写函数，以读模式打开一个文件，将其内容读入到一个string的vector中
 * 将每一行作为一个独立的元素存于vector中
 * */

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	ifstream in("data");			//打开data文件
	if (!in) {
		cerr << "无法打开输入文件" << endl;
		return -1;
	}

	string line;
	vector<string> words;
	while (getline(in,line)) {		//从文件中读取一行
		words.push_back(line);		//添加到vector中
	}

	in.close();			//输入完毕，关闭文件

	vector<string>::const_iterator it = words.begin();		//迭代器
	while(it != words.end()) {		//遍历vector
		cout << *it << endl;		//输出vector中的元素
		++it;
	}
	return 0;
}
