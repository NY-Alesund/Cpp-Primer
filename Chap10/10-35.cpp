/*************************************************************************
	> File Name: 10-35.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月13日 星期五 22时19分04秒
 ************************************************************************/

/* 使用逆序迭代器 */
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc,char *argv[])
{
	if (argc != 2) {
		cout << "用法:exercise.exe in_file" << endl;
		return -1;
	}

	ifstream in(argv[1]);
	if(!in) {
		cout << "打开输入文件失败!" << endl;
		exit(1);
	}

	vector<int> vi;
	int v;
	while(in >> v)	//从文件中读取整数
		vi.push_back(v);

	for(auto r_iter = vi.crbegin(); r_iter != vi.crend(); ++r_iter)		//r表示逆序
		cout << *r_iter << " ";
	cout << endl;

	return 0;
}

