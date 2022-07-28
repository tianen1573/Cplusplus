#include "Date.h"


int GetMonthDays(int year, int month)
{
	static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day = days[month];
	if ((month == 2)
		&& ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))//闰年2月
		day++;

	return day;
}

ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << '-' << d._month << '-' << d._day;

	return _cout;
}
istream& operator>>(istream& _cin, Date& d)
{
	_cin >> d._year;
	_cin >> d._month;
	_cin >> d._day;

	assert(d.IsLegal());//判断对象是否合法

	return _cin;
}
Date& Date::operator=(const Date& d)//赋值运算符重载, 返回当前对象引用, 便于多次赋值
{
	cout << "=" << endl;
	_year = d._year;
	_month = d._month;
	_day = d._day;

	return *this;//this出了函数仍然存在, 可返回引用
}
Date& Date::operator+=(int day)
{
	(*this)._day += day;


	while ((*this)._day > GetMonthDays((*this)._year, (*this)._month))
	{
		(*this)._day -= GetMonthDays((*this)._year, (*this)._month);
		(*this)._month++;
		if ((*this)._month > 12)
		{
			(*this)._year++;
			(*this)._month = 1;
		}
	}

	return (*this);
}
Date Date::operator+(int day) const
{
	Date tmp(*this);

	tmp._day += day;

	while (tmp._day > GetMonthDays(tmp._year, tmp._month))
	{
		tmp._day -= GetMonthDays(tmp._year, tmp._month);
		tmp._month++;
		if (tmp._month > 12)
		{
			tmp._year++;
			tmp._month = 1;
		}
	}

	return tmp;
		
}
Date& Date::operator-=(int day)
{
	(*this)._day -= day;


	while ((*this)._day <= 0)
	{
		(*this)._month--;
		if ((*this)._month == 0)
		{
			(*this)._year--;
			(*this)._month = 12;
		}
		(*this)._day += GetMonthDays((*this)._year, (*this)._month);
	}

	return (*this);
}
Date Date::operator-(int day) const 
{
	Date tmp(*this);

	tmp._day -= day;


	while (tmp._day <= 0)
	{
		tmp._month--;
		if (tmp._month == 0)
		{
			tmp._year--;
			tmp._month = 12;
		}
		tmp._day += GetMonthDays(tmp._year, tmp._month);
	}

	return tmp;
}
int Date::operator-(const Date& d) const
{
	if (*this == d) return 0;

	Date Min = *this;
	Date Max = d;
	int flag = -1;
	if (*this > d)
	{
		Min = d;
		Max = *this;
		flag = 1;
	}
	int cnt = 1;
	while ((Min += 1) != Max) cnt++;

	return cnt * flag;

}
Date& Date::operator++()
{
	return (*this) += 1;
}
Date Date::operator++(int)
{
	Date tmp(*this);

	(*this) += 1;

	return tmp;
}
Date& Date::operator--()
{
	return (*this) -= 1;
}
Date Date::operator--(int)
{
	Date tmp(*this);

	(*this) -= 1;

	return tmp;
}
bool Date::operator==(const Date& d) const
{
	return this->_year == d._year
		&& this->_month == d._month
		&& this->_day == d._day;
}
bool Date::operator>(const Date& d) const
{
	if (this->_year != d._year) return this->_year > d._year;
	if (this->_month != d._month) return this->_month > d._month;
	if (this->_day != d._day) return this->_day > d._day;

	return false;
}
bool Date::operator>=(const Date& d) const
{
	return *this > d || *this == d;
}
bool Date::operator<(const Date& d) const
{
	return !(*this >= d);
}
bool Date::operator<=(const Date& d) const
{
	return !(*this > d);
}
bool Date::operator!=(const Date& d) const
{
	return !(*this == d);
}

void Date::HowManyDays()
{
	int sum_day = 0;
	int days[] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
	if (1 == _month)
	{
		sum_day = _day;
	}
	else
	{
		sum_day = days[_month - 2] + _day;
	}
	if (((_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0) && _month > 2)
	{
		sum_day += 1;
	}
	printf("%d\n", sum_day);
	return;
}
