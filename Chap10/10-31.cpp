/*************************************************************************
	> File Name: 10-31.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月13日 星期五 21时26分50秒
 ************************************************************************/

/* 修改前一题的程序，使其只打印不重复的元素 */
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
	unique_copy(vi.begin(),vi.end(),out_iter);

	return 0;
}

