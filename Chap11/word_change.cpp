/*************************************************************************
	> File Name: word_change.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月15日 星期日 00时06分55秒
 ************************************************************************/
/* 单词转换程序 */

#include<iostream>
#include<map>
#include<string>
#include<sstream>
#include<vector>
#include<fstream>
#include<stdexcept>
#include<algorithm>
using namespace std;


/* 函数buildMap读入给定文件(转换规则文件)，建立起转换映射 */
map<string,string> buildMap(ifstream &map_file)
{
	map<string,string> trans_map;		//保存转换规则
	string key;		//要转换的单词
	string value;	//替换后的内容

	//读取第一个单词存入key中，行中剩余内容存入value
	while(map_file >> key && getline(map_file,value)) //map_file是输入流
		if(value.size() > 1)	//检查是否有转换规则
			trans_map[key] = value.substr(1);	//跳过前导空格
		else
			throw runtime_error("no rule for" + key);
	return trans_map;	//返回映射map
}


//函数transform进行实际的转换工作。如果给定string在map中，transform返回相应的短语。
const string &transform(const string &s, const map<string,string> &m)
{
	//实际的转换工作
	auto map_it = m.find(s);		//map_it是一个指向s对于的转换规则的迭代器
	//如果单词在转换规则map中
	if (map_it != m.cend())
		return map_it->second;	//使用替换短语
	else return s;			//否则返回原string
}


/* 单词转换函数，接受一个string,返回转换后的内容 */
void word_transform(ifstream &map_file, ifstream &input)
{
	auto trans_map = buildMap(map_file);	//保存转换规则
	string text;				//保存输入中的每一行
	while(getline(input,text)) {
		istringstream stream(text);		//读取每个单词
		string word;
		bool firstword = true;			//控制是否打印空格
		while(stream >> word) {
			if(firstword)
				firstword = false;	//第一个单词不打印空格，之后firstword都是false，打印空格
			else
				cout << " ";			//在单词间打印一个空格
			// transform返回它的第一个参数或其转换之后的形式
			cout << transform(word,trans_map);	//打印输出
			}
	cout << endl;		//完成一行的转换
	}
}

int main(int argc,char *argv[])
{
	if(argc != 3) {
		cout << "命令行参数不对，退出程序!" << endl;
		exit(1);
	}
	
	ifstream map_file(argv[1]);
	if(!map_file) {
		cout << "打开转换规则文件失败!" << endl;
		exit(1);
	}

	ifstream input(argv[2]);
	if(!input) {
		cout << "转换文件打开失败!" << endl;
		exit(1);
	}

	word_transform(map_file,input);
	return 0;
}

