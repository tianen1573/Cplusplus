#define _CRT_SECURE_NO_WARNINGS 1

//void fun(int arr[])
//{
//
//}
//
//struct n1
//{
//	int a;
//};
//class n2
//{
//	int a;
//};
//
//
//int main()
//{
//	/*int a = 10;
//
//	int& ra = a;
//	const double& rra = (double)a;*/
//
//	n1 _n1;
//	_n1.a = 10;
//
//	n2 _n2;
//	//_n2.a = 10;
//
//	return 0;
//}

//#include<iostream>
//#include<stdlib.h>
//#include<stdio.h>
//#include<malloc.h>
//using namespace std;

//class A
//{
//public:
//    void Print()
//    {
//        cout << "Print()" << endl;//空对象可以访问成员方法
//    }
//    void PrintA()
//    {
//        //cout << _a << endl;//空对象无成员变量
//    }
//
//private:
//    int _a;
//};
//
//template<typename T1>
//class c1
//{
//    //...
//    typedef T1 a;
//};

//int main()
//{
//    /*A* p = nullptr;
//    p->Print();*/
//    //p->PrintA();
//    
//
//    int* a = NULL;
//
//    a = (int*)realloc(a, 20);
//
//
//    return 0;
//
//}

#include<iostream>
#include<stdlib.h>
#include<string>
#include<vector>
#include<list>

using namespace std;

//int main()
//{
//	string dest, src;
//
//	getline(cin, dest);
//
//	int prePos = 0;
//	int pos = 0;
//
//	while (true)
//	{
//		
//		int last = dest.find(' ');
//	}
//
//}

//template<class T>
//class test
//{
//	typedef T dataType;
//
//	auto t = 1;
//};

//int main()
//{
//	/*test<int> t;*/
//
//	const vector<int> cvec;
//	const list<int> cl;
//
//	vector<int>::const_iterator it = cvec.begin();
//	list<int>::const_iterator it2 = cl.begin();
//
//	return 0;
//}

template<class T>
T Add(const T& left, const T& right)
{
    return left + right;
}
int main()
{
    int a1 = 10, a2 = 20;
    double d1 = 10.0, d2 = 20.0;
    Add(a1, a2);
    Add(d1, d2);

    /*
 该语句不能通过编译，因为在编译期间，当编译器看到该实例化时，需要推演其实参类型
 通过实参a1将T推演为int，通过实参d1将T推演为double类型，但模板参数列表中只有一个T，
 编译器无法确定此处到底该将T确定为int 或者 double类型而报错
 注意：在模板中，编译器一般不会进行类型转换操作，因为一旦转化出问题，编译器就需要背黑锅
 Add(a1, d1);
 */

 // 此时有两种处理方式：1. 用户自己来强制转化 2. 使用显式实例化
    Add(a1, (int)d2);
    Add<int>(a1, d2);
    return 0;
}