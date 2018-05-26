/*************************************************************************
	> File Name: 3-25.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月01日 星期日 13时58分47秒
 ************************************************************************/

//用迭代器划分分数段

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<unsigned> vUS(11);     //有11个分段
	auto it = vUS.begin();
	int cnt=0;
	int iVal;
	cout << "请输入一组成绩(0~100)：" << endl;
	while(cin >> iVal)
	{	if(iVal < 101)
		++ *(it + iVal/10);
		cnt++;
	}

	cout << "老哥你输入了" <<  cnt << "个成绩" << endl;
	cout << "各分段成绩的人数分布是:" << endl;
	for (auto it = vUS.begin(); it != vUS.end() ; it++)
		cout << *it << " ";
	cout << endl;
	return 0;
}
