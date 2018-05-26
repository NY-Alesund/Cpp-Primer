/*************************************************************************
	> File Name: Quote_Bluk.h
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月20日 星期五 09时31分52秒
 ************************************************************************/
using namespace std;

/* 定义基类 */
class Quote {
	public:
		Quote() = default;
		Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) { }
		std::string isbn() const { return bookNo; }
		
		//返回给定数量的书籍的销售总额
		//派生类负责改写并使用不同的折扣计算算法
		virtual double net_price(std::size_t n) const { return n*price; }
		virtual void debug()
		{
			cout << "bookNo=" << bookNo << " price=" << price << endl;	
		}
		virtual ~Quote() = default;			//对析构函数进行动态绑定

	private:
		std::string bookNo;					//书籍的ISBN编号
	protected:
		double price = 0.0;					//代表普通状态下不打折的价格
};

/* 定义派生类 */
class Bulk_quote : public Quote {			//Bulk_quote继承自Quote
	public:
		Bulk_quote() = default;	
		Bulk_quote(const std::string& book, double p, std::size_t qty, double disc) 
				: Quote(book,p), min_qty(qty), discount(disc) { }
		//覆盖基类的函数版本以实现基于大量购买的折扣政策
		double net_price(std::size_t cnt) const override	//关键字override显式表示覆盖了继承的虚函数
		{
			if(cnt >= min_qty)
				return cnt * (1 - discount) * price;		//达到销售额销售折扣
			else
				return cnt * price;
		}
		virtual void debug() 
		{
			Quote::debug();					//bookNo变量为private,所以不能直接访问bookNo
											//只能调用基类的debug()函数来显式
			cout << "min_qty=" << min_qty << " discount" << discount << endl; 
		}
	private:
		std::size_t min_qty = 0;			//适用折扣政策的最o低购买量
		double discount = 0.0;				//以小数表示的折扣额
};

/*
double Bulk_quote::net_price(size_t cnt) const
{
	if (cnt >= min_qty)
		return cnt * (1 - discount) *price;		//达到销售额销售折扣
	else
		return cnt * price;
}
*/


//计算并打印销售给定数量的某种书籍所得费用
double print_total(ostream &os, const Quote &item, size_t n)
{
	//根据传入item形参的对象类型调用Quote::new_price
	//或者Bulk_quote::net_price
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due : " << ret << endl;
	return ret;
}
