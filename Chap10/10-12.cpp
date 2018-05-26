/*************************************************************************
	> File Name: 10-12.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月12日 星期四 21时42分39秒
 ************************************************************************/

/* 编写名为compareIsbn函数，比较两个Sales_data对象的isbn()成员。
 * 使用这个函数排序一个保存Sales_data对象的vector			*/

#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include "Sales_data.h"
using namespace std;

inline bool compareIsbn(const Sales_data &lhs,const Sales_data &rhs)
{
	return lhs.isbn() < rhs.isbn();
}

int main(int argc,char *argv[])
{
	ifstream in(argv[1]);
	if (!in) {
		cout << "打开输入文件失败!" << endl;
		exit(1);
	}

	vector<Sales_data> sds;
	Sales_data sd;
	while(read(in,sd))
		sds.push_back(sd);

	sort(sds.begin(),sds.end(),compareIsbn);

	for (const auto &s : sds) {
		print(cout,s);
		cout << endl;
	}

	return 0;
}
