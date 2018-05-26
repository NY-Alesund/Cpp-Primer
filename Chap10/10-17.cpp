/*************************************************************************
	> File Name: 10-17.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月12日 星期四 22时53分57秒
 ************************************************************************/
/* 对sort的调用中，使用lambda来代替函数compareIsbn */
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include "Sales_data.h"
using namespace std;

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

	sort(sds.begin(),sds.end(),[](const Sales_data &lhs, const Sales_data &rhs) {return lhs.isbn() < rhs.isbn();});

	for(const auto &s : sds) {
		print(cout,s);
		cout << endl;
	}

	return 0;
}

