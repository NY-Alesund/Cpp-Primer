/*************************************************************************
	> File Name: 3-31.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年03月31日 星期六 23时08分12秒
 ************************************************************************/

#include<iostream>
#include<cstddef>
using namespace std;

int main()
{
	constexpr size_t array_size = 10;
	int ia[array_size];

	for(size_t ix = 0 ; ix<10 ; ix++)
	{	
		ia[ix] = ix;
		cout << ia[ix] << " " << endl;
	}
	return 0;
}

