/*************************************************************************
	> File Name: 6-10.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月04日 星期三 19时11分18秒
 ************************************************************************/

#include<iostream>
using namespace std;

void mySWAP(int &p,int &q)
{
	int tmp = p;
	p = q;
	q = tmp;
}

int main()
{
	int a,b;
	cin >> a >> b;
	int &r =a,&s = b;
	cout << "交换前 a = " << a << " b = " << b << endl;
	mySWAP(r,s);
	cout << "交换后 a = " << a << " b = " << b << endl;
	return 0;
}
