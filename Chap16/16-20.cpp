/*************************************************************************
	> File Name: 16-20.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月22日 星期日 21时15分58秒
 ************************************************************************/

/* 接受一个容器的引用，打印容器的元素
 * 使用begin和end返回的迭代器来控制循环 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

template <typename T>
void print(T &a)
{
	for (auto iter = a.begin(); iter != a.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
}

int main()
{
	string s = "Fan Kai lin!";
	vector<int> ivec = {5,2,0,1,3,1,4};

	print(s);
	print(ivec);

	return 0;
}
