/*************************************************************************
	> File Name: 13-17.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月19日 星期四 13时36分31秒
 ************************************************************************/

#include<iostream>
using namespace std;

class numbered {
	public:
		numbered () { mysn = seq++; }
		//13-15
		numbered (numbered &n) { mysn = seq++; }
		int mysn;
	private:
		static int seq;
};

int numbered::seq = 0;

//13-16
//void f(const numbered &s)
void f(numbered s)
{
	cout << s.mysn << endl;
}

int main(int argc,char **argv)
{
	numbered a , b=a , c=b ;
	f(a),f(b),f(c);

	return 0;
}
