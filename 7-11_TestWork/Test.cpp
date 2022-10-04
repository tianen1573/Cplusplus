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

//#include <stdio.h>
//#define a 10
//void foo();
//void foo() {
//#undef a
//#define a 50
//}
//int main()
//{
//	printf("%d..", a);
//	//foo();
//	printf("%d", a);
//	return 0;
//} 

#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

//class par
//{
//public :
//	int _a;
//	int _b;
//protected:
//	int _aa;
//private:
//	int _p;
//};
//
//class chl : protected par
//{
//public:
//	int _c;
//	int _a;
//	void fun()
//	{
//		par::_a;
//	}
//};
//
//int main()
//{
//	par _par;
//	chl _chl;
//
//	_par._a;
//	//_par._aa;
//	//_chl._a;
//
//	//_chl.par::_p;
//
//	if ("abcd" > "cbd")
//		cout << "YES" << endl;
//
//	return 0;
//}


int main()
{
	int ar[] = { 1,2,3,4,0,5,6,7,8,9 };
	int n = sizeof(ar) / sizeof(int);
	vector<int> v(ar, ar + n);
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it != 0)
			cout << *it;
		else
			v.erase(it);
		it++;
	}
	return 0;
}
