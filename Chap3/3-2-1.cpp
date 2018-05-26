/*************************************************************************
	> File Name: 3-2.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月01日 星期日 11时13分30秒
 ************************************************************************/
/* 读取一整行 */
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string line;
	while(getline(cin,line))
		cout << line << endl;
	return 0;
}
