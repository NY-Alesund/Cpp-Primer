/*************************************************************************
	> File Name: 2-38.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年03月31日 星期六 15时57分32秒
 ************************************************************************/

#include<iostream>
#include<typeinfo>
using namespace std;

int main()
{
	int a = 3;
	auto c1 = a;
	decltype(a) c2 = a;
	decltype((a)) c3 =a ;

	const int d = 5;
	auto f1 = d;         //auto 推断类型直接忽略顶层const
	decltype(d) f2 = d;

	std::cout << typeid(c1).name() << std::endl;
	std::cout << typeid(c2).name() << std::endl;
	std::cout << typeid(c3).name() << std::endl;
	std::cout << typeid(f1).name() << std::endl;
	std::cout << typeid(f2).name() << std::endl;

	c1++;
	c2++;
	c3++;
	f1++;
	//f2++;           //错误，f2是整形常量，不能进行自增

	std::cout << a << " " << c1 <<  " " << c2 << " " << c3 << " " << f1 <<" " << f2 << std::endl;
	return 0;
}


