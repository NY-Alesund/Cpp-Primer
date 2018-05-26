/*************************************************************************
	> File Name: grade.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月01日 星期日 09时59分39秒
 ************************************************************************/

/* 根据输入统计各分数段的人数 */

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<unsigned> scrvec(10,0);
	int scores;
	while(cin >> scores) {
		if(scores >= 0 && scores <= 100)
			++scrvec[scores/10];
		else
			continue;
	}
	for (auto i : scrvec)
		cout << i << " ";
	cout << endl;
	return 0;
}
