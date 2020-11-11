#include<iostream>
using namespace std;
#include<assert.h>

template <class T>
class Vector
{
public:
	Vector()
		:_start(nullptr)
		, _finish(nullptr)
		, _endOfStorage(nullptr)
	{}

	size_t size() const
	{
		return _finish - _start;
	}

	size_t capacity() const
	{
		return _endOfStorage - _start;
	}

	void push_back(const T& val)
	{
		//1.检查容量
		if (_finish == _endOfStorage)
		{
			size_t newCapacity = _start == nullptr?1 : 2 * capacity();
			reserve(newCapacity);
		}
		//2.尾插
		*_finish = val;
		//3.更新size
		++_finish;
		//insert(end(), val);
	}
	void pop_back()
	{
		erase(end() - 1);
	}

	void reserve(size_t n)
	{
		//只增加容量
		if (n > capacity())
		{
			size_t sz = size();
			//1.开空间
			T* tmp = new T[n];
			//2.内容拷贝（浅拷贝）
			//memcpy(tmp, _start, sizeof(T)*size());   //类型为自定义类型时，发生浅拷贝，调用自定义类型析构函数，释放资源，导致资源二次释放
			//执行T类型的赋值操作，进行深拷贝
			for (int i = 0; i < sz; i++)
			{
				tmp[i] = _start[i];
			}
			//3.释放原有空间
			delete[] _start;
			//4.更新成员变量
			_start = tmp;
			_finish = _start + sz;
			_endOfStorage = _start + n;
		}
	}

	T& operator[](size_t pos)
	{
		assert(pos < size());
		return _start[pos];
	}

	const T& operator[](size_t pos) const
	{
		assert(pos < size());
		return _start[pos];
	}

	//vector迭代器：T*
	typedef T* iterator;
	typedef const T* const_iterator;

	iterator begin()
	{
		return _start;
	}

	iterator end()
	{
		return _finish;
	}

	const_iterator begin() const
	{
		return _start;
	}

	const_iterator end() const
	{
		return _finish;
	}

	void resize(size_t n, const T& val = T())
	{
		if (n > capacity())
		{
			reserve(n);
		}
		if (n > size())
		{
			//给新的位置：[size, n) 赋值
			iterator it = end();
			while (it != _start + n)
			{
				*it = val;
				++end;
			}
		}
		_finish = _start + n;
	}

	void insert(iterator pos, const T& val)
	{
		assert(pos >= begin() && pos <= end());
		//获取pos和begin的偏移量
		int offset = pos - _start;
		//检查容量
		if (_finish == _endOfStorage)
		{
			size_t newCapacity = _start == nullptr ? 1 : 2 * capacity();
			reserve(newCapacity);
		}
		//增容会引起迭代器失效，更新pos
		pos = _start + offset;
		//元素移动
		iterator it = end();
		while (it != pos) 
		{
			*it = *(it - 1);
			--it;
		}
		//元素插入
		*pos = val;
		//更新size
		++_finish;
	}

	iterator erase(iterator pos)
	{
		assert(pos >= begin() && pos < end());
		iterator it = pos + 1;
		//移动元素：从前向后
		while (it != end())
		{
			*(it - 1) = *it;
			++it;
		}
		--_finish;
		//返回被删除元素的下一个位置
		return pos;
	}

	~Vector()
	{
		if (_start)
		{
			delete[] _start;
			_start = _finish = _endOfStorage = nullptr;
		}
	}

private:
	T* _start; //首元素地址
	T* _finish; //最后一个元素的下一个地址（最后一个元素的尾地址）
	T* _endOfStorage; //空间的尾地址
};

void test()
{
	//删除内容为1的元素
	Vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(3);
	v.push_back(7);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	Vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it == 1)
			it = v.erase(it);
		else
			++it;
	}
}

int main()
{
	test();
	system("pause");
	return 0;
}