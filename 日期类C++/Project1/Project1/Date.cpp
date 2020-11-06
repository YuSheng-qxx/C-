#include<iostream>
using namespace std;
#include<string.h>
#pragma warning(disable:4996)

class Date
{
public:
	int getDay(int year, int month)
	{
		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[month];
		if ((month == 2) && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		{
			day += 1;
		}
		return day;
	}
	Date(int year = 1900, int month = 1, int day = 1)
	{
		if (year <= 0 || month <= 0 || month > 12 || day <= 0 || day > getDay(year, month))
		{
			cout << "日期无效" << endl;
			cout << "日期重置为：1900-1-1" << endl;
			_year = 1900;
			_month = 1;
			_day = 1;
		}
		else
		{
			_year = year;
			_month = month;
			_day = day;
		}
	}
	Date operator - (int day)
	{
		Date _d(*this);//拷贝构造
		return _d -= day;
	}
	Date operator + (int day)
	{
		Date _d(*this);
		return _d += day;
	}
	//前置++
	Date& operator ++()
	{
		return *this += 1;
	}
	//后置++
	Date operator ++(int)
	{
		Date _d(*this);
		*this += 1;
		return _d;
	}

	//前置--
	Date& operator--()
	{
		return *this -= 1;
	}

	//后置--
	Date operator--(int)
	{
		Date tmp(*this);
		*this -= 1;
		return tmp;
	}

	Date& operator += (int day)
	{
		if (day < 0)
		{
			return *this -= -day;
		}
		_day += day;
		while (_day > getDay(_year, _month))
		{
			_day -= getDay(_year, _month);
			_month++;
			if (_month == 13)
			{
				_month = 1;
				++_year;
			}
		}
		return *this;
	}
	Date& operator -= (int day)
	{
		if (day < 0)
		{
			return *this += -day;
		}
		_day -= day;
		while (_day <= 0)
		{
			_month--;
			if (_month == 0)
			{
				_month = 12;
				_year--;
			}
			_day += getDay(_year, _month);
		}
		return *this;
	}
	//<
	bool operator<(const Date& d)
	{
		if (_year < d._year)
			return true;
		else if (_year == d._year)
		{
			if (_month < d._month)
				return true;
			else if (_month == d._month)
			{
				if (_day < d._day)
					return true;
			}
		}
		return false;
	}

	bool operator==(const Date& d)
	{
		return _year == d._year
			&&_month == d._month
			&&_day == d._day;
	}
	bool operator<=(const Date& d)
	{
		if (*this<d || *this == d)
			return true;
		else
			return false;
	}
	bool operator!=(const Date& d)
	{
		return !(*this == d);
		/*if (!(*this == d))
		return true;
		return false;*/
	}
	bool operator>=(const Date& d)
	{
		if (!(*this < d))
			return true;
		return false;
	}
	bool operator>(const Date& d)
	{
		if (!(*this<d || *this == d))
			return true;
		return false;
	}

	int operator-(const Date& d)
	{
		Date max = *this;
		Date min = d;
		int flag = 1;
		if (min>max)
		{
			min = *this;
			max = d;
			flag = -1;
		}
		int day = 0;
		while (min < max)
		{
			++day;
			++min;
		}
		return day * flag;
	}
private:
	int _year;
	int _month;
	int _day;
};

void test()
{
	Date d1(2020, 1, 2);
	Date d2 = d1;
}

int main()
{
	test();
	system("pause");
	return 0;
}