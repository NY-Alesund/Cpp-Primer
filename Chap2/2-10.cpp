/*************************************************************************
	> File Name: 2-10.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年03月28日 星期三 14时54分01秒
 ************************************************************************/

#include<iostream>
using namespace std;

std::string global_str;
int global_int = 1;

int main()
{
	int local_int = 2;
	std::string local_str;
	std::cout << global_str << global_int << " " << local_int << local_str;

	return 0;
}
