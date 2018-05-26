/*************************************************************************
	> File Name: sum10.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年03月27日 星期二 15时41分59秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main()
{
	int sum = 0, val = 1;

	while(val <= 10){
		sum += val;
		++val;
	}

	std::cout << "Sum of 1 to 10 inclusive is "
			  << sum << std::endl;
	return 0;

}
