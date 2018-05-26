/*************************************************************************
	> File Name: 10-37.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月13日 星期五 22时44分46秒
 ************************************************************************/

/* 给定一个包含10个元素的vector,将位置3-7之间的元素按逆序拷贝到一个list中 */
#include<iostream>
#include<vector>
#include<list>
#include<iterator>
#include<algorithm>
using namespace std;

int main(int argc,char *argv[])
{
	ostream_iterator<int> out_iter(cout," ");
	vector<int> vi = { 0,1,2,3,4,5,6,7,8,9};
	//用流迭代器和copy输出int序列
	copy(vi.begin(),vi.end(),out_iter);
	cout << endl;

	list<int> li;
	//将vi[2] ， 也就是第3个元素的位置转换为反向迭代器
	vector<int>::reverse_iterator re(vi.begin()+2);

	//将vi[7] , 也就是第8个元素的位置转换为反向迭代器
	vector<int>::reverse_iterator rb(vi.begin()+7);

	//用反向迭代器将元素逆序拷贝到List
	copy(rb,re,back_inserter(li));
	copy(li.begin(),li.end(),out_iter);
	cout << endl;
	return 0;
}
