/*************************************************************************
	> File Name: 7-7.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月07日 星期六 18时52分04秒
 ************************************************************************/

#include<iostream>
#include "Sales_data.h"
using namespace std;

int main()
{
	cout << "请输入交易记录(ISBN,销售量,售价):" << endl;
	Sales_data total;

	if(read(cin,total))
	{
		Sales_data trans;		//保存和的变量

		while(read(cin,trans))
		{
			if(total.isbn() == trans.isbn())
				total.combine(trans);
			else
			{
				print(cout,total);
				cout << endl;
				total = trans;
			}
		}
		print(cout,total);
		cout << endl;
	}
	else
	{
		cerr << "No data?!" << endl;
		return -1;
	}
	return 0;
}
