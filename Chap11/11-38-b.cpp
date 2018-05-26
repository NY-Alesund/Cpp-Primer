/*************************************************************************
	> File Name: 11-38-b.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月16日 星期一 10时47分28秒
 ************************************************************************/
/* 用unordered_map重写单词转换程序 */
#include<iostream>
#include<unordered_map>
#include<vector>
#include<fstream>
#include<string>
#include<stdexcept>
#include<sstream>
using namespace std;

unordered_map<string,string> buildMap(ifstream &map_file)
{
	unordered_map<string,string> trans_map;		//保存转换规则
	string key;		//要转换的单词
	string value;	//用来替换的内容

	//读取第一个单词存入key,这一行剩下的内容存入value
	while(map_file >> key && getline(map_file, value))
		if(value.size() > 1)		//检查是否存在转换规则
			trans_map[key] = value.substr(1);	//跳过前导空白
		else
			throw runtime_error("no rule for" + key);
	return trans_map;
}

const string & transform(const string &s,const unordered_map<string,string> &m)
{
	//完成具体转换工作，这个函数是程序的核心
	auto map_it = m.find(s);
	//如果这个单词在转换映射表中
	if(map_it != m.cend())
		return map_it->second;		//用映射表指定内容替换单词
	else
		return s;					//否者原样返回
}

//第一个参数为转换规则文件
//第二个参数是要转换的文本文件
void word_transform(ifstream &map_file,ifstream &input)
{
	auto trans_map = buildMap(map_file);	//保存转换规则

	//调试用：映射表创建好后打印它
	cout << "Here is out transformation map : \n\n";
	for (auto entry : trans_map)
		cout << "key: " << entry.first << "\tvalue: " << entry.second << endl;
	cout << "\n\n";

	//对给定文本进行转换
	string text;		//保存从输入读取的每一行
	while (getline(input,text)) {		//从输入读取一行
		istringstream stream(text);		//读取每个单词
		string word;
		bool firstword = true;			//控制是否打印空格
		while(stream >> word) {
			if(firstword)
				firstword = false;
			else
				cout << " ";			//在单词间打印空格
			cout << transform(word,trans_map);		//打印结果
		}
		cout << endl;
	}
}

int main(int argc,char *argv[])
{
	//打开两个文件并检查是否成功
	if (argc != 3)
		throw runtime_error("wrong number of arguments");

	ifstream map_file(argv[1]);		//打开转换规则文件
	if (!map_file)
		throw runtime_error("no transformation file");

	ifstream input(argv[2]);		//打开要转换的文件
	if(!input)
		throw runtime_error("no input file");

	word_transform(map_file,input);
	return 0;
}

