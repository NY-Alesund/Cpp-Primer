/*************************************************************************
	> File Name: 9-45.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月10日 星期二 22时58分14秒
 ************************************************************************/

/* 接受一个表示名字的string参数和两个分别表示前缀和后缀的字符串。使用迭代器及insert和append函数将前缀和后缀添加到给定的名字中 
 * 将生成新的string返回	*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

void name_string(string &name, const string &prefix, const string &suffix)
{
	name.insert(name.begin(),1,' ');			//开头插入一个空格
	name.insert(name.begin(),prefix.begin(),prefix.end());	//插入前缀
	name.append(" ");							//末尾插入一个空格
	name.append(suffix.begin(),suffix.end());				//插入后缀
}

int main()
{
	string s = "James Bond";
	name_string(s,"Mr.","II");
	cout << s << endl;

	s = "M";
	name_string(s,"Mrs.","III");
	cout << s << endl;

	return 0;
}
