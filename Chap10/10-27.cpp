/*************************************************************************
	> File Name: 10-27.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月13日 星期五 16时24分01秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

int main(int argc,char *argv[])
{
	vector<int> v1 = {1,2,2,3,4,5,5,6};
	list<int> li;

	unique_copy(v1.begin(),v1.end(),back_inserter(li));

	for(auto v : li)
		cout << v << " ";
	cout << endl;

	return 0;
}
