/*************************************************************************
	> File Name: Screen.h
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月07日 星期六 19时48分24秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

class Screen
{
private:
	unsigned height = 0, width = 0;
	unsigned cursor = 0;
	string contents;
public:
	//构造函数
	Screen() = default;
	
	Screen(unsigned ht, unsigned wd) : height{ht}, width(wd), contents(ht * wd,' ') {}; 
	//接受高和宽的值，contents初始化屏幕成给定数量的空白' '
	
	Screen(unsigned ht, unsigned wd, char c) : height(ht), width(wd), contents(ht * wd, c) {};  //将
	//接受高和宽的值以及一个字符，将该字符作为初始化之后屏幕的内容。

public:
	//添加Screen类的move,set,display函数
	Screen& move(unsigned r, unsigned c)
	{
		cursor = r * width + c;
		return *this;
	}
	Screen& set(char ch)
	{
		contents[cursor] = ch;
		return *this;
	}
	Screen& set(unsigned r, unsigned c, char ch)
	{
		contents[r * width + c] = ch;
		return *this;
	}
	Screen& display()
	{
		cout << contents;
		return *this;
	}
};


