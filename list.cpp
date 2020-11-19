#include<list>
#include<string>
#include<iostream>
using namespace std;

template <class T>
struct ListNode
{
	T _data;
	ListNode<T*> _next = nullptr;
	ListNode<T*> _prev = nullptr;

	ListNode(const T& = T())
		:_data(val)
		, _next(nullptr)
		, _prev(nullptr)
	{}
};

template <class T>
class List
{
public:
	typedef ListNode<T> Node;
	//实现不了迭代器
	//typedef T* iterator;
	//typedef Node* iterator;
	typedef ListIterator<T, T&, T*> iterator;
	typedef ListIterator <T, const T&, const T*> const_iterator;

	List()
	{
		//空的带头双向循环链表
		_header = new Node;
		_header->_next = _header->_prev = _header;
	}

	iterator begin()
	{
		return iterator(_header->_next);
	}

	iterator end()
	{
		return iterstor(_header);
	}

	const_iterator begin()
	{
		return iterator(_header->_next);
	}

	const_iterator end()
	{
		return iterstor(_header);
	}

	void push_back(const T& val)
	{
		/*Node* cur = new Node(val);
		Node* tail = _header->_prev;

		tail->_prev = cur;
		cur->_prev = tail;

		cur->_next = _header;
		_header->_prev = cur;*/
		insert(end(), val);
	}

	void insert(iterator pos, const T& val)
	{
		Node* cur = pos._node;
		Node* prev = cur->_prev;

		Node* newNode = new Node(val);

		prev->_next = newNode;
		newNode->_prev = prev;

		newNode->_next = cur;
		cur->_prev = newNode;
	}

	void push_front(const T& val)
	{
		insert(begin(), val);
	}

	//返回值：被删除数据的下一个位置
	iterator erase(iterator pos)
	{
		//不能删除end迭代器指向的数据
		if (pos != end())
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;

			prev->_next = next;
			next->_prev = prev;

			delete cur;
			//创建指向下一个节点的迭代器
			return iterator(next);
		}
		return pos;
	}

	void pop_back()
	{
		erase(--end());
	}

	void pop_front()
	{
		erase(begin());
	}

	List(const List<T>& lst)
	{
		//深拷贝
		_header = new Node;
		_header->_next = _header->_prev = _header;
		//插入lst中的每个数据
		for (const auto& e : lst)
		{
			push_back(e);
		}
	}

	//List<T>& operator=(const List<T>& lst)
	//{
	//	if (this != &lst)
	//	{
	//		//清空数据
	//		clear();
	//		for (const auto& e : lst)
	//		{
	//			puah_back(e);
	//		}
	//	}
	//	return *this;
	//}

	List<T>& operator=(List<T> lst)
	{
		swap(_header, lst._header);
		return *this;
	}

	void clear()
	{
		//清空有效节点
		Node* cur = _header->_next;
		while (cur != _header)
		{
			Node* next = cur->_next;
			delete cur;
			cur = next;
		}
		//恢复循环结构
		_header->_next = _header->_prev = _header;
	}

	~List()
	{
		clear();
		delete _header;
	}

	void print()
	{
		Node* cur = _header->_next;
		while (cur != _header)
		{
			cout << cur->_data << " ";
			cur = cur->_next;
		}
		cout << endl;
	}

private:
	Node* _header;
};

template<class T, class Ref, class Ptr>
struct ListIterator
{
	typedef ListNode<T>* Node;
	typedef ListIterator<T, Ref, Ptr> Self;
	Node* _node;

	ListIteraror(Node* node)
		:_node(node)
	{}

	//让迭代器类型支持解引用操作：重载*运算符
	Ref operator*()
	{
		return _node->_data;
	}

	Self& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	//后置++
	Self operator++(int)
	{
		ListIteraror<T> ret(*this);
		_node = _node->_next;
		//返回未修改之前的迭代器
		return ret;
	}

	Self& operator--()
	{
		_node = _node->perv;
		return *this;
	}

	//后置--
	Self operator--(int)
	{
		ListIteraror<T> ret(*this);
		_node = _node->perv;
		return ret;
	}

	bool operator!=(const ListIteraror<T>& it)
	{
		//判断两个数据的位置是否相同
		return _node != it._node;
	}
	Ptr operator->()
	{
		return &_node->_data;
	}
};

template <class T>
void printList(const List<T>& lst)
{
	List<T>::iterator it = lst.begin();
	while (it != end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

template <class T>
void printFor(const List<T>& lst)
{
	for (const auto& e : lst)
	{
		cout << e << " ";
	}
	cout << endl;
}



















//template <class T>
//void printList(const list<T>& lst)
//{
//	list<int>::const_iterator it = lst.begin();
//	while (it != lst.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}
//template <class T>
//void printListFor(const list<T>& lst)
//{
//	for (const auto& e : lst)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//
//void test()
//{
//	list<int> lst;
//	list<int> lst2;
//	lst.push_back(1);
//	lst.push_back(2);
//	lst.push_back(3);
//	lst2.push_back(4);
//	lst2.push_back(1);
//	lst2.push_back(13);
//	lst2.sort();
//	lst.merge(lst2);//lst:1 1 2 3 4 13   lst2:空
//
//	lst.reverse();
//}

//void test()
//{
//	list<int> lst;
//	lst.push_back(1);
//	lst.push_back(3);
//	lst.push_back(2);
//	lst.push_back(1);
//	lst.push_back(1);
//	lst.sort();
//	lst.unique();//首先需要list中的元素有序
//}

//void test()
//{
//	list<int> lst;
//	list<int> lst2;
//	lst.push_back(1);
//	lst.push_back(2);
//	lst.push_back(3);
//
//	lst2.push_back(4);
//	lst2.push_back(5);
//	lst.splice(lst.begin(), lst2);  //lst:4 5 1 2 3   lst2中的内容直接拼接到lst中，lst2为空	
//	lst2.splice(lst2.end(), lst, lst.begin()); //lst2:4   lst:5 1 2 3
//	lst2.splice(lst2.end(), lst, ++lst.begin(), --lst.end());//lst2:4 1 2   lst:5 3
//
//	lst2.remove(4);//lst2:1 2
//	lst2.remove(100);//lst2:1 2
//}

//void test()
//{
//	list<int> lst;
//	cout << lst.size() << endl;
//	lst.resize(2);
//	printList(lst);
//	lst.resize(5, 5);
//	printList(lst);
//	list<string> lst2;
//	lst.resize(2);
//	printList(lst2);
//	lst2.resize(5, "12");
//	printList(lst2);
//}

//void test()
//{
//	list<int> lst;
//	list<int> lst2(3, 10);
//	list<int> lst3(lst2.begin(), lst2.end());
//	list<int> copy(lst3);
//	list<int>::iterator it = lst2.begin();
//	while (it != lst2.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	list<int> lst4;
//	lst4.push_back(1);
//	lst4.push_back(2);
//	lst4.push_back(3);
//	lst4.push_back(4);
//	list<int>::reverse_iterator it2 = lst4.rbegin();
//	while (it2 != lst2.rend())
//	{
//		cout << *it2 << " ";
//		++it2;
//	}
//	cout << endl;
//
//}