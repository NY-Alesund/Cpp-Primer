/*************************************************************************
	> File Name: 10-5.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月12日 星期四 18时28分01秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int main(int argc,char *argv[])
{
	char *p[] = {"Hello","World","!"};
	char *q[] = {strdup(p[0]),strdup(p[1]),strdup(p[2])};
	//strdup会先用malloc()配置与p字符串相同的空间大小，然后将参数p中的内容复制到该内存地址，然后返回该地址。
	char *r[] = {p[0],p[1],p[2]};
	cout << equal(begin(p),end(p),q) << endl;		//输出0
	cout << equal(begin(p),end(p),r) << endl;		//输出1

	return 0;
}

