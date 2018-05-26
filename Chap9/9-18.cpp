/*************************************************************************
	> File Name: 9-18.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月10日 星期二 12时56分03秒
 ************************************************************************/
/* 编写程序，从标准输入读取string序列，存入到deque中。
 * 编写一个循环，用迭代器打印deque中的元素			*/

#include<iostream>
#include<deque>
using namespace std;

int main()
{
	deque<string> sd;		//string的deque

	string word;
	while(cin >> word)		//读取字符串，直至遇到文件结束符
		sd.push_back(word);

	//用c.begin()获取deque首元素迭代器，遍历deque中所有元素
	for (auto si = sd.cbegin(); si != sd.cend(); si++)
		cout << *si << endl;
	return 0;
}
