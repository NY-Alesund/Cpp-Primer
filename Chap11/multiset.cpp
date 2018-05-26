/*************************************************************************
	> File Name: multiset.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月14日 星期六 17时31分27秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main()
{
	vector<int> ivec;
	for (vector<int>::size_type i = 0; i != 10; ++i) {
		ivec.push_back(i);
		ivec.push_back(i);	//每个数重复保存一次
	}

	//iset包含来自ivec的不重复元素；miset包含所有20个元素
	set<int> iset(ivec.cbegin(),ivec.cend());
	multiset<int> miset(ivec.cbegin(),ivec.cend());
	cout << ivec.size() << endl;	
	cout << iset.size() << endl;
	cout << miset.size() << endl;

	return 0;

}
