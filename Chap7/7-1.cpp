/*************************************************************************
	> File Name: 7-1.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月07日 星期六 13时27分59秒
 ************************************************************************/

#include<iostream>
#include"Sales_item.h"

using namespace std;

int main()
{
	cout << "请输入交易记录(ISBN,销售量,原价,实际售价)：" << endl;
	Sales_item total;

	//读入第一条交易记录，确保有数据可处理
	if(cin >> total)
	{
		Sales_item trans;  
		//读入并处理剩余交易记录
		while(cin >> trans)
		{
			if(total.isbn() == trans.isbn())
				total += trans;   //更新总销售额
			else
			{
				cout << total << endl;
				total = trans;			//total现在表示下一本书的销售额
			}
		}
		cout << total << endl;	//打印最后一本书的结果
	}
	else
	{
		cerr << "NO data?!" << endl;
		return -1;   
	}
	return 0;
}
