#pragma once

#include <iostream>
#include <assert.h>
using namespace std;

int GetMonthDays(int year, int month);

class Date
{

	

public:
	static void aaa()
	{
		cout << 11;
	}
	Date(int year = 2022, int month = 7, int day = 27)//构造
	{
		cout << "构造\n";
		this->_year = year;
		(*this)._month = month;
		_day = day;

		assert(IsLegal());//判断构造的对象是否合法
	}
	Date(const Date& d)//拷贝构造----类成员函数,编译器会适当内联
	{
		cout << "拷贝构造\n";
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	~Date()
	{
		cout << "析构\n";
	}
	Date& operator=(const Date& d);

	Date& operator+=(int day);
	Date operator+(int day) const;
	Date& operator-=(int day);
	Date operator-(int day) const;
	int operator-(const Date& d) const;
	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);
	bool operator==(const Date& d) const;
	bool operator>(const Date& d) const;
	bool operator>=(const Date& d) const;
	bool operator<(const Date& d) const;
	bool operator<=(const Date& d) const;
	bool operator!=(const Date& d) const;


	bool IsLegal()//日期是否合法
	{
		if (_month < 1 || _month > 12) return false;
		if (_day < 1 || _day > GetMonthDays(_year, _month)) return false;

		return true;
	}
	void HowManyDays();

private:
	int _year = 2022;
	int _month = 7;
	int _day = 27;

friend ostream& operator<<(ostream& _cout, const Date& d);//返回输出流引用, 多次输出
friend istream& operator>>(istream& _cin, Date& d);
};

