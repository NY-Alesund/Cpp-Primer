/*************************************************************************
	> File Name: bookstore.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月12日 星期四 15时44分41秒
 ************************************************************************/

#include<iostream>
using namespace std;

istream_iterator<Sales_item> item_iter(cin),eof;
ostream_iterator<Sales_item> out_iter(cout,"\n");
//将第一笔交易记录存在sum中，并读取下一条记录
Sales_item sum = *item_iter++;
while(item_iter != eof) {
	//如果当前交易记录(存在item_iter中)有着相同的ISBN号
	if(item_iter->isbn() == sum.isbn())
		sum += *item_iter++;		//将其加到sum上并读取下一条记录
	else{
		out_iter = sum;				//输出sum当前值
		sum = *item_iter++;			//读取下一条记录
	}
}
out_iter = sum;				//记得打印最后一组记录的和

