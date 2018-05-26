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

/* 重做12-6，使用shared_ptr */

#include<iostream>
#include<memory>
#include<vector>
#include<string>
using namespace std;

vector<int> *new_vector(void)
{
	return new (nothrow) vector<int>;			
}

void read_ints(shared_ptr<vector<int>> spv)
{
	int v;
	while(cin >> v)
		spv->push_back(v);
}

void print_ints(shared_ptr<vector<int>> spv)
{
	for (const auto &v : *spv)
		cout << v << " ";
	cout << endl;
}

int main(int argc,char *argv[])
{
	//vector<int> *pv = new_vector();
	shared_ptr<vector<int>> spv(new_vector());

	read_ints(spv);
	print_ints(spv);

	return 0; 
}


