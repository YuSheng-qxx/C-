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
		//1.�������
		if (_finish == _endOfStorage)
		{
			size_t newCapacity = _start == nullptr?1 : 2 * capacity();
			reserve(newCapacity);
		}
		//2.β��
		*_finish = val;
		//3.����size
		++_finish;
		//insert(end(), val);
	}
	void pop_back()
	{
		erase(end() - 1);
	}

	void reserve(size_t n)
	{
		//ֻ��������
		if (n > capacity())
		{
			size_t sz = size();
			//1.���ռ�
			T* tmp = new T[n];
			//2.���ݿ�����ǳ������
			//memcpy(tmp, _start, sizeof(T)*size());   //����Ϊ�Զ�������ʱ������ǳ�����������Զ������������������ͷ���Դ��������Դ�����ͷ�
			//ִ��T���͵ĸ�ֵ�������������
			for (int i = 0; i < sz; i++)
			{
				tmp[i] = _start[i];
			}
			//3.�ͷ�ԭ�пռ�
			delete[] _start;
			//4.���³�Ա����
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

	//vector��������T*
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
			//���µ�λ�ã�[size, n) ��ֵ
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
		//��ȡpos��begin��ƫ����
		int offset = pos - _start;
		//�������
		if (_finish == _endOfStorage)
		{
			size_t newCapacity = _start == nullptr ? 1 : 2 * capacity();
			reserve(newCapacity);
		}
		//���ݻ����������ʧЧ������pos
		pos = _start + offset;
		//Ԫ���ƶ�
		iterator it = end();
		while (it != pos) 
		{
			*it = *(it - 1);
			--it;
		}
		//Ԫ�ز���
		*pos = val;
		//����size
		++_finish;
	}

	iterator erase(iterator pos)
	{
		assert(pos >= begin() && pos < end());
		iterator it = pos + 1;
		//�ƶ�Ԫ�أ���ǰ���
		while (it != end())
		{
			*(it - 1) = *it;
			++it;
		}
		--_finish;
		//���ر�ɾ��Ԫ�ص���һ��λ��
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
	T* _start; //��Ԫ�ص�ַ
	T* _finish; //���һ��Ԫ�ص���һ����ַ�����һ��Ԫ�ص�β��ַ��
	T* _endOfStorage; //�ռ��β��ַ
};

void test()
{
	//ɾ������Ϊ1��Ԫ��
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