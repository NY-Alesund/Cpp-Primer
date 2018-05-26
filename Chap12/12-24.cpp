/*************************************************************************
	> File Name: 12-24.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月17日 星期二 19时19分10秒
 ************************************************************************/

/* 从标准输入中读取一个字符串,存取到动态分配的字符数组中.
 * 描述程序如何处理变长输入,测试你的程序,输入一个超出分配的数组长度的字符串 */
#include<iostream>
#include<cstring>
using namespace std;

int main(int argc,char *argv[])
{
	char c;

	//分配20个字符的动态数组
	//因此最多存放19个字符
	char *r = new char[20];
	int l = 0;

	while(cin.get(c)) {
		if(isspace(c))		//空格符，制表符等空白符
			break;
		r[l++] == c;		//存入动态数组
		if (l == 20) {
			cout << "达到数组容量上限" << endl;
			break;
		}			
	}
	
	r[l] = 0;

	cout << r << endl;

	//释放动态数组
	delete [] r;

	return 0;
}
