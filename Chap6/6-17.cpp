/*************************************************************************
	> File Name: 6-17.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月04日 星期三 19时28分39秒
 ************************************************************************/
/*判断字符串中是否有大写字母，并把string对象全部转化为小写*/

#include<iostream>
#include<string>
using namespace std;

bool HasUpper(string& str)  //判断字符串是否有大写字母
{
	for(auto c : str)
		if(isupper(c))
			return true;
	return false;
}

void ChangeToLower(string& str)   //把字符串中大写字母转化为小写
{
	for(auto &c : str)
		c = tolower(c);
}

int main()
{
	cout << "请输入一个字符串:" << endl;
	string str;
	cin >> str;
	if(HasUpper(str))
	{
		ChangeToLower(str);
		cout << "转换后的字符串是:" << str << endl;
	}
	else
		cout << "该字符串不含大写字母,无须转换" << endl;
	return 0;
}
