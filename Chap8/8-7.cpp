/*************************************************************************
	> File Name: 8-7.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月08日 星期日 15时46分35秒
 ************************************************************************/
/*
 * 重写书店程序，从一个文件data中读取交易记录
 * 将结果保存到另一个文件save中
 * */

#include<iostream>
#include<fstream>
#include "Sales_data.h"
using namespace std;

int main(int argc,char *argv[])
{
	if(argc != 3) {
		cerr << "请给出输入、输出文件名" << endl;
		return -1;
	}
	ifstream in (argv[1]);
	if (!in) {
		cerr << "无法打开输入文件" << endl;
		return -1;
	}

	ofstream out(argv[2],ofstream::app);  //app表示把结果追加到给定文件末尾
	if (!out) {
		cerr << "无法打开输出文件" << endl;
		return -1;
	}

	Sales_data total;
	if(read(in,total)) {
		Sales_data trans;
		while(read(in,trans)){
			if(total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				print(out,total) << endl;
				total = trans;
			}
		}
		print(out,total) << endl;
	} else {
		cerr << "没有数据" << endl;
	}
	return 0;
}
