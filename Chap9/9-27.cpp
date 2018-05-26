/*************************************************************************
	> File Name: 9-27.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月10日 星期二 20时48分36秒
 ************************************************************************/

/* 查找并删除forward_list<int>中的奇数元素 */

#include<iostream>
#include<forward_list>
using namespace std;

int main()
{
	forward_list<int> iflst =  {1,2,3,4,5,6,7,8};

	auto prev = iflst.before_begin();		//前驱元素
	auto curr = iflst.begin();				//当前元素

	while (curr != iflst.end())
		if(*curr & 1)						//奇数		//与1按位与相当于和0x00000001相与
			curr = iflst.erase_after(prev);	//删除，erase_after返回一个指向被删元素之后的迭代器；：移动到下一元素
		else{
			prev = curr;
			curr ++;
		}
	for (curr = iflst.begin(); curr != iflst.end(); ++curr)
		cout << *curr << " ";
	cout << endl;

	return 0;
}

