/*************************************************************************
	> File Name: 11-31.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月16日 星期一 10时11分48秒
 ************************************************************************/

/* 定义一个作者及其作品的multimap，使用find查找第一个元素并用erase删除。*/
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

void remove_author(multimap<string,string> &books, const string &author)
{
	auto pos = books.equal_range(author);		//查找给定作者范围
	if (pos.first == pos.second)		//空范围，没有该作者
		cout << "没有" << author << "这个作者" << endl << endl;
	else
		books.erase(pos.first,pos.second);		//删除该作者所有著作
}

void print_books(multimap<string,string> &books)
{
	cout << "当前书目包括:" << endl;
	for (auto &book : books)		//遍历所有书籍，打印之
		cout << book.first << ",《" << book.second << "》" << endl;
	cout << endl;
}

int main(int argc,char *argv[])
{
	multimap<string,string> books;
	books.insert({"Barth,John","Sot-Weed Factor"});
	books.insert({"Barth,John","Lost in the Funhouse"});
	books.insert({"金庸","射雕英雄传"});
	books.insert({"金庸","天龙八步"});

	print_books(books);

	remove_author(books,"张三");

	remove_author(books,"Barth,John");
	print_books(books);

	return 0;
}
