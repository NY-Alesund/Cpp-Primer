/*************************************************************************
	> File Name: 5-20.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月04日 星期三 16时26分09秒
 ************************************************************************/

/*　检测输入的字符串中连续出现的字符 */
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string curstring,prestring;
	bool b1 = true;
	cout << "请输入一组字符串:..." << endl;
	while(cin >> curstring)
	{
		if(curstring == prestring)
		{
			b1 = false;
			cout << "出现的连续字符是:" << curstring << endl;
			break;
		}
		else
			prestring = curstring;
	}
	if(b1)
		cout << "没有出现连续字符~" << endl;
	return 0;
}
