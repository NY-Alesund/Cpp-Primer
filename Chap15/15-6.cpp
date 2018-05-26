/*************************************************************************
	> File Name: 15-6.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月21日 星期六 14时13分38秒
 ************************************************************************/

#include<iostream>
#include<string>
#include "my_Quote.h"
#include "my_Limited.h"		//当购买书籍不超过一个给定的限量时享受折扣,超过限量的原价

int main()
{
	Quote Qt("Lebron James",23);
	Limited_quote BQ("Kobe Bryant",24,500,0.1);
	print_total(cout,Qt,1000);
	print_total(cout,BQ,1000);
	return 0;

}
