#define _CRT_SECURE_NO_WARNINGS 1

#include "myList.h"


//struct type1 {
//	int val = 0;
//	int ele = 0;
//};
//
//struct type2 {
//	type1 _str;
//	int val = 1;
//};

template<class T>
void PrintList(const qlz::list<T>& l)
{
	auto it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		++it;
	}

	cout << endl;
}

// 测试List的构造
void TestqlzList1()
{
	qlz::list<int> l1;
	qlz::list<int> l2(10, 5);
	PrintList(l2);

	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	qlz::list<int> l3(array, array + sizeof(array) / sizeof(array[0]));
	PrintList(l3);

	qlz::list<int> l4(l3);
	PrintList(l4);

	l1 = l4;
	PrintList(l1);
}

// PushBack()/PopBack()/PushFront()/PopFront()
void TestqlzList2()
{
	// 测试PushBack与PopBack
	qlz::list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	PrintList(l);

	l.pop_back();
	l.pop_back();
	PrintList(l);

	l.pop_back();
	cout << l.size() << endl;

	// 测试PushFront与PopFront
	l.push_front(1);
	l.push_front(2);
	l.push_front(3);
	PrintList(l);

	l.pop_front();
	l.pop_front();
	PrintList(l);

	l.pop_front();
	cout << l.size() << endl;
}

// 测试insert和erase
void TestqlzList3()
{
	int array[] = { 1, 2, 3, 4, 5 };
	qlz::list<int> l(array, array + sizeof(array) / sizeof(array[0]));

	auto pos = l.begin();
	l.insert(l.begin(), 0);
	PrintList(l);

	++pos;
	l.insert(pos, 2);
	PrintList(l);

	l.erase(l.begin());
	l.erase(pos);
	PrintList(l);

	// pos指向的节点已经被删除，pos迭代器失效
	cout << *pos << endl;

	auto it = l.begin();
	while (it != l.end())
	{
		it = l.erase(it);
	}
	cout << l.size() << endl;
}

// 测试反向迭代器
void TestqlzList4()
{
	int array[] = { 1, 2, 3, 4, 5 };
	qlz::list<int> l(array, array + sizeof(array) / sizeof(array[0]));

	auto rit = l.rbegin();
	while (rit != l.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	const qlz::list<int> cl(l);
	auto crit = l.rbegin();
	while (crit != l.rend())
	{
		cout << *crit << " ";
		++crit;
	}
	cout << endl;
}


int main()
{
	/*type2 _str1;

	list<type1> list1;

	list1.push_back({ 1, 2 });
	list1.push_back({ 2, 3 });
	list1.push_back({ 3, 4 });

	auto it = list1.begin();

	cout << it->ele << endl;

	vector<type1> vec1;

	vec1.push_back({ 1, 2 });
	vec1.push_back({ 2, 3 });
	vec1.push_back({ 3, 4 });

	auto vecit = vec1.begin();

	cout << vecit->ele << endl;*/

	/*qlz::test1();*/


	/*qlz::test1();
	cout << endl;

	qlz::test2();
	cout << endl;

	qlz::test3();
	cout << endl;

	qlz::test4();
	cout << endl;*/

	/*qlz::test5();*/

	//TestqlzList1();
	//TestqlzList2();
	TestqlzList3();
	cout << endl;
	//TestqlzList4();


	return 0;
}