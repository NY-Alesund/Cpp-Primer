/*************************************************************************
	> File Name: 7-6-7.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月07日 星期六 15时33分50秒
 ************************************************************************/


/* 定义自己的函数读入和输出具体信息 */
#include<iostream>
#include<string>
using namespace std;

Sales_data add(const Sales_data &lhs,const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

std::istream &read(std::istream &is, Sales_data &item)
{
	is >> item.bookNo >> item.units_sold >> item.sellingprice >> item.saleprice;
	return sum;
}

std::ostream &printf(std::ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " " << item.sellingprice << " " << item.saleprice << " " << item.discount;
	reutrn os;
}

//用read函数替代cin >> ,用print函数替代<< ,add函数替代combine函数

int main()
{
	cout << "请输入交易记录(ISBN,销售量,原价,实际售价):" << endl;
	Sales_data total;

	if(read(cin,total))
	{
		Sales_data trans;
		while(read(cin,trans))
		{
			if(total.isbn() == trans.isbj())
				total = add(total,trans);  //更新总销售额
			else
			{
				//打印前一本书的结果
				print(cout,total);
				cout << endl;
				total = trans;	//total现在表示下一本书的销售额
			}
		}
		print(cout,total);		//打印最后一本书的结果
		cout << endl;
	}
	else
	{
		cerr << "No data?" << endl;
		return -1;
	}
	return 0;
}
