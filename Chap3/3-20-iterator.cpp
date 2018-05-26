/*************************************************************************
	> File Name: 3-20-1.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月01日 星期日 12时38分54秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> vInt;
	int iVal;
	cout << "请输入一组数字: " << endl;
	while(cin >> iVal)
		vInt.push_back(iVal);
	if(vInt.size() == 0)
	{
		cout << "没有任何数字" << endl;
		return -1;
	}

	cout << "首尾两项的和依次是:" << endl;
	
	auto beg = vInt.begin();
	auto end = vInt.end()-1;

	for( ; beg != end ; beg++,end--)
	{	
		cout << *beg + *end << " ";
	}
	if(beg == end)
		cout << *beg;
	cout << endl;
	return 0;
}
