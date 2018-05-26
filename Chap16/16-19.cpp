/*************************************************************************
	> File Name: 16-19.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月22日 星期日 21时09分21秒
 ************************************************************************/

/* 编写函数，接受一个容器的引用，打印容器中的元素 
 * 使用容器的size_type和size成员来控制打印元素的循环 */
#include<iostream>
#include<vector>
#include<string>
using namespace std;

template <typename T>
void print(T &v)
{
	for (typename T::size_type i = 0; i != v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}

int main()
{
	string s = "Hello!";
	print(s);

	vector<int> vi = {0,2,4,6,8};
	print(vi);

	return 0;
}

