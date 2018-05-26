/*************************************************************************
	> File Name: 6-7.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月04日 星期三 18时18分16秒
 ************************************************************************/

#include<iostream>
using namespace std;

unsigned myCnt()
{
	static unsigned iCnt = -1;
	++iCnt;
	return iCnt;
}

int main()
{
	cout << "请输入任意字符后按回车键继续" << endl;
	char ch;
	while(cin >> ch)
	{
		cout << "函数myCnt()的执行次数是：" << myCnt() << endl;  //多次调用不会重复声明定义iCnt的值为０；
	}
	return 0;
}


