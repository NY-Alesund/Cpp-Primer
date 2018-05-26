/*************************************************************************
	> File Name: 10-1.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月12日 星期四 17时59分03秒
 ************************************************************************/

/* 用accumulate算法求vector<int>中的元素之和 */
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main(int argc,char *argv[])
{
	ifstream in(argv[1]);
	if (!in) {
		cout << "打开输入文件失败!" << endl;
		exit(1);
	}

	vector<int> vi;
	int val;
	while(in >> val)
		vi.push_back(val);

	cout << "序列中整数之和为" << accumulate(vi.begin(),vi.end(),0) << endl;

	return 0;
}
