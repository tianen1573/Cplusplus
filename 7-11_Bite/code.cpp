#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

/*pro1*/
//int main()
//{
//    ////不初始化
//    char* p = nullptr;
//    //char s[] = "aaa"; p = s;
//    //p = "aaaa";
//    
//    ////初始化
//    //char a = 'a';
//    //char* p = &a;
//    //scanf("%s", p);
//
//    printf("%s", p);
//    return 0;
//}

//char fun(const char* p)
//{
//	return *p;
//}
//int main()
//{
//	char a[5] = { 0 }, (*f1)(const char*) = fun, ch = 'a';
//	const char* s = "one";
//	cout << f1(&ch);
//	cout << (f1)(s);
//	return 0;
//}

/*数据结构考核 - 2*/
//#include <iostream>
//#include <stdlib.h>
//#include <string.h>
//using namespace std;
//
//const int N = 10011;
//
//typedef struct ListN
//{
//	int val;
//	struct ListN* next;
//}LN;
//
//int n, m;
//
//int main()
//{
//	cin >> n >> m;
//
//	LN l[N];
//
//	for (int i = 1; i <= n; i++)
//	{
//		l[i].val = i;
//		l[i].next = &(l[i + 1]);
//	}
//	l[n].next = &(l[1]);
//
//	LN* p = &(l[1]);
//	int cnt = 0;
//	if (m == 1)
//		cout << l[n].val;
//	else
//	{
//		while (p->next != p)
//		{
//			cnt++;
//			if (cnt == m - 1)
//			{
//				p->next = p->next->next;
//				cnt = 0;
//			}
//			p = p->next;
//		}
//
//		cout << p->val;
//	}
//
//	return 0;
//}

//union Un1
//{
//	char c[5];
//	int i;
//};
//union Un2
//{
//	short c[7];
//	int i;
//};
//union Un
//{
// int i;
// char c;
//};
//union Un un;
//union D
//{
//	int d1;
//	float d2;
//}d;
//int main()
//{
//	printf("%d\n", sizeof(union Un1));
//	printf("%d\n", sizeof(union Un2));
//	// 下面输出的结果是一样的吗？
//	printf("%d\n", &(un.i));
//	printf("%d\n", &(un.c));
//	//下面输出的结果是什么？
//	un.i = 0x11223344;
//	un.c = 0x55;
//	printf("%x\n", un.i);
//
//	d.d2 = 10;
//	printf("%p\n", &d);
//	printf("%p\n", &d.d1);
//	printf("%d\n", d.d1);
//
//	return 0;
//}

//typedef int DataType;
//class Stack
//{
//public:
//	
//	Stack(DataType* ptr, int cap, int size)
//	{
//		_array = ptr;
//		cap = _capacity;
//		size = _size;
//	}
//	Stack()
//	{
//		_array = nullptr;
//		_capacity = 0;
//		_size = 0;
//	}
//
//	void Push(DataType data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//private:
//	DataType* _array;
//	int _capacity;
//	int _size;
//};
//
//
//int main()
//{
//	Stack s1((DataType*)malloc(5 * sizeof(DataType)), 5, 0);
//
//	Stack s2();
//
//	return 0;
//}

//#include<stdio.h>
//void fun(const char* fname, const char* st)
//{
//	FILE* myf;
//	int i;
//	myf = fopen(fname, "w");
//	for (i = 0; i < strlen(st); i++) fputc(st[i], myf);
//	fclose(myf);
//} 
//int main()
//{
//	fun("test.txt", "new world");
//	fun("test.txt", "hello,");
//	return 0;
//}

//#include<iostream>
//#include<stdlib.h>
//
//using namespace std;
////打表--减少重复操作
//int a[1000001] = { 0 };
//
//int main()
//{
//    //建表
//    for (int i = 1; i <= 1000000; i++)
//    {
//        if (i <= 2) a[i] = i;
//        else a[i] = (2 * a[i - 1] + a[i - 2]) % 32767;
//    }
//    int T = 0; cin >> T;
//    while (T--)
//    {
//        int n = 0; cin >> n;
//        cout << a[n] << endl;
//    }
//    return 0;
//}

//void TestFunc(int a = 10)
//{
//	cout << "void TestFunc(int)" << endl;
//}
//void TestFunc(int a)
//{
//	cout << "void TestFunc(int)" << endl;
//}
//
//int main()
//{
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class Date
//{
//public:
//    int _y, _m, _d;
//    Date& DDate(int& D)//用正数构造, 便于日期输入
//    {
//        _d = D % 100;
//        _m = D / 100 % 100;
//        _y = D / 10000;
//        return *this;
//    }
//    bool operator>(Date& d)
//    {
//        if (_y != d._y) return _y > d._y;
//        if (_m != d._m) return _m > d._m;
//
//        return _d > d._d;
//    }
//    bool operator==(Date& d)
//    {
//        return _y == d._y
//            && _m == d._m
//            && _d == d._d;
//    }
//};
//int GetMonthDays(int year, int month)
//{
//    static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//    int day = days[month];
//    if ((month == 2)
//        && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))//闰年2月
//        day++;
//
//    return day;
//}
//int main()
//{
//    int D1, D2;
//    while (~scanf("%d %d", &D1, &D2))
//    {
//        Date Min, Max;
//        if (D1 > D2)
//        {
//            Max.DDate(D1);
//            Min.DDate(D2);
//        }
//        else
//        {
//            Max.DDate(D2);
//            Min.DDate(D1);
//        }
//        int cnt = 0;
//        while (!(Min == Max))
//        {
//            Min._d++;
//            if (Min._d > GetMonthDays(Min._y, Min._m))
//            {
//                Min._d = 1;
//                Min._m++;
//            }
//            if (Min._m > 12)
//            {
//                Min._y++;
//                Min._m = 1;
//            }
//            cnt++;
//        }
//        if (cnt != 0) cnt++;
//        cout << cnt << endl;
//    }
//    return 0;
//}