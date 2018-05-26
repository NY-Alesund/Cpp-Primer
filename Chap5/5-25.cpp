/*************************************************************************
	> File Name: 5-25.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月04日 星期三 16时57分14秒
 ************************************************************************/

/* 从标准输入读取两个整数，输出相除的结果。引用try-catch机制处理除数为０的情况*/
#include<iostream>
#include<stdexcept>
using namespace std;

int main()
{
	cout << "请依次输入被除数和除数:" << endl;
	int ival1,ival2;
	while(cin >> ival1 >> ival2)
	{
		try
		{
			if(ival2 == 0)
			{
				throw runtime_error("除数不能为0");  //抛出异常
			}
			cout << "两数相除的结果是:" << ival1/ival2 << endl;
		}
		catch(runtime_error err)	//try语句块捕获异常
		{
			cout << err.what() << endl;
			cout << "需要继续吗(y or n)?";
			char ch;
			cin >> ch;
			if(ch != 'y' && ch != 'Y')
				break;		//开始下一次循环
		}
	}
}
