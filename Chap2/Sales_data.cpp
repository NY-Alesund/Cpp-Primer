/*************************************************************************
	> File Name: Sales_data.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年03月28日 星期三 23时37分11秒
 ************************************************************************/


#include<iostream>
#include<string>
#include<Sales_data.h>
using namespace std;

int main()
{
	Sales_data data1,data2;
	
	double price = 0; //书的单价，用于计算销售输入

	//读入第一笔交易的IBSN  销售额 和 单价
	std::cin >> data1.bookNO >> data1.units_sold >> price ;
	//计算销售收入
	data1.revenue = data1.units_sold * price;

	//读入第二笔
	std::cin >> data2.bookNO >> data2.units_sold >> price ;
	data2.revenue = data2.units_sold * price;

	//判断IBSN是否相同
	if(data1.bookNO == data2.bookNO){
		unsigned totalCnt = data1.units_sold + data2.units_sold;
		double totalRevenue = data1.revenue + data2.revenue;
		//输出 IBSN 总销售量 销售额 平均单价
		std::cout << data1.bookNO << " " << totalCnt << " " << totalRevenue << " ";
		if(totalCnt != 0)
			std::cout << totalRevenue / totalCnt <<std::endl;
		return 0;  //标志成功
	}
	else{
std:cerr << "Data must refer to the same ISBN" << std::endl;
	return -1; //标志失败
	}
}

