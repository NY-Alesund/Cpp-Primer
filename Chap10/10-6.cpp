/*************************************************************************
	> File Name: 10-6.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月12日 星期四 18时37分22秒
 ************************************************************************/

/* 使用fill_n将一个序列中的int值都设置为0 */
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc,char *argv[])
{
	ifstream in(argv[1]);
	if (!in) {
		cout << "打开输入文件失败" << endl;
		exit(1);
	}

	vector<int> vi;
	int val;
	while(in >> val) {
		vi.push_back(val);
		cout << val << " ";
	}
	cout << endl;

	fill_n(vi.begin(),vi.size(),0);
	for(auto iter = vi.begin(); iter != vi.end(); iter++)
		cout << *iter << " ";

	return 0;

}
