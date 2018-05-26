/*************************************************************************
	> File Name: Message.h
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月18日 星期三 18时33分46秒
 ************************************************************************/


//假定Folder类包含名为addMsg和remMsg的成员，分别完成在给定Folder对象的消息集合中添加和删除Message的工作

class Message {
	friend class Folder;
	public:
		//folder被隐式初始化为空集合
		explicit Message(const std::string &str = "") : contents(str) { }
		
		//拷贝控制成员，用来管理指向本Message的指针
		Message(const Message&);				//拷贝构造函数
		Message& operator=(const Message&);		//拷贝赋值运算符
		~Message();								//析构函数

		//从给定Folder集合中添加/删除本Message
		void save(Folder&);
		void remove(Folder&);

	private:
		std::string contents;					//contents保存实际消息文本
		std::set<Folder*> folders;				//folders是指向Message所在Folder的指针的列表
		
		//拷贝构造函数,拷贝赋值运算符和析构函数所使用的工具函数			
		void add_to_Folders(const Message&);	//将本Message添加到指定参数的Folder中
		void remove_from_Folders();				//从folders中的每个Folder中删除本Message
};

//成员函数save:将本Message存放在给定Folder中
void Message::save(Folder &f)
{
	folders.insert(&f);					//将给定Folder添加到我们的Folder列表中
	f.addMsg(this);						//将本Message添加到f的Message集合中
}

//成员函数remove:删除本Message
void Message::remove(Folder &f)
{
	folders.erase(&f);					//将给定Folder从Folder列表中删除
	f.remMsg(this);						//将本Message从f的Message集合中删除
}



/* add_to_Folders和remove_from_Folders是拷贝构造函数、拷贝赋值运算符和析构函数所使用的工具函数*/
//将本Message添加到指向m的Folder中
void Message::add_to_Folders(const Message &m)
{
	for (auto f : m.folders)			//对每个包含m的Folder
		f->addMsg(this);				//向该Folder添加一个指向本Message的指针
}

//Message的拷贝构造函数拷贝给定对象的数据成员:
Message::Message(const Message &m) : contents(m.contents),folders(m.folders)
{
	add_to_Folders(m);					//将新创建的Message的指针添加到每个包含原Message的Folder中
}

//当一个Message销毁时，从对应的Folder中删除本Message
void Message::remove_from_Folders()
{
	for(auto f : folders)		//对folders中每个指针
		f->remMsg(this);		//从该Folder中删除本Message
}

//析构函数
Message::~Message()
{
	remove_from_Folders();		//调用此函数确保没有任何Folder保存正在销毁的Message的指针
}


//Message的拷贝赋值运算符
Message& Message::operator=(const Message &rhs)
{
	//通过先删除指针再插入它们来处理自赋值情况
	remove_from_Folders();		//删除原来的Folder指针
	contents = rhs.contents;	//从rhs拷贝消息内容
	folders	= rhs.folders;		//从rhs拷贝Folder指针
	add_to_Folders(rhs);		//将本Message添加到那些Folder中
	return *this;
}

//Message的swap函数
void swap(Message &lhs , Message &rhs)
{
	using std::swap;			//在本例中严格来说不需要，但这是一个好习惯
	
	//将每个消息的指针从它所在的Folder中删除
	for (auto f : lhs.folders)
		remMsg(&lhs);
	for (auto f : rhs.folders)
		remMsg(&rhs);

	//交换contents和Folder指针set
	swap(lhs.folders,rhs.folders);		//使用swap(&set,&set)
	swap(lhs.contents,rhs.contents);	//swap(&string,&string)

	//将每个Message的指针添加到它的新Folder中
	for (auto f : lhs.folders)
		f->addMsg(&lhs);
	for (auto f : rhs.folders)
		f->addMsg(&rhs);
}


//从本Message移动Folder指针
void Message::move_Folders(Message *m)
{
	folders = std::move(m->folders);		//使用set的移动赋值运算符
	for (auto f : folders) {		//对每个Folder
		f->remMsg(m);				//从Folder中删除旧Message
		f->addMsg(this);			//将本Message添加到Folder中
	}
	m->folders.clear();				//确保销毁m是无害的
}

//Message的移动构造函数
Message::Message(Message &&m) : contents(std::move(m.contents))
{
	move_Folders(&m);				//移动Message并更新Folder指针
}

//移动赋值运算符
Message& Message::operator=(Message &&rhs)
{
	if (this != &rhs) {				//直接检查自赋值情况
		remove_from_Folders();
		contents = std::move(rhs.contents);		//移动赋值运算符
		move_Folders(&rhs);			//重置Folders指向本Message
	}

	return *this;
}
