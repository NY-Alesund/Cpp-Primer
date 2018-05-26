/*************************************************************************
	> File Name: 15-28.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月21日 星期六 22时01分21秒
 ************************************************************************/

/* 定义一个存放Quote对象的vector,将Bulk_quote对象传入其中。计算vector中所有元素总的net_price */
#include<iostream>
#include<string>
#include<ostream>
#include<vector>
#include "Quote_and_Bulk.h"

int main()
{
	vector<Bulk_quote> itemVec;
	for (size_t i = 0; i != 10; ++i)
	{
		Bulk_quote item("C++ Primer",6,5,0.5);			//书名,单价,需要达到销售额，折扣
		itemVec.push_back(item);
	}

	double sum = 0;
	for (vector<Bulk_quote>::iterator iter = itemVec.begin(); iter != itemVec.end(); ++iter)
	{
		sum += iter -> net_price(10);					//调用Quote::net_price
	}

	cout << sum << endl;								//输出

	return 0;
	
}
