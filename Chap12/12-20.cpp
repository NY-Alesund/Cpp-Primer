/*************************************************************************
	> File Name: 12-20.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月17日 星期二 18时57分45秒
 ************************************************************************/

/* 逐行读入一个输入文件，将内容存入一个StrBlob中，用一个StrBlobPtr打印出StrBlob中的每个元素 */
#include<iostream>
#include<fstream>
#include "my_StrBlob.h"
using namespace std;

int main(int argc,char *argv[])
{
	ifstream in(argv[1]);
	if (!in) {
		cout << "无法打开输入文件!" << endl;
		return -1;
	}

	StrBlob b;
	string s;
	while(getline(in,s))
		b.push_back(s);

	for (auto it = b.begin(); neq(it,b.end()); it.incr())		//neq当两个参数不相等时返回true
		cout << it.deref() << endl;

	return 0;
}
	

