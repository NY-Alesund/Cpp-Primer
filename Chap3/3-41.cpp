/*************************************************************************
	> File Name: 3-41.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月01日 星期日 15时57分24秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace std;

int main()
{
	const int sz =10;
	int a[sz];
	srand((unsigned)time(NULL));	//生成随机数种子
	cout << "数组的内容是: " << endl;

	for(auto &val : a)
	{
		val = rand()%100;
		cout << val <<" ";
	}
	cout << endl;

	//利用begin和end初始化vector对象
	vector<int> vInt(begin(a),end(a));
	cout << "Vector的内容是： " << endl;

	//利用范围for循环遍历vector的每个元素
	for(auto val : vInt)
	{
		cout << val << " ";
	}
	cout << endl;
	return 0;

}
