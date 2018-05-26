/*************************************************************************
	> File Name: 16-7.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月22日 星期日 20时38分08秒
 ************************************************************************/

/* 编写一个constexpr模板，返回给定数组的大小 */
#include<iostream>
#include<string>
using namespace std;

template <typename T, size_t N>
constexpr int arr_size(const T (&a)[N])
{
	return N;
}

template<typename T,size_t N>
void print(const T (&a)[N])
{
	for(int i = 0; i < arr_size(a); i++)
		cout << a[i] << " ";
	cout << endl;
}

int main()
{
	int a[6] = { 0,2,4,6,8,10 };
	string vs[3] = { "Hello","World","!"} ;

	print(a);
	print(vs);

	return 0;
}
