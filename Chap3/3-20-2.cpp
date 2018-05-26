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

	int end = vInt.size()-1;
	cout << "首尾两项的和依次是:" << endl;
	
	for(int beg = 0 ; beg <= end ; beg++,end-- )
	{
		if(beg == end)
			cout << vInt[beg];
		else	
			cout << vInt[beg] + vInt[end] << " ";
	}
	cout << endl;
	return 0;
}
