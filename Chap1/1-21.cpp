/*************************************************************************
	> File Name: 1-21.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年03月31日 星期六 16时31分23秒
 ************************************************************************/

#include<iostream>
#include<string>

struct Sales_data {
	std::string ISBN;    //书号
	int    num;   //销售数量
	double single; //销售单价
	double count ; //销售总额

};

int main()
{
	Sales_data Sales_1,Sales_2,Sale_c;

	std::cin >> Sales_1.ISBN >> Sales_1.num >> Sales_1.single;
	std::cin >> Sales_2.ISBN >> Sales_2.num >> Sales_2.single;
	Sales_1.count = Sales_1.num * Sales_1.single;
	Sales_2.count = Sales_2.num * Sales_2.single;
	
	if(Sales_1.ISBN == Sales_2.ISBN)
	{
		Sale_c.num = Sales_1.num + Sales_2.num;
		Sale_c.count = Sales_1.count + Sales_2.count;
		std::cout << Sales_1.ISBN << " " << Sale_c.num << " " << Sale_c.count << std::endl;
		return 0;
	} 
	else
	{
		std::cerr << "Data must refer to same ISBN" ;
		return -1;
	}
}
