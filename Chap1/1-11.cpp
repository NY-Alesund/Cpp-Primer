/*************************************************************************
	> File Name: 1-11.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年03月27日 星期二 15时47分54秒
 ************************************************************************/

#include<iostream>

int main()
{
	std::cout << "Please input two integer,I will printf all integer betwwen it :" << std::endl;
	int val1 = 0,val2 = 0;
	std::cin >> val1 >> val2;
	int a,b;
	if(val1 > val2)
	{
		a = val1;
		b = val2;
	}
	else
	{
		a = val2;
	    b = val1;
	}
	while(b <= a )
	{
		std::cout << b << std::endl;
		b++;
	}

	return 0;

}
