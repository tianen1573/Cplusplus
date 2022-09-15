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
	Date(int year = 2022, int month = 7, int day = 27)//����
	{
		cout << "����\n";
		this->_year = year;
		(*this)._month = month;
		_day = day;

		assert(IsLegal());//�жϹ���Ķ����Ƿ�Ϸ�
	}
	Date(const Date& d)//��������----���Ա����,���������ʵ�����
	{
		cout << "��������\n";
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	~Date()
	{
		cout << "����\n";
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


	bool IsLegal()//�����Ƿ�Ϸ�
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

friend ostream& operator<<(ostream& _cout, const Date& d);//�������������, ������
friend istream& operator>>(istream& _cin, Date& d);
};

