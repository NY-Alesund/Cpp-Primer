/*************************************************************************
	> File Name: book_store.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年03月27日 星期二 18时06分25秒
 ************************************************************************/

#include<iostream>
#include "Sales_item.h"
using namespace std;

int main()
{
	Sales_item	total;   // 每个ISBN的所有数据合并起来，存入名为total的变量中
	//读入第一条交易记录，确保有数据可处理
	if(std::cin >> total){
		Sales_item	trans;    //保存读取的每条销售记录

		//读入并处理剩余交易记录
		while(std::cin >> trans){
			//如果仍在处理相同的书
			if(total.isbn() == trans.isbn())
				total += trans;  //更新销售总额
			else{
				//打印前一本书的结果
				std::cout << total << std::endl;
				total = trans;  //total现在表示下一本书的销售额
			}
		}
		std::cout << total << std::endl;  //打印最后一本书的结果
	}
	else{
		//没有输入！警告读者
		std::cerr << "NO data?!" << std::endl;
		return -1; //表示失败
	}
	return 0;
}
