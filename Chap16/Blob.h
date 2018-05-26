/*************************************************************************
	> File Name: Blob.h
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月22日 星期日 15时03分44秒
 ************************************************************************/

/* 模板有一个名为T的模板类型参数，用来表示Blob保存的元素的类型 */
template <typename T> class Blob {
	public:
		typedef T value_type;
		typedef typename std::vector<T>::size_type size_type;
		//构造函数
		Blob();
		Blob(std::initializer_list<T> il);
		//Blob中的元素数目
		size_type size() const { return data->size(); }
		bool empty() const { return data->empty(); }
		//添加和删除元素
		void push_back(const T &t) { data->push_back(t); }
		//移动版本
		void push_back(T &&) { data->push_back(std::move(t)); }
		void pop_back();
		//元素访问
		T& back();
		T& operator[](size_type i);
	private:
		std::shared_ptr<std::vector<T>> data;
		//若data[i]无效，则抛出msg
		void check(size_type i, const std::string &msg) const;
};

/* 构造函数 */
template <typename T>
Blob<T>::Blob(): data(std::make_shared<std::vector<T>>()) { }

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il)
			: data(std::make_shared<std::vector<T>> (il))

/* 定义check成员，检查一个给定的索引*/
template <typename T>
void Blob<T>::check(size_type i,const std::string &msg) const
{
	if(i >= data->size())
		throw std::out_of_range(msg);
}

/* back函数 */
template <typename T>
T& Blob<T>::back()
{
	check(0,"back on empty Blob");
	return data->back();
}

/* 定义下标运算符 */
template <typename T>
T& Blob<T> ::operator[](size_type i)
{
	//如果i太大，check会抛出异常，阻止访问一个不存在的元素
	check(i,"subscript out of range");
	return (*data)[i];
}

/* pop_back函数 */
template <typename T> void Blob<T>::pop_back()
{
	check(0,"pop_back on empty Blob");
	data->pop_back();
}



