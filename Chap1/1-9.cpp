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
	int sum = 0, val = 55;

	while(val <= 100){
		sum += val;
		++val;
	}

	std::cout << "Sum of 55 to 100 inclusive is "
			  << sum << std::endl;
	return 0;

}
