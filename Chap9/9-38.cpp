/*************************************************************************
	> File Name: 9-38.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月10日 星期二 22时14分56秒
 ************************************************************************/
/* 探究标准库中vector是如何增长的 */
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> vi;
	int s,c;

	for(s = vi.size(),c = vi.capacity(); s<=c; s++)
		vi.push_back(1);
	cout << "空间:" << vi.capacity() << " 元素数:" << vi.size() << endl;

	for(s = vi.size(),c = vi.capacity(); s<=c; s++)
		vi.push_back(1);
	cout << "空间:" << vi.capacity() << " 元素数:" << vi.size() << endl;

	for(s = vi.size(),c = vi.capacity(); s<=c; s++)
		vi.push_back(1);
	cout << "空间:" << vi.capacity() << " 元素数:" << vi.size() << endl;

	for(s = vi.size(),c = vi.capacity(); s<= c; s++)
		vi.push_back(1);
	cout << "空间:" << vi.capacity() << " 元素数:" << vi.size() << endl;

	return 0;
}

