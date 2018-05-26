/*************************************************************************
	> File Name: 4-13.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月04日 星期三 10时49分32秒
 ************************************************************************/
/*产生随机vector对象元素*/
#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace std;

int main()
{
	vector<int> ival;
	int sz  = 10;
	srand((unsigned) time(NULL));
	cout << "生成10个随机数字..." << endl;
	for (int i=0;i!=sz;i++)
		ival.push_back(rand()%100);
	cout << "生成的10个数字是:" << endl;
	for (auto c : ival)
		cout << c << " ";
	cout << endl;

	cout << "将其中的奇数翻倍:" << endl;
	for (auto &d : ival)
	{
		if( d%2 == 1)
			d *= 2;
		cout << d << " ";
	}
	cout << endl;
	
	return 0;

}

