#define _CRT_SECURE_NO_WARNINGS 1

#include "myVector.h"

#include<vector>

void Test1()
{
	vector<int> v1;
	vector<int> v2(10, 5);

	int array[] = { 1,2,3,4,5 };
	vector<int> v3(array, array + sizeof(array) / sizeof(array[0]));

	vector<int> v4(v3);

	for (size_t i = 0; i < v2.size(); ++i)
	{
		cout << v2[i] << " ";
	}
	cout << endl;

	auto it = v3.begin();
	while (it != v3.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : v4)
	{
		cout << e << " ";
	}
	cout << endl;
}

void Test2()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	cout << v.front() << endl;
	cout << v.back() << endl;
	cout << v[0] << endl;
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.pop_back();
	v.pop_back();
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.insert(v.begin(), 0);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.erase(v.begin() + 1);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

int main()
{
	/*qlz::Test1();
	Test1();*/

	qlz::Test2();
	Test2();

	/*qlz::Test3();*/

	return 0;
}
