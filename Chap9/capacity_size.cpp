/*************************************************************************
	> File Name: capacity_size.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月09日 星期一 19时57分16秒
 ************************************************************************/

/* 
 * capacity和size的区别 
 * capacity是最多保存多少元素（内存空间大小）
 * size是指已经保存的元素的数目	
 * */


#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> ivec;	//size应该为0;capacity的值依赖于具体实现

	cout << "ivec::size: " << ivec.size()
		 << " capacity: " << ivec.capacity() << endl;

	//向ivec添加24个元素
	for (vector<int>::size_type ix = 0; ix != 24; ++ix)
		ivec.push_back(ix);

	//size应该为24，capacity应该大于等于24，具体依赖与标准库的实现
	cout << "ivec::size: " << ivec.size()
		 << " capacity: "  << ivec.capacity() << endl;

	ivec.shrink_to_fit();	//归还内存

	//size的值不变，capacity的值依赖于具体实现
	cout << "归还内存后的值为：..." << endl;
	cout << "ivec::size: " << ivec.size()
		 << " capacity: "  << ivec.capacity() << endl;
	
	return 0;
}
