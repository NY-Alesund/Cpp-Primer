/*************************************************************************
	> File Name: 9-14.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月10日 星期二 11时31分20秒
 ************************************************************************/

/* 将一个list中的char*指针元素赋值给一个vector中的string */
#include<iostream>
#include<vector>
#include<list>
using namespace std;

int main()
{
	list<char *> slist = {"hello","world","!"};
	vector<string> svec;

	/*	容器类型不同，不能直接赋值
		svec = slist			*/
	//元素类型相容，可以采用范围赋值
	svec.assign(slist.begin(),slist.end());

	cout << svec.capacity() << " " << svec.size() << " " << svec[0] << " " << svec[svec.size()-1] << endl;

	return 0;
}
