/*************************************************************************
	> File Name: 4-22.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月04日 星期三 11时03分20秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int main()
{
	int grade;
	string finalgrade;
	cout << "请输入你的成绩: " << endl;
	while(cin >> grade && grade<=100 && grade>=0)
	{
		finalgrade = grade >= 60 ? (grade >= 75 ? (grade >= 90 ? "high pass" : "pass") : "low pass") : "fail" ;
		cout << "你的最终等级是：" << finalgrade << endl;
		cout << "请输入你的成绩: " << endl;
	}
	cout << "输入错误，退出" << endl;
	return 0;
}
