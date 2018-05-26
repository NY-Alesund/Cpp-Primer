/*************************************************************************
	> File Name: Folder.h
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月18日 星期三 20时50分25秒
 ************************************************************************/


class Folder {
	friend class Message;
	public:
		void addMsg(Message *m) { msgs.insert(m); }
		void remMsg(Message *m) { msgs.erase(m);  }
	private:
		set<Message*> msgs;				//msgs保存文件夹所有消息的指针
}


void Folder::add_to_Messages(const Folder &f)
{
	for (auto msg : f.msgs)
		msg->addFldr(this);							//将这个Folder添加到Message中
}

void Folder::remove_from_Msgs()
{
	while(!msgs.empty())							//将这个Folder从它所有Message中删除
		(*msgs.begin())->remove(*this);
}

//用到两个Message的辅助成员函数
void addFldr(Floder *f)
{
	folders.insert(f);	 			//添加给定Folder
}

void Message::remove(Floder &f)		//删除给定Folder
{
	folders.erase(&f);				//将Folder从此Message中删除
	f.remMsg(this);					//反向：将Message也从Folder中删除
}

//定义拷贝控制成员

//拷贝构造函数
Folder::Folder(const Folder &f) : msgs(f.msgs)
{
	add_to_Messages(f);				//将Folder添加到它所有Message的folders中
}

//析构函数
Folder::~Folder()
{
	remove_from_Msgs();
}

//拷贝赋值运算符
Folder& Folder::operator=(const Folder &f)
{
	remove_from_Msgs();				//从每个Message中删除此Folder
	msgs = f.msgs;					//从右侧运算对象拷贝Message集合
	add_to_Message(f);				//将此Folder添加到每个新Message中
	return *this;
}




