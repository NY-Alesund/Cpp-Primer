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
#include<memory>
#include "Quote_and_Bulk.h"

int main()
{
	vector<shared_ptr<Quote>> itemVec;
	for (size_t i = 0; i != 10; ++i)
	{
		Quote item("C++ Primer",6);			//书名,单价,需要达到销售额，折扣
		shared_ptr<Quote> p = make_shared<Quote> (item);
		itemVec.push_back(p);
	}

	double sum = 0;
	//for (vector<shared_ptr<Quote>>::iterator iter = itemVec.begin(); iter != itemVec.end(); ++iter)
	//{
	//	sum += (**iter).net_price(10);					//调用Quote::net_price
	//}
	
	for (auto iter : itemVec)
		sum += (*iter).net_price(10);
	cout << sum << endl;								//输出

	return 0;
	
}
