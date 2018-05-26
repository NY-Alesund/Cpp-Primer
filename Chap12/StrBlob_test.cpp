/*************************************************************************
	> File Name: StrBlob_test.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月17日 星期二 16时06分19秒
 ************************************************************************/

#include<iostream>
#include "my_StrBlob.h"

using namespace std;

int main(int argc,char *argv[])
{
	StrBlob b1;
	{
		StrBlob b2 = {"a","an","the"};
		b1 = b2;
		b2.push_back("about");
		cout << b2.size() << endl;
	}
	cout << b1.size() << endl;
	cout << b1.front() << " " << b1.back() << endl;

	const StrBlob b3 = b1;
	cout << b3.front() << " " << b3.back() << endl;
}

