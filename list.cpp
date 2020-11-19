//#include<list>
//#include<string>
//#include<iostream>
//using namespace std;
//
//template <class T>
//struct ListNode
//{
//	T _data;
//	ListNode<T*> _next = nullptr;
//	ListNode<T*> _prev = nullptr;
//
//	ListNode(const T& = T())
//		:_data(val)
//		, _next(nullptr)
//		, _prev(nullptr)
//	{}
//};
//
//template <class T>
//class List
//{
//public:
//	typedef ListNode<T> Node;
//	//实现不了迭代器
//	//typedef T* iterator;
//	//typedef Node* iterator;
//	typedef ListIterator<T> iterator;
//	List()
//	{
//		//空的带头双向循环链表
//		_header = new Node;
//		_header->_next = _header->_prev = _header;
//	}
//
//	iterator begin()
//	{
//		return iterator(_header->_next);
//	}
//
//	iterator end()
//	{
//		return iterstor(_header);
//	}
//
//	void push_back(const T& val)
//	{
//		Node* cur = new Node(val);
//		Node* tail = _header->_prev;
//		tail->_prev = cur;
//		cur->_prev = tail;
//		cur->_next = _header;
//		_header->_prev = cur;
//	}
//
//private:
//	Node* _header;
//};
//
//template<class T>
//struct ListIterator
//{
//	typedef ListNode<T> Node;
//	Node* _node;
//	ListIteraror(Node* node)
//		:_node(node)
//	{}
//	//让迭代器类型支持解引用操作：重载*运算符
//	T& operator*()
//	{
//		return _node->_data;
//	}
//
//	ListIterator<T>& operator++()
//	{
//		_node = _node->_next;
//		return *this;
//	}
//	bool operator!=(const ListIteraror<T>& it)
//	{
//		//判断两个数据的位置是否相同
//		return _node != it._node;
//	}
//	T* operator->()
//	{
//		return *_node->_data;
//	}
//};




















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