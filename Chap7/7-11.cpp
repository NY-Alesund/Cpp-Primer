/*************************************************************************
	> File Name: 7-11.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月07日 星期六 15时59分41秒
 ************************************************************************/

//添加构造函数并使用

#include<iostream>
using namespace std;

class Sales_data
{
public:				//构造函数的４种形式
	Sales_data() = default;
	Sales_data(const std::string &book): bookNo(book) {}
	Sales_data(const std::string &book, const unsigned num, const double sellp, const double salep);
	Sales_data(std::istream &is);
private:
	std::string bookNo;		
	unsigned units_sold = 0;
	double sellingprice = 0.0;
	double saleprice    = 0.0;
	double discount     = 0.0;
};

Sales_data::Sales_data(const std::string &book, const unsigned num, const double sellp, const double salep)
{
	bookNo = book;
	units_sold = num;
	sellingprice = sellp;
	saleprice = salep;
	if(sellingprice != 0)
		discount = saleprice / sellingprice;  //计算实际折扣
}

Sales_data::Sales_data(std::istream &is)
{
	is >> *this;
}

int main()
{
	Sales_data data1;
	Sales_data data2("978-7-121-15535-2");
	Sales_data data3("978-7-121-15535-2",100,128,109);
	Sales_data data4(cin);

	cout << "书籍的销售情况是:" << endl;
	cout << data1 << "\n" << data2 << "\n" << data3 << "\n" << data4 << "\n";
	return 0;
}
