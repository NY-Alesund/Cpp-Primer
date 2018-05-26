/*************************************************************************
	> File Name: 4-2.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月04日 星期三 09时43分27秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>

using namespace std;

int main()
{
	vector<int> vec;
	srand((unsigned) time(NULL));
	cout << "系统自动生成一组元素..." << endl;
	for(int i=0;i!=10;i++)
		vec.push_back(rand()%100);
	cout << "生成的向量数据:" << endl;
	for (auto c : vec)
		cout << c << " ";
	cout << endl;
	
	cout << "验证运算顺序:" << endl;
	cout << "*vec.begin()的值是:		" << *vec.begin() << endl;
	cout << "*(vec.begin())的值是:		" << *(vec.begin()) << endl;
	cout << "*vec.begin()+1的值是：		" << *vec.begin()+1 << endl;
	cout << "(*(vec.begin()))+1的值是:	" << (*(vec.begin()))+1 << endl;
	
	return 0;

}
