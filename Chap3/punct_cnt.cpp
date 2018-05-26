/*************************************************************************
	> File Name: punct_cnt.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年03月31日 星期六 19时01分46秒
 ************************************************************************/

/* 使用范围for语句和ispunct函数来统计string对象中标点符号个数 */

#include<iostream>
#include<cctype>
#include<string>
using namespace std;

int main()
{
    string s("Hello,world!~");
	decltype(s.size()) punct_cnt = 0;
  
	//统计s中标点符号的数量
	for(auto c : s)
		if(ispunct(c))
			++punct_cnt;
	cout << punct_cnt << " punctuation characters in " << s << endl;
	return 0;
}
