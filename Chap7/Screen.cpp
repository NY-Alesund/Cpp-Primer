/*************************************************************************
	> File Name: Screen.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月07日 星期六 20时01分20秒
 ************************************************************************/

#include<iostream>
#include "Screen.h"
using namespace std;

int main()
{
	Screen myScreen(5,5,'X');
	myScreen.move(4,0).set('#').display();
	cout << "\n";
	myScreen.display();
	cout << "\n";
}
