/*************************************************************************
	> File Name: 3-36-arr.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月01日 星期日 15时13分32秒
 ************************************************************************/

#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

int main()
{
	const int sz = 5;
	int a[sz], b[sz], i;
	
	srand((unsigned) time(NULL));   //生成随机数种子
	
	for(i=0; i<sz; i++)
		a[i] = rand()%10;
	cout << "系统数据已生成，请输入你猜测的5个数字（0~9） 可以重复:" << endl;
	int uVal;
	for(i=0;i<sz;i++)
		if(cin >> uVal)
			b[i] = uVal;
	
	cout << "系统生成的数据是：" << endl;
	for(auto val : a)
		cout << val << " ";
	cout << endl;
	cout << "你猜测的数据是: " << endl;
	for(auto val : b)
		cout << val << " ";
	cout << endl;
	
	int cnt = 0;		//记录猜对了几个
	int *p = begin(a);
	int *q = begin(b);
	while(p!=end(a) && q!=end(b))
	{	
		if( *p == *q)
			cnt++;
		++p;
		++q;
	}
	if( cnt == 5 )
		cout << "恭喜你全答对了!" << endl;
	else
		cout << "你猜对了" << cnt << "个数字!" << endl;
	return 0;
}
