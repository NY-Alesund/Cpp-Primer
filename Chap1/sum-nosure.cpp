/*************************************************************************
	> File Name: sum-nosure.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年03月27日 星期二 16时05分18秒
************************************************************************/

/* 预先不知道数字个数的求和程序 */

#include<iostream>
using namespace std;

int main()
{
	int sum = 0, value = 0;

	/* 读取文件直到遇到文件尾，计算所有读入的值的和 */
	while(std::cin >> value)   //当检测到输入文件结束符-Ctrl+D  或者 检测到输入不是整数时，输出和
		sum += value;
	std::cout << "Sum is : " << sum << std::endl;
	return 0;
}

