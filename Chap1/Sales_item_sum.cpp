/*************************************************************************
	> File Name: Sales_item_sum.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年03月27日 星期二 17时39分27秒
 ************************************************************************/
/* 将两个Sales_item类类型对象相加 */

#include<iostream>
#include "Sales_item.h"
using namespace std;

int main()
{
	Sales_item	item1,item2;
	std::cin >> item1 >> item2;
	
	/*检查ISBN是否相同，是否为同一种书*/
	if(item1.isbn() == item2.isbn()){
		std::cout << item1 + item2 << std::endl;
		return 0;
	}
	else{
		std::cerr << "Data must refer to same ISBN"
			<< std::endl;
		return -1;
	}
}
