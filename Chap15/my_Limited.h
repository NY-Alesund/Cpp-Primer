/*************************************************************************
	> File Name: 15-5.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月21日 星期六 13时52分10秒
 ************************************************************************/

/* 声明自己的Limited_quote类 */
/* 购买量不超过max_qty的部分享受折扣，超出部分原价 */
class Limited_quote : public Quote
{
	public:
		Limited_quote() = default;
		Limited_quote(const std::string& book, double p, std::size_t qty, double disc)
				: Quote(book,p), max_qty(qty),	discount(disc) { }
		/* 覆盖基类的函数版本以实现基于大量购买的折扣政策 */
		double net_price(std::size_t) const override;			//关键字override显式表示覆盖了继承的虚函数
	private:
		std::size_t max_qty = 0;								//适用折扣政策的最低购买量
		double discount = 0.0;									//以小数表示的折扣额
};

double Limited_quote::net_price(size_t cnt) const
{
	if (cnt <= max_qty)
		return cnt * (1-discount) *price;						//达到销售额销售折扣
	else
		return max_qty*(1-discount)*price+(cnt-max_qty)*price;
}



