/*************************************************************************
	> File Name: 3-14.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月01日 星期日 12时08分29秒
 ************************************************************************/

/* 输入一组整数，存到vector对象，然后打印出来*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	vector<int> iVal;
	int i;
	char flag;
	cout << "请输入一个整数：";
	while(cin >> i) {
		iVal.push_back(i);
		cout << "请选择继续输入(y)或者退出(n): ";
		cin >> flag;
		if(flag == 'y') {
			cout << "请输入一个整数: ";
			continue;
		}

		if(flag == 'n') break;
	}

	for (auto v : iVal)
		cout << v << " ";
	cout << endl;
	return 0;
		
}

