/*************************************************************************
	> File Name: biggies.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月12日 星期四 10时59分56秒
 ************************************************************************/

using namespace std;

void biggies(vector<string> &word, vector<string>::size_type sz)
{
	elimDups(words);		//将words按字典排序，删除重复单词
	
	//按长度排序，长度相同的单词维持字典排序
	stable_sort(words.begin(),words.end(), [](const string &a,const string &b) {return a.size() < b.size();});
	
	//获取一个迭代器，指向第一个满足size() >= sz的元素
	auto wc = find_if(words.begin(),words.end(),[sz](const string &a) { return a.size() >= sz};);

	//计算size>=sz元素的数目
	auto count = words.end() - wc;
	cout << count << " " << make_plural(count,"word","s") << " of length" << sz << " or length" << endl;

	//打印长度大于等于给定值的单词，每个单词后面接一个空格
	for_each(wc,words.end(),[](const string &s) {cout << s << " ";});
	cout << endl;
}
