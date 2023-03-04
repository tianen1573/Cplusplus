//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<iostream>
//
//using namespace std;
//
//template<class T>
//class SmartPtr {
//public:
//    SmartPtr(T* ptr = nullptr)
//        : _ptr(ptr)
//    {}
//    ~SmartPtr()
//    {
//        if (_ptr)
//            delete _ptr;
//    }
//    T& operator*() { return *_ptr; }
//    T* operator->() { return _ptr; }
//private:
//    T* _ptr;
//};
//struct Date
//{
//    int _year;
//    int _month;
//    int _day;
//};
//int main()
//{
//    SmartPtr<int> sp1(new int);
//    *sp1 = 10;
//    cout << *sp1 << endl;
//    SmartPtr<Date> sparray(new Date);
//    // 需要注意的是这里应该是sparray.operator->()->_year = 2018;
//    // 本来应该是sparray->->_year这里语法上为了可读性，省略了一个->
//    sparray->_year = 2018;
//    sparray->_month = 1;
//    sparray->_day = 1;
//}

//#include"autoPtr.h"
//#include"uniquePtr.h"
//#include"sharedPtr.h"
//
//int main()
//{
//	//autoPtr::func1();
//
//	//uniquePtr::func1();
//
//	//sharedPtr::func1();
//	sharedPtr::func2();
//
//
//	return 0;
//}