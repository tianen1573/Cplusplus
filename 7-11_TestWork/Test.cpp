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


//int main()
//{
//	int ar[] = { 1,2,3,4,0,5,6,7,8,9 };
//	int n = sizeof(ar) / sizeof(int);
//	vector<int> v(ar, ar + n);
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		if (*it != 0)
//			cout << *it;
//		else
//			v.erase(it);
//		it++;
//	}
//	return 0;
//}

//struct A
//{
//	char c;
//	int arr[0];
//};
//
//int main()
//{
//	
//	cout << sizeof(struct A);
//
//	return 0;
//}


//int main()
//{
//    // 最简单的lambda表达式, 该lambda表达式没有任何意义
//    [] {};
//
//    // 省略参数列表和返回值类型，返回值类型由编译器推导为int
//    int a = 3, b = 4;
//    [=] {return a + 3; };
//
//    // 省略了返回值类型，无返回值类型
//    auto fun1 = [&](int c) {b = a + c; };
//    fun1(10);
//    cout << a << " " << b << endl;
//
//    // 各部分都很完善的lambda函数
//    auto fun2 = [=, &b](int c)->int {return b += a + c; };
//    cout << fun2(10) << endl;
//
//    // 复制捕捉x
//    int x = 10;
//    auto add_x = [x](int a) mutable { x *= 2; return a + x; };
//    cout << add_x(10) << endl;
//    return 0;
//}

// ret = func(x);
// 上面func可能是什么呢？那么func可能是函数名？函数指针？函数对象(仿函数对象)？也有可能
// 是lamber表达式对象？所以这些都是可调用的类型！如此丰富的类型，可能会导致模板的效率低下！
// 为什么呢？我们继续往下看
//template<class F, class T>
//T useF(F f, T x)
//{
//	static int count = 0;
//	cout << "count:" << ++count << endl;
//	cout << "count:" << &count << endl;
//	return f(x);
//}
//double f(double i)
//{
//	return i / 2;
//}
//struct Functor
//{
//	double operator()(double d)
//	{
//		return d / 3;
//	}
//};
//int main()
//{
//	// 函数名
//	cout << useF(f, 11.11) << endl;
//	// 函数对象
//	cout << useF(Functor(), 11.11) << endl;
//	// lamber表达式
//	cout << useF([](double d)->double { return d / 4; }, 11.11) << endl;
//	return 0;
//}

//#include <functional>
//template<class F, class T>
//T useF(F f, T x)
//{
//	static int count = 0;
//	cout << "count:" << ++count << endl;
//	cout << "count:" << &count << endl;
//	return f(x);
//}
//double f(double i)
//{
//	cout << "f" << endl;
//	return i / 2;
//}
//struct Functor
//{
//	double operator()(double d)
//	{
//		cout << "fun" << endl;
//		return d / 3;
//	}
//};
//int main()
//{
//	// 函数名
//	std::function<double(double)> func1 = f;
//	cout << useF(func1, 11.11) << endl;
//	// 函数对象
//	std::function<double(double)> func2 = Functor();
//	cout << useF(func2, 11.11) << endl;
//	// lamber表达式
//	std::function<double(double)> func3 = [](double d)->double { cout << "lambda" << endl; return d / 4; };
//	cout << useF(func3, 11.11) << endl;
//	return 0;
//}

#include <functional>
int Plus(int a, int b)
{
    return a + b;
}
class Sub
{
public:
    int sub(int a, int b)
    {
        return a - b;
    }
};
int main()
{
    //表示绑定函数plus 参数分别由调用 func1 的第一，二个参数指定
    std::function<int(int, int)> func1 = std::bind(Plus, placeholders::_1,
        placeholders::_2);
    //auto func1 = std::bind(Plus, placeholders::_1, placeholders::_2);
    //func2的类型为 function<void(int, int, int)> 与func1类型一样
    //表示绑定函数 plus 的第一，二为： 1， 2
    auto  func2 = std::bind(Plus, 1, 2);
    cout << func1(1, 2) << endl;
    cout << func2() << endl;
    Sub s;
    // 绑定成员函数
    std::function<int(int, int)> func3 = std::bind(&Sub::sub, s,
        placeholders::_1, placeholders::_2);
    // 参数调换顺序
    std::function<int(int, int)> func4 = std::bind(&Sub::sub, s,
        placeholders::_2, placeholders::_1);
    cout << func3(1, 2) << endl;
    cout << func4(1, 2) << endl;
    return 0;
}