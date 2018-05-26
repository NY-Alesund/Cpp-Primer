/*************************************************************************
	> File Name: 15-26.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月21日 星期六 21时14分18秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<ostream>
using namespace std;

class Quote
{
	public:
		Quote() = default;
		Quote(const std::string &book="",double sales_price = 0.0)
				: bookNo(book),price(sales_price)
		{
			cout << "Quote constructor is running" << endl;
		}
		std::string isbn() const
		{
			return bookNo;
		}
		//返回给定数量的书籍的销售总额,派生类改写并使用不同的折扣计算方法
		virtual double net_price(std::size_t n) const
		{
			return n*price;
		}
		virtual void debug()
		{
			cout << "bookNo=" << bookNo << " price=" << price << endl;
		}
		virtual ~Quote()
		{
			cout << "Quote destructor is running" << endl;
		}

		friend ostream &operator << (ostream&,Quote&);

	private:
		std::string bookNo;							//书籍的ISBN编号
	protected:
		double price = 0.0;							//代表普通状态下不打折的价格
};

ostream & operator << (ostream &os,Quote &e)
{
	os << "\tUsing operator << (ostream &,Quote &);" << endl;
	return os;
};

class Bulk_quote:public Quote
{
	public:
		Bulk_quote(const string &book="",double sales_price=0.0,size_t qty=0,double disc=0.0)
				: Quote(book,sales_price),min_qty(qty),discount(disc)
		{
			cout << "Bulk_constructor is running" << endl;
		}
		double net_price(size_t cnt) const
		{
			if (cnt > min_qty)
				return cnt * (1 - discount) * price;
			else
				return cnt * price;
		}
		~Bulk_quote()
		{
			cout << "Bulk_quote destructor is running" << endl;
		}
	private:
		size_t min_qty;
		double discount;
};

ostream &operator<<(ostream &os,Bulk_quote& bq)
{
	os << "\tUsing operator << (ostream&,Bulk_quote &)" << endl;
	return os;
}

int main(int argc,char *argv[])
{
	Quote base("C++ primer",128.0);
	Bulk_quote bulk("Core Python Programming",89,5,0.19);
	cout << base << endl;
	cout << bulk << endl;
	/* 执行完后的析构顺序和构造顺序正好相反*/

	return 0;
}
