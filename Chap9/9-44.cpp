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
	int p = 0;
	while((p=s.find(oldval,p)) != string::npos) {	//在s中从0开始查找oldval
		s.replace(p,oldval.size(),newval);			//将找到的子串替换为newval的内容
		p += newval.size();							//下标调整到新插入内容之后
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
