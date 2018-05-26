/*************************************************************************
	> File Name: 16-4.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月22日 星期日 20时00分43秒
 ************************************************************************/

/* 编写行为类似标准库find算法的模板
 * 需要两个模板类型参数，一个表示函数的迭代器参数，一个表示值的类型 */
#include<iostream>
#include<string>
#include<vector>
#include<list>
using namespace std;

/*I表示迭代器的类型,T表示值的类型。此函数返回一个迭代器,类型为I*/
template <typename I,typename T>
I find(I b,I e, const T &v)
{
	while (b != e && *b != v)
		b++;
	return b;
}

int main()
{
	vector<int> vi = {0,2,4,6,8,10};
	list<string> ls = { "Hello", "World", "!"};

	auto iter = find(vi.begin(), vi.end(), 6);
	if (iter == vi.end())
		cout << "can not find 6" << endl;
	else
		cout << "find 6 at position " << iter - vi.begin() << endl;

	auto iter1 = find(ls.begin(), ls.end(), "mom");
	if (iter1 == ls.end())
		cout << "can not find mom" << endl;
	else
		cout << "found mom" << endl;

	return 0;
}
