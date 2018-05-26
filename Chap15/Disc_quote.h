/*************************************************************************
	> File Name: Disc_quote.h
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月20日 星期五 12时32分29秒
 ************************************************************************/

/* 抽象基类 */
//用于保存折扣值和购买量的表，派生类使用这些数据可以实现不同的价格策略
class Disc_quote : public Quote {
	public:
		Disc_quote() = default;
		Disc_quote(const std::string& book,double price,std::size_t qty,double disc) 
			: Quote(book,price), quantity(qty), discount(disc) { }
		double net_price(std::size_t) const = 0;
	protected:
		std::size_t  quantity = 0;          //折扣适用的购买量
		double discount = 0.0;              //表示折扣的小数值
}

/* 当同一书籍的销售量超过了某个值是启动折扣 */
/* 折扣的值是一个小于1的正的小数值，以此来降低正确销售价格 */
class Bulk_quote : public Disc_quote {
	public:
		Bulk_quote() = default;
		Bulk_quote(const std::string& book,double price, std::size_t qty, double disc)
					: Disc_quote(book,price,qty,disc) { }
		//覆盖基类中的函数版本以实现一种新的折扣策略
		double net_price(std::size_t) const override;
};

