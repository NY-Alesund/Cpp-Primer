/*************************************************************************
	> File Name: 10-1.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月12日 星期四 17时59分03秒
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
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

	cout << "请输入要搜索的整数:";
	cin >> val;

	cout << "序列中包含" << count(vi.begin(),vi.end(),val) << "个" << val << endl;   //count返回给定值在序列中出现的次数

	return 0;
}
