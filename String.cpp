#include<iostream>
using namespace std;
#include<string>
#include<assert.h>
//#pragma warning(disable:4996)
//
class String
{
public:
	//����
	String(const char* str = "")
	{
		_size = strlen(str);
		_capacity = _size;
		_ptr = new char[_capacity + 1];
		strcpy(_ptr, str);
	}

	/*string(const string& str)
		:_ptr(new char[strlen(str._ptr) + 1])
		,_size(str._size)
		, _capacity(str._capacity)
	{
		strcpy(_ptr, str._ptr);
	}*/

	//��������
	String(const String& str)
		:_ptr(nullptr)
		, _size(0)
		, _capacity(0)
	{
		String tmp(str._ptr);
		Swap(tmp);
	}

	//��ֵ
	String operator=(String str)
	{
		Swap(str);
		return *this;
	}

	void Swap(String& str)
	{
		swap(_ptr, str._ptr);
		swap(_capacity, str._capacity);
		swap(_size, str._size);
	}

	//����
	~String()
	{
		if (_ptr)
		{
			delete[] _ptr;
			_ptr = nullptr;
		}
	}

	void push_back(const char ch)
	{
		//�ж�����
		if (_size == _capacity)
		{
			//����
			size_t newCapacity = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newCapacity);
		}
		//����
		_ptr[_size++] = ch;
		_ptr[_size] = '\0';
	}

	void reserve(size_t n)
	{
		if (n > _capacity)
		{
			//���¿ռ�
			char* tmp = new char[n + 1];
			//����ԭʼ�ռ�����
			strcpy(tmp, _ptr);
			//�ͷ�ԭ�пռ�
			delete[] _ptr;
			_ptr = tmp;
			//��������
			_capacity = n;
		}
	}

	size_t size()
	{
		return _size;
	}

	char& operator[](size_t pos)
	{
		assert(pos < _size);
		return _ptr[pos];
	}

	const char& operator[](size_t pos) const
	{
		assert(pos < _size);
		return _ptr[pos];
	}

	//������:��������Ԫ�ص�һ�ֻ���
	//������������ָ�룩���ƶ��������á��ж�
	//string��������ʵ�֣�char*
	typedef char* iterator;
	typedef const char* const_iterator;

	//��һ��Ԫ��
	iterator begin()
	{
		return _ptr;
	}

	//���һ��Ԫ�ص���һ��λ��
	iterator end()
	{
		return _ptr + _size;
	}

	const_iterator begin() const
	{
		return _ptr;
	}

	const_iterator end()const
	{
		return _ptr + _size;
	}

	void resize(size_t sz, char ch = '\0')
	{
		if (sz > _capacity)
		{
			//����
			reverse(sz);
		}
		if (sz > _size)
		{
			//��ֵ
			memset(_ptr + _size, ch, sz - _size);
		}
		_size = sz;
		_ptr[_size] = '\0';
	}

	void Append(const char* str)
	{
		int len = strlen(str);
		if (_size + len > _capacity)
		{
			reverse(_size + len);
		}

		//β���ַ���
		strcpy(_ptr + _size, str);
		_size += len;
	}

	String& operator+=(const char& ch)
	{
		push_back(ch);
		return *this;
	}

	String& operator+=(const char* str)
	{
		Append(str);
		return *this;
	}

	void insert(size_t pos, const char& ch)
	{
		//pos = 0,ͷ��
		//pos = _size,β��
		//0 <= pos <= _size
		assert(pos <= _size);
		if (_size == _capacity)
		{
			size_t newCapacity = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newCapacity);
		}
		size_t end = _size;
		while (end > pos)
		{
			_ptr[end] = _ptr[end - 1];
			--end;
		}
		_ptr[pos] = ch;
		_ptr[++_size] = '\0';
	}

	void insert(size_t pos, const char* str)
	{
		assert(pos <= _size);
		int len = strlen(str);
		if (_size + len > _capacity)
		{
			reverse(_size + len);
		}
		size_t end = _size + len;
		while (end > pos + len - 1)
		{
			_ptr[end] = _ptr[end - len];
			--end;
		}
		memcpy(_ptr + pos, str, len*sizeof(char));
		_size += len;
	}

	void erase(size_t pos, size_t len)
	{
		assert(pos < _size);
		if (pos + len >= _size)
		{
			_size = pos;
			_ptr[_size] = '\0';
			return;
		}
		size_t start = pos + len;
		while (start < _size)
		{
			_ptr[start - len] = _ptr[start];
			++start;
			//_ptr[pos++] = _ptr[start++];
		}
		_size -= len;
		_ptr[_size] = '\0';
	}

	size_t find(const char& ch, size_t pos = 0)
	{
		for (size_t i = pos; i < _size; i++)
		{
			if (_ptr[i] == ch)
				return i;
		}
		return npos;
	}

	size_t find(const char* str, size_t pos = 0)
	{
		char* start = strstr(_ptr + pos, str);
		if (start)
		{
			return start - _ptr;
		}
		return npos;
	}

	friend ostream& operator<<(ostream& _cout, const String& str);
	friend istream& operator>>(istream& _cin, String& str);

private:
	char* _ptr;
	size_t _size;
	size_t _capacity;
	static const size_t npos;
};

const size_t string::npos = -1;

ostream& operator<<(ostream& _cout, const String& str)
{
	for (size_t i = 0; i < str._size; i++)
	{
		_cout << str[i];
	}
	return _cout;
}

istream& operator>>(istream& _cin, String& str)
{
	char ch;
	while (ch = getchar() != EOF)
	{
		if (ch == '\n')
			return _cin;
		str += ch;
	}
	return _cin;
}

void test3()
{
	String str2 = "123456";
	//��Χfor�������ᷭ��ɵ������ı�����ʽ
	for (auto ch:str2)
	{
		cout << ch << " ";
	}
	cout << endl;
}

void test2()
{
	String str1 = "123456";
	String::iterator it = str1.begin();
	while (it != str1.end)
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test()
{
	String str = "12345";
	for (size_t i = 0; i < str.size(); i++)
	{
		cout << str[i] << " ";
	}
	cout << endl;
}

int main()
{
	test();
	return 0;
}











//class String
//{
//public:
//	String(char* ptr = "")
//		:_ptr(new char[strlen(ptr)+1])
//	{
//		strcpy(_ptr, ptr);
//	}
//	
//	//������������������+�������Դ
//	String(const String& str)
//		:_ptr(new char[strlen(str._ptr) + 1])
//	{
//		strcpy(_ptr, str._ptr);
//	}
//
//	String& operator=(const String& str)
//	{
//		if (this != &str)
//		{
//			char* tmp = new char[strlen(str._ptr) + 1];
//			strcpy(tmp, str._ptr);
//			delete[] _ptr;
//			_ptr = tmp;
//		}
//		return *this;
//	}
//
//	const char* c_str() const
//	{
//		return _ptr;
//	}
//
//	~String()
//	{
//		if (_ptr)
//		{
//			delete[] _ptr;
//			_ptr = nullptr;
//		}
//	}
//private:
//	char* _ptr;
//};
//void test()
//{
//	String s("123");
//	//��������
//	String s2 = s;
//	//��ֵ
//	s = s2;
//}
//
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}