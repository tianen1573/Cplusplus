#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdlib.h>
//#include<stdio.h>
//#include<iostream>
//
//using std::cout;
//using std::endl;
//
//
//class MyClass
//{
//public:
//	MyClass(int a = 0);
//	~MyClass();
//	void Print()
//	{
//		cout << _a << endl;
//	}
//
//private:
//	int _a = 0;
//};
//
//MyClass::MyClass(int a)
//{
//	_a = a;
//}
//
//MyClass::~MyClass()
//{
//}
//
//int main()
//{
//	MyClass* A = (MyClass*)malloc(sizeof(MyClass));
//
//	A->Print();
//
//	return 0;
//}

#include <stdio.h>
#define a 10
void foo();
void foo() {
#undef a
#define a 50
}
int main()
{
	printf("%d..", a);
	//foo();
	printf("%d", a);
	return 0;
} 
