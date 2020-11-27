#include<stack>
#include<vector>
using namespace std;
#include<iostream>
//
template <class T, class container=deque<T>>
class Stack
{
public:
	void push(const T& val)
	{
		_v.push_back(val);
	}

	void pop()
	{
		_v.pop_back();
	}

	T& top()
	{
		return _v.back();
	}

	bool empty()
	{
		return _v.empty();
	}

	size_t size()
	{
		return _v.size();
	}

private:
	container _v;
};

//void test()
//{
//	Stack<int> st;
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	st.push(4);
//	while (!st.empty())
//	{
//		cout << st.top() << " ";
//		st.pop();
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




//最小栈
//class MinStack
//{
//	stack<int> _stack;
//	stack<int> _minstack;
//	void push(int x)
//	{
//		_stack.push(x);
//		if (_minstack.empty() || x <= _minstack.top())
//		{
//			_minstack.push(x);
//		}
//	}
//
//	void pop()
//	{
//		if (!_minstack.empty() && _stack.top() == _minstack.top())
//		{
//			_minstack.pop();
//		}
//		_stack.pop();
//	}
//
//	int top()
//	{
//		return _stack.top();
//	}
//
//	int getMin()
//	{
//		return _minstack.top();
//	}
//};



//栈接口测试
//void test()
//{
//	stack<int> st;
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	st.push(4);
//	st.push(5);
//	cout << st.size() << endl;
//	while (!st.empty())
//	{
//		cout << st.top() << " ";
//		st.pop();
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