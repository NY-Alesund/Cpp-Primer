/*************************************************************************
	> File Name: 9-28.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月10日 星期二 20时53分54秒
 ************************************************************************/

/* 
 * 接受一个forward_list<string>和两个string
 * 在链表中查找第一个string,并将第二个string插入到紧接着第一个string之后位置。
 * 若第一个string未在链表，则将第二个string插入到链表末尾
*/

#include<iostream>
#include<forward_list>
using namespace std;

void test_and_insert(forward_list<string> &sflst, const string &s1, const string &s2)
{
	auto prev = sflst.before_begin();		//前驱元素
	auto curr = sflst.begin();				//当前元素
	bool inserted = false;

	while(curr != sflst.end()) {
		if(*curr == s1) {							//找到给定字符串
			curr = sflst.insert_after(curr,s2);		//插入新字符串，curr指向它
			inserted = true;
		}
	}
	
	if (!inserted)
		sflst.insert_after(prev,s2);			//未找到给定字符串，插入尾后
}

int main()
{
	forward_list<string> sflst = {"Hello", "!", "world", "!"};

	test_and_insert(sflst,"Hello","你好");
	for(auto curr = sflst.cbegin(); curr != sflst.cend(); curr++)
		cout << *curr << " ";
	cout << endl;

	test_and_insert(sflst,"!","?");
	for(auto curr = sflst.cbegin(); curr != sflst.cend(); curr++)
		cout << *curr << " ";
	cout << endl;

	test_and_insert(sflst,"Bye","再见");
	for(auto curr = sflst.cbegin(); curr != sflst.cend(); curr++)
		cout << *curr << " ";
	cout << endl;

	return 0;
}

