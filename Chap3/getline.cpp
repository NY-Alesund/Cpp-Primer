/*************************************************************************
	> File Name: getline.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年03月31日 星期六 18时03分04秒
 ************************************************************************/
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string line;
    while(getline(cin,line))
		cout << line <<endl;
    return 0;
}
