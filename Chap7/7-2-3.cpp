/*************************************************************************
	> File Name: 7-2-3.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月07日 星期六 13时46分24秒
 ************************************************************************/

//练习７－２　７－３合并

#include<iostream>
using namespace std;

class Sales_data
{
	private:			//定义私有数据成员
		string bookNo;	//书籍编号，隐形初始化为空串
		unsigned units_sold = 0;	//销售量
		double sellingprice = 0.0;	//原始价格
		double saleprice    = 0.0;	//实售价格
		double discount		= 0.0;	//折扣
	
	public:				//定义公有函数成员
		//isbn函数只有一条语句，返回bookNo
		string isbn() const  { return bookNo;}
		//combine函数用于把两个isbn相同的销售记录合并在一起
		Sales_data& combine(const Sales_data &rhs)
		{
			units_sold += rhs.units_sold;		//累加书籍的销售量
			saleprice	= (rhs.saleprice * rhs.units_sold + saleprice * units_sold) / (rhs.units_sold + units_sold);
			//重新计算实际销售价格
			
			if(sellingprice != 0)
				discount = saleprice / sellingprice;  //重新计算实际折扣
			return *this;		//返回合并后的结果
		}
};

int main()
{
	cout << "请输入交易记录(ISBN,销售量,原价,实际售价):" << endl;
	Sales_data total;			//保存交易记录的和变量
	//读入第一条交易记录，确保有数据可处理
	if(cin >> total)
	{
		Sales_data trans;	//保存下一条交易记录
		while(cin >> trans)
		{
			if(total.isbn() == trans_isbn())
				total.combine(trans);	//更新总销售额
			else
			{
				//打印前一本书的结果
				cout << total << endl;
				total = trans;		//total现在表示下一本书的销售额
			}
		}
		cout << total << endl;	//打印最后一本书的结果
	}
	else
	{
		//没有输入，警告
		cerr << "No data~!" << endl;
		return -1;  //失败
	}
	return 0;
}
