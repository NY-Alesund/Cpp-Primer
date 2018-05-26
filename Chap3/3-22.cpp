/*************************************************************************
	> File Name: 3-22.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月01日 星期日 13时16分07秒
 ************************************************************************/

/* 将输入的字符串转化为大写形式，每次输入可以输入n行 */

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	vector<string> text;         //text可以看成字符串数组
	string s;
	
	while(getline(cin,s))		//每个vector对象是一行字符串
		text.push_back(s);

	for(auto it = text.begin(); it != text.end();it++)  //遍历所有字符串，不受空白符影响。
	{
		for(auto it2 = it->begin();it2 != it->end();it2++)  //遍历当前字符串
			*it2 = toupper(*it2);            //转化为大写
		cout << *it << endl;
	}
	return 0;
}
