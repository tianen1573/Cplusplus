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

#include<iostream>
#include<stdlib.h>
using namespace std;

class A
{
public:
    void Print()
    {
        cout << "Print()" << endl;//空对象可以访问成员方法
    }
    void PrintA()
    {
        //cout << _a << endl;//空对象无成员变量
    }

private:
    int _a;
};
int main()
{
    A* p = nullptr;
    p->Print();
    //p->PrintA();
    return 0;
}