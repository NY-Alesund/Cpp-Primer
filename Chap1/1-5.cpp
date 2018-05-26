/*************************************************************************
	> File Name: 1-4.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年03月27日 星期二 15时12分22秒
 ************************************************************************/

#include<iostream>
using namespace std;
/*
 *简单主函数
 *读取两个数，求它们的乘积
 */

int main()
{
	int v1=0,v2=0;
	std::cin  >> v1 >> v2 ;  //输入两个数
	std::cout << "Enter two numbers:\n" << "The mul of " << v1 << " and " << v2
			  << " is " << v1*v2 << std::endl;   //输出长语句
	return 0;

}
