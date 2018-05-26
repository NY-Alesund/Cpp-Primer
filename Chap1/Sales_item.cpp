/*************************************************************************
	> File Name: Sales_item.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年03月27日 星期二 16时36分52秒
 ************************************************************************/

#include<iostream>
#include "Sales_item.h"
using namespace std;

int main()
{
	Sales_item book;
	//读入ISBN号，售出的册数以及销售价格
	std::cin >> book;

	//输出ISBN号，售出的册数，总销售额和平均价格
	std::cout << book << std::endl;
	return 0;
}
