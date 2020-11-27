#include<iostream>
using namespace std;
#include<queue>
#include <functional>
#include <vector>

//仿函数类
template <class T>
struct Less
{
	bool operator()(const T& val1,const T& val2)
	{
		return val1 < val2;
	}
};

template <class T>
struct Greater
{
	bool operator()(const T& val1, const T& val2)
	{
		return val1 > val2;
	}
};

template <class T, class Container = vector<T>, class Compare=Less<T>>
class PriorityQueue
{
public:
	void shiftUp(int child)
	{
		int parent = (child - 1) / 2;
		while (child > 0)
		{
			if (_com(_c[parent], _c[child]))
			{
				swap(_c[parent], _c[child]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
				break;
		}
	}

	void push(const T& val)
	{
		_c.push_back(val);
		shiftUp(_c.size() - 1);
	}

	void pop()
	{
		swap(_c[0], _c[_c.size() - 1]);
		_c.pop_back();
		shiftDown(_c[0]);
	}

	T& top()
	{
		return _c.front();
	}

	bool empty()
	{
		return _c.empty();
	}

	size_t size()
	{
		return _c.size();
	}

	void shiftDown(int parent)
	{
		int child = parent * 2 + 1;
		while (child<_c.size())
		{
			if (child+1<_c.size() && _com( _c[child],_c[child+1]))
			{
				child += 1;
			}
			if (_com(_c[parent], _c[child]))
			{
				swap(_c[parent], _c[child]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
				break;
		}
	}

private:
	Container _c;
	Compare _com;
};

//void test()
//{
//	//list不支持随机访问，不能作为优先级队列的底层容器
//	//优先级队列的默认容器：vector->随机访问效率高于双端队列
//	PriorityQueue<int> pq;
//	pq.push(10);
//	pq.push(1);
//	pq.push(4);
//	pq.push(2);
//	pq.push(7);
//	while (!pq.empty())
//	{
//		cout << pq.top() << " ";
//		pq.pop();
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

//struct Time
//{
//	Time(int h, int m, int s)
//		:_h(h)
//		, _m(m)
//		, _s(s)
//	{}
//
//	int _h = 0;
//	int _m = 0;
//	int _s = 0;
//
//	bool operator<(const Time& t)
//	{
//		if (_h < t._h)
//			return true;
//		else if (_h == t._h)
//		{
//			if (_m < t._m)
//				return true;
//			else if (_m == t._m)
//			{
//				if (_s < t._s)
//				{
//					return true;
//				}
//			}
//		}
//		return false;
//	}
//};
//
//ostream& operator<<(ostream& _cout, const Time& t)
//{
//	_cout << t._h << "-" << t._m << "-" << t._s << endl;
//	return _cout;
//}
//
//void test()
//{
//	//建大堆，重载<
//	priority_queue<Time> pq;
//	//建小堆，重载>
//	//priority_queue<Time, vector<Time>, greater<Time>> pq;
//	pq.push(Time(18, 23, 12));
//	pq.push(Time(12, 13, 14));
//	pq.push(Time(15, 18, 25));
//
//	while (!pq.empty())
//	{
//		cout << pq.top() << " ";
//		pq.pop();
//	}
//}

//void test()
//{
//	//默认大堆
//	priority_queue<int> pq;
//	//改成小堆
//	//priority_queue<int, vector<int>, greater<int>> pq;
//	pq.push(1);
//	pq.push(6);
//	pq.push(8);
//	pq.push(4);
//	pq.push(0);
//	pq.push(10);
//	pq.push(7);
//	while (!pq.empty())
//	{
//		cout << pq.top() << " ";
//		pq.pop();
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