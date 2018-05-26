/*************************************************************************
	> File Name: 5-14.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月04日 星期三 13时52分41秒
 ************************************************************************/

/* 统计连续出现次数最多的单词 */
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string curword,preword,maxword;
	int curcnt = 0,maxcnt = 0;
	
	while(cin >> curword)
	{
		if(curword == preword)
		{	
			++curcnt;
			if(curcnt > maxcnt)
			{
				maxcnt = curcnt;
				maxword = curword;
			}
		}
		else
		{
			curcnt = 1;
		}
		preword = curword;   //更新
	}
	cout << "出现最多的连续单词是: " << maxword <<  "!出现了" << maxcnt << "次" << endl;
	return 0;
}


