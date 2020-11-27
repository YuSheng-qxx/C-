#include<queue>
#include<list>
#include<iostream>
using namespace std;

template <class T, class container=deque<T>>
class Queue
{
public:
	void push(const T& val)
	{
		_lst.push_back(val);
	}

	void pop()
	{
		_lst.pop_front();
	}

	T& front()
	{
		return _lst.front();
	}

	bool empty()
	{
		return _lst.empty();
	}

	T& back()
	{
		return _lst.back();
	}

	size_t size()
	{
		return _lst.size();
	}
private:
	container _lst;
};
//
//void test()
//{
//	Queue<int> q;
//	q.push(1);
//	q.push(2);
//	q.push(3);
//	q.push(4);
//	cout << q.size() << endl;
//	while (!q.empty())
//	{
//		cout << q.front() << " ";
//		q.pop();
//	}
//	cout << endl;
//}
//
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}