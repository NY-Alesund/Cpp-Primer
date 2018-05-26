/*************************************************************************
	> File Name: 9-31.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月10日 星期二 21时40分20秒
 ************************************************************************/

/* 在list中删除偶数元素并复制奇数值元素	*/

#include<iostream>
#include<list>
using namespace std;

int main()
{
	list<int> ilst = {0,1,2,3,4,5,6,7,8,9};
	auto curr = ilst.begin();				//首节点

	while(curr != ilst.end()) {
		if(*curr & 1) {			//判断是否是奇数
			curr = ilst.insert(curr,*curr);	//插入到当前元素之前,返回指向插入的元素的迭代器
			curr ++; curr ++;				//移动到下一元素
		} else								//偶数
			curr = ilst.erase(curr);		//删除，curr指向下一元素
	}

	for(curr = ilst.begin(); curr != ilst.end(); ++curr)
		cout << *curr << " ";
	cout << endl;
	
	return 0;
}
