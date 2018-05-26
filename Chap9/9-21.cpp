/*************************************************************************
	> File Name: 9-21.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月10日 星期二 16时01分22秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<string> svec;		//string的vector

	string word;
	auto iter = svec.begin();	//获取vector首位置迭代器
	while( cin >> word )		//读取字符串，直至遇到文件结束符	
		iter = svec.insert(iter,word);	//在迭代器iter指向的元素之前插入word，返回指向添加元素的迭代器。

	//用cbegin()获取vector首元素迭代器，遍历vector中所有元素
	for (auto iter = svec.cbegin(); iter != svec.end(); ++iter)
		cout << *iter << endl;

	return 0;
}
