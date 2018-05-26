/*************************************************************************
	> File Name: 7-13.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月07日 星期六 18时40分09秒
 ************************************************************************/

#include<iostream>
#include "Sales_data.h"
using namespace std;

int main()
{
	Sales_data total(cin);		//保存当前求和结果的变量
	if (cin)
	{
		Sales_data trans(cin);
		do
		{
			if(total.isbn == trans.isbn())
				total.combine(trans);
			else
			{
				print(cout,total) << endl;
				total = trans;
			}
		}while(read(cin,trans));
		print(cout,total) << endl;		//输出最后一条交易
	}
	else
	{
		cerr << "No data?!" << endl;
	}
	return 0;
}
