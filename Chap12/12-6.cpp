/*************************************************************************
	> File Name: 12-6.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月17日 星期二 16时30分50秒
 ************************************************************************/

/* 
 * 编写函数返回动态分配的int的vector,将C此vector传递给另一个函数,
 * 这个函数读取标准输入,将读入的值保存到vector元素中。在将vector传递给另一个函数
 * */

#include<iostream>
#include<memory>
#include<vector>
#include<string>
using namespace std;

vector<int> *new_vector(void)
{
	return new (nothrow) vector<int>;		//nothrow代表如果分配失败，不抛出异常,返回一个空指针
}

void read_ints(vector<int> *pv)
{
	int v;
	while(cin >> v)
		pv->push_back(v);
}

void print_ints(vector<int> *pv)
{
	for (const auto &v : *pv)
		cout << v << " ";
	cout << endl;
}

int main(int argc,char *argv[])
{
	vector<int> *pv = new_vector();
	if (!pv) {
		cout << "内存不足!" << endl;
		return -1;
	}

	read_ints(pv);
	print_ints(pv);

	delete pv;
	pv = nullptr;
	
	return 0; 
}


