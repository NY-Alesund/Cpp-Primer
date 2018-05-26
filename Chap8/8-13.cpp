/*************************************************************************
	> File Name: 8-13.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月08日 星期日 16时43分15秒
 ************************************************************************/

//从文件中读取姓名和电话号码，格式正确则输出，格式不正确提示错误。
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

struct PersonInfo {
	string name;
	vector<string> phones;
};

string format(const string &s) { return s;}

bool valid(const string &s)
{
	return true;
}

int main(int argc,char *argv[])
{
	string line,word;				//分别保存来自输入的一行和单词
	vector<PersonInfo> people;		//保存来自输入的所有记录
	istringstream record;
	
	if(argc != 2) {
		cerr << "请给出文件名" << endl;
		return -1;
	}
	ifstream in(argv[1]);
	if(!in) {
		cerr << "无法打开输入文件" << endl;
		return -1;
	}

	while (getline(in,line)) {
		PersonInfo info;			//创建一个保存此记录数据的对象
		record.clear();				//重复使用字符串流时，每次都要调用clear
		record.str(line);			//将记录绑定到刚读入的行
		record >> info.name;		//读取名字
		while(record >> word)		//读取电话号码
			info.phones.push_back(word);	//保持它们

		people.push_back(info);		//将次记录追加到people末尾
	}

	ostringstream os;	
	for (const auto &entry : people) {		//对people中每一项
		ostringstream formatted,badNums;	//每个循环步创建的对象
	for (const auto &nums : entry.phones) { //对每个数
		if (!valid(nums))
		{
			badNums << " " << nums;			//将数的字符串形式存入badNums
		} else
			//将格式化的字符串写入formatted
			formatted << " " << format(nums);
	}
	if (badNums.str().empty())				//没有错误的数
		os << entry.name << " " << formatted.str() << endl;   //把名字和格式化的数输入到os
	else
		cerr << "input error:" << entry.name << " invalid number(s)" << badNums.str() << endl;
	}
	cout << os.str() << endl;		//将os所保存的string输出
	
	return 0;
}


