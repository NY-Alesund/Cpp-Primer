/*************************************************************************
	> File Name: 9-43.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月10日 星期二 22时29分55秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

void replace_string(string &s, const string &oldval, const string &newval)
{
	auto l = oldval.size();
	if (!l)
		return;
	auto iter = s.begin();
	while(iter <= s.end() - 1) {		//末尾少于oldval长度的部分无须检查
		auto iter1 = iter;
		auto iter2 = oldval.begin();
		//s中iter开始的子串必须每个字符都与oldval相同
		while(iter2 != oldval.end() && *iter1 == *iter2) {
			iter1++;
			iter2++;
		}
		if(iter2 == oldval.end()) {		//oldval耗尽--字符串相等
			iter = s.erase(iter,iter1);	//删除s中与oldval相等部分
			if (newval.size()) {		//替换子串是否非空
				iter2 = newval.end();	//由后至前逐个插入newval中的字符
				do {
					iter2 --;
					iter = s.insert(iter,*iter2);
				} while( iter2 > newval.begin());
			}
			iter += newval.size();		//迭代器移动到新插入内容之后
		}	else iter++;
	}
}

int main()
{
	string s = "tho thru tho!";
	replace_string(s,"thru","through");
	cout << s << endl;

	replace_string(s,"tho","though");
	cout << s << endl;

	replace_string(s,"through"," ");
	cout << s << endl;

	return 0;
}
