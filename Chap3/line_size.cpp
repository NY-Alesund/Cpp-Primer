/*************************************************************************
	> File Name: line_size.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年03月31日 星期六 18时11分20秒
 ************************************************************************/
#include<iostream>
#include<string>
using namespace std;

int main()
{
    string line;
    while(getline(cin,line))
		if(line.size() > 12)   //每次读入一整行，输出其中超过12个字符的行
			cout << line <<endl;
    return 0;
}
