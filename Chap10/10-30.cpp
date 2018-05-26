/*************************************************************************
	> File Name: 10-30.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月13日 星期五 16时42分24秒
 ************************************************************************/

/* 使用流迭代器，sort和copy从标准输入读取一个整数序列，将其排序，并将其结果写到标准输出 */
#include<iostream>
#include<fstream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

int main(int argc,char *argv[])
{
	//创建流迭代器从标准输入读入整数
	istream_iterator<int> in_iter(cin);
	//尾后迭代器
	istream_iterator<int> eof;
	vector<int> vi;
	while(in_iter != eof)
		vi.push_back(*in_iter++);		//存入vector并递增迭代器

	sort(vi.begin(),vi.end());

	ostream_iterator<int> out_iter(cout," ");
	copy(vi.begin(),vi.end(),out_iter);

	return 0;
}

