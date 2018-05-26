/*************************************************************************
	> File Name: author_pro.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月15日 星期日 20时54分23秒
 ************************************************************************/
/* 
 * 给定一个作者到著作题目的映射，打印一个特定作者的所有著作。
 * 三种不同的方法
 * */

#include<iostream>
#include<string>
#include<
using namespace std;


string search_item("Alain de Botton");	//要查找的作者



//使用find和count:
auto entries =	authors.count(search_item);		//元素的数量
auto iter	 =  author.find(search_item);		//此作者的第一本书
//用一个循环查找作者的所有著作
while(entries) {
	cout << iter->second << endl;		//打印每个题目
	++iter;		//前进到下一本书
	--entries;	//记录已经打印了多少本书
}


//使用lower_bound和upper_bound:
for (auto beg = authors.lower_bound(search_item),
		  end = authors.upper_bound(search_item); beg != end;	++beg)
	cout << beg->second << endl;	//打印每个题目


//使用equal_range(k)；	返回迭代器pair，表示关键字等于k的元素的范围
//pos保存迭代器对,表示与关键字匹配的元素范围
for (auto pos = authors.equal_range(search_item); pos.first != pos.second; ++pos.first)
	cout << pos.first->second << endl;	//打印每个题目
