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

//#include<iostream>
//#include<stdlib.h>
//#include<string>
//#include<vector>
//#include<list>
//
//using namespace std;

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

//template<class T>
//T Add(const T& left, const T& right)
//{
//    return left + right;
//}
//int main()
//{
//    int a1 = 10, a2 = 20;
//    double d1 = 10.0, d2 = 20.0;
//    Add(a1, a2);
//    Add(d1, d2);
//
//    /*
// 该语句不能通过编译，因为在编译期间，当编译器看到该实例化时，需要推演其实参类型
// 通过实参a1将T推演为int，通过实参d1将T推演为double类型，但模板参数列表中只有一个T，
// 编译器无法确定此处到底该将T确定为int 或者 double类型而报错
// 注意：在模板中，编译器一般不会进行类型转换操作，因为一旦转化出问题，编译器就需要背黑锅
// Add(a1, d1);
// */
//
// // 此时有两种处理方式：1. 用户自己来强制转化 2. 使用显式实例化
//    Add(a1, (int)d2);
//    Add<int>(a1, d2);
//    return 0;
//}

//#include<assert.h>

//class Car {
//public:
//    virtual void Drive() {}
//};
//class Benz :public Car {
//public:
//    virtual void Drive() override { cout << "Benz-舒适" << endl; }
//    virtual void Drive(int a) { cout << "Benz-舒适" << endl; }
//
//};
//
//namespace bit
//{
//    class string
//    {
//    public:
//        typedef char* iterator;
//        iterator begin()
//        {
//            return _str;
//        }
//        iterator end()
//        {
//            return _str + _size;
//        }
//        string(const char* str = "")
//            :_size(strlen(str))
//            , _capacity(_size)
//        {
//            //cout << "string(char* str)" << endl;
//            _str = new char[_capacity + 1];
//            strcpy(_str, str);
//        }
//        // s1.swap(s2)
//        void swap(string& s)
//        {
//            ::swap(_str, s._str);
//            ::swap(_size, s._size);
//            ::swap(_capacity, s._capacity);
//        }
//        // 拷贝构造
//        string(const string& s)
//            :_str(nullptr)
//        {
//            cout << "string(const string& s) -- 深拷贝" << endl;
//            string tmp(s._str);
//            swap(tmp);
//        }
//        // 赋值重载
//        string& operator=(const string& s)
//        {
//            cout << "string& operator=(string s) -- 深拷贝" << endl;
//            string tmp(s);
//            swap(tmp);
//            return *this;
//        }
//        // 移动构造
//        string(string&& s)
//            :_str(nullptr)
//            , _size(0)
//            , _capacity(0)
//        {
//            cout << "string(string&& s) -- 移动语义" << endl;
//            swap(s);
//        }
//        // 移动赋值
//        string& operator=(string&& s)
//        {
//            cout << "string& operator=(string&& s) -- 移动语义" << endl;
//            swap(s);
//            return *this;
//        }
//        ~string()
//        {
//            delete[] _str;
//            _str = nullptr;
//        }
//        char& operator[](size_t pos)
//        {
//            assert(pos < _size);
//            return _str[pos];
//        }
//        void reserve(size_t n)
//        {
//            if (n > _capacity)
//            {
//                char* tmp = new char[n + 1];
//                strcpy(tmp, _str);
//                delete[] _str;
//                _str = tmp;
//                _capacity = n;
//            }
//        }
//        void push_back(char ch)
//        {
//            if (_size >= _capacity)
//            {
//                size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
//                reserve(newcapacity);
//            }
//            _str[_size] = ch;
//            ++_size;
//            _str[_size] = '\0';
//        }
//        //string operator+=(char ch)
//        string& operator+=(char ch)
//        {
//            push_back(ch);
//            return *this;
//        }
//        const char* c_str() const
//        {
//            return _str;
//        }
//    private:
//        char* _str;
//        size_t _size;
//        size_t _capacity; // 不包含最后做标识的\0
//    };
//}
//
//template<class T>
//struct ListNode
//{
//    ListNode* _next = nullptr;
//    ListNode* _prev = nullptr;
//    T _data;
//};
//template<class T>
//class List
//{
//    typedef ListNode<T> Node;
//public:
//    List()
//    {
//        _head = new Node;
//        _head->_next = _head;
//        _head->_prev = _head;
//    }
//    void PushBack(T&& x)
//    {
//        //Insert(_head, x);
//        Insert(_head, std::forward<T>(x));
//    }
//    void PushFront(T&& x)
//    {
//        //Insert(_head->_next, x);
//        Insert(_head->_next, std::forward<T>(x));
//    }
//    void Insert(Node* pos, T&& x)
//    {
//        Node* prev = pos->_prev;
//        Node* newnode = new Node;
//        newnode->_data = std::forward<T>(x); // 关键位置
//        // prev newnode pos
//        prev->_next = newnode;
//        newnode->_prev = prev;
//        newnode->_next = pos;
//        pos->_prev = newnode;
//    }
//    void Insert(Node* pos, const T& x)
//    {
//        Node* prev = pos->_prev;
//        Node* newnode = new Node;
//        newnode->_data = x; // 关键位置
//        // prev newnode pos
//        prev->_next = newnode;
//        newnode->_prev = prev;
//        newnode->_next = pos;
//        pos->_prev = newnode;
//    }
//private:
//    Node* _head;
//};
//int main()
//{
//    List<bit::string> lt;
//    lt.PushBack("1111");
//    lt.PushFront("2222");
//    return 0;
//}

//int main()
//{
//    int&& rr1  = 10;
//
//    auto ptr = &rr1;
//
//    *ptr = 11;
//
//    cout << *ptr << ' ' << rr1;
//
//    return 0;
//}


//// 使用举例
//#include <functional>
//int Plus(int a, int b)
//{
//    return a + b;
//}
//class Sub
//{
//public:
//    int sub(int a, int b)
//    {
//        return a - b;
//    }
//};
//int main()
//{
//    //表示绑定函数plus 参数分别由调用 func1 的第一，二个参数指定
//    std::function<int(int, int)> func1 = std::bind(Plus, placeholders::_1,
//        placeholders::_2);
//    //auto func1 = std::bind(Plus, placeholders::_1, placeholders::_2);
//    //func2的类型为 function<void(int, int, int)> 与func1类型一样
//    //表示绑定函数 plus 的第一，二为： 1， 2
//    auto  func2 = std::bind(Plus, 1, 2);
//    cout << func1(1, 2) << endl;
//    cout << func2() << endl;
//    Sub s;
//    // 绑定成员函数
//    std::function<int(int, int)> func3 = std::bind(&Sub::sub, s, placeholders::_1, placeholders::_2);
//    // 参数调换顺序
//    std::function<int(int, int)> func4 = std::bind(&Sub::sub, s, placeholders::_2, placeholders::_1);
//    cout << func3(1, 2) << endl;
//    cout << func4(1, 2) << endl;
//    return 0;
//}


//// 懒汉
//// 优点：第一次使用实例对象时，创建对象。进程启动无负载。多个单例实例启动顺序自由控制。
//// 缺点：复杂
//#include <iostream>
//#include <mutex>
//#include <thread>
//using namespace std;
//class Singleton
//{
//public:
//	static Singleton* GetInstance() {
//		// 注意这里一定要使用Double-Check的方式加锁，才能保证效率和线程安全
//		if (nullptr == m_pInstance) {
//			m_mtx.lock();
//			if (nullptr == m_pInstance) {
//				m_pInstance = new Singleton();
//			}
//			m_mtx.unlock();
//		}
//		return m_pInstance;
//	}
//	// 实现一个内嵌垃圾回收类    
//	class CGarbo {
//	public:
//		~CGarbo() {
//			if (Singleton::m_pInstance)
//				delete Singleton::m_pInstance;
//		}
//	};
//	// 定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数从而释放单例对象
//	static CGarbo Garbo;
//private:
//	// 构造函数私有
//	Singleton() {};
//	// 防拷贝
//	Singleton(Singleton const&);
//	Singleton& operator=(Singleton const&);
//
//	static Singleton* m_pInstance; // 单例对象指针
//	static mutex m_mtx;   //互斥锁
//};
//Singleton* Singleton::m_pInstance = nullptr;
//Singleton::CGarbo Singleton::Garbo;
//mutex Singleton::m_mtx;
//
//
//int main()
//{
//	thread t1([] {cout << Singleton::GetInstance() << endl; });
//	thread t2([] {cout << Singleton::GetInstance() << endl; });
//	t1.join();
//	t2.join();
//	cout << Singleton::GetInstance() << endl;
//	cout << Singleton::GetInstance() << endl;
//	return 0;
//}


//namespace n1
//{
//	using namespace std;
//
//	int a, b;
//
//	namespace n2
//	{
//		void func2()
//		{
//			cin >> a >> b;
//			cout << a << ' ' << b;
//		}
//	}
//}
//
//int _g_val = 111;
//
//void func2(int a = 12, int b = 11, int c = _g_val)
//{
//	cout << a << ' ' << b << ' ' << c << endl;
//}
//void func2(int a, int b)
//{
//	cout << a << ' ' << b << endl;
//}
//
//int main()
//{
//	//n1::n2::func();
//
//	func2(1);
//
//	return 0;
//}

//#include <iostream>
//
//using std::cout;
//using std::endl;
//
////void f();
////void f(int);
//void f(double, double = 314);
//namespace N
//{
//    void f(char a, char b)
//    {
//
//    }
//}
//class A{
//    public: 
//        operator double()//double() 构造函数
//        {
//            cout << "operator double()\n";
//
//            return double();
//        }
//};
//int main()
//{
//    using namespace N; //using指示符
//    A a;
//    cout << a.operator double() << endl;
//    cout << double(11);
//    return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	int a;
//	const int b = 10;
//	
//	const int* p1 = &a;
//	p1 = &b;
//
//	cout << a;
//
//	return 0;
//}

#include "head.h"

//void func3()
//{
//	cout << "main \n";
//}
//
//int main()
//{
//	func3();
//
//	return 0;
//}

//void TestAuto()
//{
//	auto a = 1, b = 2;
//	//auto c = 3, d = 4.0; // 该行代码会编译失败，因为c和d的初始化表达式类型不同
//}

//class A
//{
//public :
//	int a, b;
//	void func()
//	{
//		this->a = 10;;
//
//		cout << a << ' ' << b << endl;
//	}
//
//	A operator=(const A& a);
//};
//
//A A::operator=(const A& a) 
//{
//	return A();
//}

//class A
//{
//public:
//	
//	~A()
//	{
//		cout << "------A------\n";
//	}
//};
//
//class Date
//{
//public:
//	string str;
//
//	Date(string s)
//		:str(s)
//	{}
//	~Date()
//	{
//		cout << str << "匿名对象\n";
//	}
//
//};
// 赋值运算符重载成全局函数，注意重载成全局函数时没有this指针了，需要给两个参数
//Date& operator=(Date& left, const Date& right)
//{
//	if (&left != &right)
//	{
//		left._year = right._year;
//		left._month = right._month;
//		left._day = right._day;
//	}
//	return left;
//}

//class Date
//{
//public:
//	// 1. 单参构造函数，没有使用explicit修饰，具有类型转换作用
//	// explicit修饰构造函数，禁止类型转换---explicit去掉之后，代码可以通过编译
//	Date(int year)
//		:_year(year)
//	{}
//	/*
//   // 2. 虽然有多个参数，但是创建对象时后两个参数可以不传递，没有使用explicit修饰，具有类型转换作用
//   // explicit修饰构造函数，禁止类型转换
//   explicit Date(int year, int month = 1, int day = 1)
//   : _year(year)
//   , _month(month)
//   , _day(day)
//   {}
//   */
//	Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void Test()
//{
//	Date d1(2022);
//	// 用一个整形变量给日期类型对象赋值
//	// 实际编译器背后会用2023构造一个无名对象，最后用无名对象给d1对象进行赋值
//	d1 = 2023;
//	// 将1屏蔽掉，2放开时则编译失败，因为explicit修饰构造函数，禁止了单参构造函数类型转换的作用
//}

//class T
//{
//public:
//
//	const static int a = 1;
//
//	void print()
//	{
//		cout << a << endl;
//	}
//
//};

//int T::a;

//int main()
//{
//	//const volatile int a = 10;
//
//	//int* pa = (int*)&a;
//	//*pa = 11;
//
//	//cout << a << ' ' << *pa;
//
//	/*A aa;
//	aa.func();*/
//
//	/*A a;
//
//	Date("");
//	const Date d = Date("const");
//	Date("");*/
//
//	//Test();
//
//	/*T t;
//	t.print();*/
//
//	return 0;
//}

//class A
//{
//private:
//    static int k;
//    int h;
//public:
//    class B // B天生就是A的友元
//    {
//    public:
//        void foo(const A& a)
//        {
//            cout << k << endl;//OK
//            cout << a.h << endl;//OK
//        }
//    };
//};
//int A::k = 1;
//int main()
//{
//    A::B b;
//    b.foo(A());
//
//    return 0;
//}

//int globalVar = 1;
//static int staticGlobalVar = 1;
//void Test()
//{
//	static int staticVar = 1;//静态存储区
//	int localVar = 1;//栈
//	int num1[10] = { 1, 2, 3, 4 };//栈
//	char char2[] = "abcd";//栈 "abcd"在只读区，此时"abcd"拷贝到char2数组了
//	const char* pChar3 = "abcd";//栈，此时pChar3指向"abcd"存储的地址，不拷贝
//	int* ptr1 = (int*)malloc(sizeof(int) * 4);//栈 *ptr1在堆
//	int* ptr2 = (int*)calloc(4, sizeof(int));//栈 *ptr2在堆
//	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);//栈 *ptr2在堆
//	free(ptr1);
//	free(ptr3);
//
//	//栈，在高地址，向下增长
//	//堆，在低地址，向上增长
//}
//
//void Test1()
//{
//	int* p1 = (int*)malloc(sizeof(int));
//	free(p1);
//	// 1.malloc/calloc/realloc的区别是什么？
//	int* p2 = (int*)calloc(4, sizeof(int));
//	int* p3 = (int*)realloc(p2, sizeof(int) * 10);
//	// 这里需要free(p2)吗？
//	free(p3);
//}
//
//int main()
//{
//	Test1();
//	return 0;
//}


//template<class T>
//T Add(const T& left, const T& right)
//{
//    auto a = right + left;
//
//    return left + right;
//}
//int main()
//{
//    int a1 = 10, a2 = 20;
//    double d1 = 10.01, d2 = 20.01;
//    cout << endl << Add(a1, a2);
//    cout << endl << Add(d1, d2);
//
//    /*
// 该语句不能通过编译，因为在编译期间，当编译器看到该实例化时，需要推演其实参类型
// 通过实参a1将T推演为int，通过实参d1将T推演为double类型，但模板参数列表中只有一个T，
// 编译器无法确定此处到底该将T确定为int 或者 double类型而报错
// 注意：在模板中，编译器一般不会进行类型转换操作，因为一旦转化出问题，编译器就需要背黑锅
// Add(a1, d1);
// */
// // 此时有两种处理方式：1. 用户自己来强制转化 2. 使用显式实例化
//    cout << endl << Add(a1, (int)d1);
//    cout << endl << Add<int>(a1, d1);
//
//    //Add<auto>(a1, a2);
//    return 0;
//}


//class Person
//{
//public:
//    void Print()
//    {
//        cout << "name:" << _name << endl;
//        cout << "age:" << _age << endl;
//    }
//protected:
//    string _name = "peter"; // 姓名
//    int _age = 18;  // 年龄
//};
//// 继承后父类的Person的成员（成员函数+成员变量）都会变成子类的一部分。这里体现出了Student和Teacher复用了Person的成员。下面我们使用监视窗口查看Student和Teacher对象，可以看到变量的复用。调用Print可以看到成员函数的复用。
//class Student : public Person
//{
//protected:
//    int _stuid; // 学号
//};
//class Teacher : public Person
//{
//protected:
//    int _jobid; // 工号
//};

//// 实例演示三种继承关系下基类成员的各类型成员访问关系的变化  
//class Person
//{
//public:
//        void Print()
//    {
//        cout << _name << endl;
//    }
//protected:
//    string _name = "peter"; // 姓名
//private:
//    int _age; // 年龄
//};
////class Student : protected Person
////class Student : private Person
//class Student : public Person
//{
//protected:
//    int _stunum; // 学号
//};

//class Person
//{
//protected:
//    string _name; // 姓名
//    string _sex;  // 性别
//    int _age; // 年龄
//};
//class Student : public Person
//{
//public:
//    int _No; // 学号
//};
//void Test()
//{
//    Student sobj;
//    // 1.子类对象可以赋值给父类对象/指针/引用
//    Person pobj = sobj;
//    Person* pp = &sobj;
//    Person& rp = sobj;
//
//    //2.基类对象不能赋值给派生类对象
//    //sobj = pobj;
//
//    // 3.基类的指针可以通过强制类型转换赋值给派生类的指针
//    pp = &sobj;
//    Student* ps1 = (Student*)pp; // 这种情况转换时可以的。
//    ps1->_No = 10;
//
//    pp = &pobj;
//    Student* ps2 = (Student*)pp; // 这种情况转换时虽然可以，但是会存在越界访问的问题
//    ps2->_No = 10;
//}
//
//int main()
//{
//    //Student s;
//    ////Teacher t;
//    //s.Print();
//    ////t.Print();
//
//    Test();
//
//    return 0;
//}


//// Student的_num和Person的_num构成隐藏关系，可以看出这样代码虽然能跑，但是非常容易混淆
//class Person
//{
//protected:
//    string _name = "小李子"; // 姓名
//    int _num = 111;   // 身份证号
//};
//class Student : public Person
//{
//public:
//    void Print()
//    {
//        cout << " 姓名:" << _name << endl;
//        cout << " 身份证号:" << Person::_num << endl;
//        cout << " 学号:" << _num << endl;
//    }
//protected:
//    int _num = 999; // 学号
//};
//void Test()
//{
//    Student s1;
//    s1.Print();
//};

//// B中的fun和A中的fun不是构成重载，因为不是在同一作用域
//// B中的fun和A中的fun构成隐藏，成员函数满足函数名相同就构成隐藏。
//class A
//{
//public:
//    void fun()
//    {
//        cout << "func()" << endl;
//    }
//};
//class B : public A
//{
//public:
//    void fun(int i)
//    {
//        A::fun();
//        cout << "func(int i)->" << i << endl;
//    }
//};
//void Test()
//{
//    B b;
//    b.fun(10);
//    b.A::fun();
//};

//class Person
//{
//public:
//    Person(const char* name = "peter")
//        : _name(name)
//    {
//        cout << "Person()" << endl;
//    }
//
//    Person(const Person& p)
//        : _name(p._name)
//    {
//        cout << "Person(const Person& p)" << endl;
//    }
//
//    Person& operator=(const Person& p)
//    {
//        cout << "Person operator=(const Person& p)" << endl;
//        if (this != &p)
//            _name = p._name;
//
//        return *this;
//    }
//
//    ~Person()
//    {
//        cout << "~Person()" << endl;
//    }
//protected:
//    string _name; // 姓名
//};
//class Student : public Person
//{
//public:
//    Student(const char* name, int num)
//        : Person(name)
//        , _num(num)
//    {
//        cout << "Student()" << endl;
//    }
//
//    Student(const Student& s)
//        : Person(s)
//        , _num(s._num)
//    {
//        cout << "Student(const Student& s)" << endl;
//    }
//
//    Student& operator = (const Student& s)
//    {
//        cout << "Student& operator= (const Student& s)" << endl;
//        if (this != &s)
//        {
//            Person::operator=(s);//子类对象赋值给父类对象
//            _num = s._num;
//        }
//        return *this;
//    }
//
//    ~Student()
//    {
//        cout << "~Student()" << endl;
//    }
//protected:
//    int _num; //学号
//};
//void Test()
//{
//    Student s1("jack", 18);
//    Student s2(s1);
//    Student s3("rose", 17);
//    s1 = s3;
//}
//
//
//int main()
//{
//    Test();
//
//    return 0;
//}

//class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // 姓名
//};
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
//};
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	//cout << s._stuNum << endl;
//}
//void main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//}

//class Person
//{
//public:
//	Person() { ++_count; }
//protected:
//	string _name; // 姓名
//public:
//	static int _count; // 统计人的个数。
//};
//int Person::_count = 0;
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
//};
//class Graduate : public Student
//{
//protected:
//	string _seminarCourse; // 研究科目
//};
//void TestPerson()
//{
//	Student s1;
//	Student s2;
//	Student s3;
//	Graduate s4;
//	cout << " 人数 :" << Person::_count << endl;
//	Student::_count = 0;
//	cout << " 人数 :" << Person::_count << endl;
//}

//class Person
//{
//public:
//	string _name; // 姓名
//};
//class Student : public Person
//{
//protected:
//	int _num; //学号
//};
//class Teacher : public Person
//{
//protected:
//	int _id; // 职工编号
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//void Test()
//{
//	// 这样会有二义性无法明确知道访问的是哪一个
//	Assistant a;
//	//a._name = "peter";
//	// 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
//	a.Student::_name = "xxx";
//	a.Teacher::_name = "yyy";
//
//	1;
//}


//class Person
//{
//public:
//	string _name; // 姓名
//};
//class Student : virtual public Person
//{
//protected:
//	int _num; //学号
//};
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // 职工编号
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//void Test()
//{
//	Assistant a;
//	a._name = "peter";
//
//}
//
//int main()
//{
//	//TestPerson();
//	Test();
//
//	return 0;
//}

//class A
//{
//public:
//	int _a;
//};
//// class B : public A
//class B : virtual public A
//{
//public:
//	int _b;
//};
//// class C : public A
//class C : virtual public A
//{
//public:
//	int _c;
//};
//class D : virtual public B, public C
//{
//public:
//	int _d;
//};
//int main()
//{
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//	B b;
//	b._a = 16;
//	b._b = 32;
//	return 0;
//}

//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//	/*注意：在重写基类虚函数时，派生类的虚函数在不加virtual关键字时，虽然也可以构成重写(因
//	为继承后基类的虚函数被继承下来了在派生类依旧保持虚函数属性),但是该种写法不是很规范，不建议
//	这样使用*/
//	/*void BuyTicket() { cout << "买票-半价" << endl; }*/
//};
//void Func(Person& p)
//{
//	p.BuyTicket();
//}

class A {};
class B : public A {};
class Person {
public:
	virtual A* f() { cout << "A*" << endl; return new A; }
};
class Student : public Person {
public:
	B* f() { cout << "B*" << endl; return new B; }
};

int main()
{
	/*Person ps;
	Student st;
	Func(ps);
	Func(st);*/

	Person p;
	Student s;

	p.f();
	Person* pp = &s;
	pp->f();

	return 0;
}


//class Person {
//public:
//    virtual ~Person() { cout << "~Person()" << endl; }
//};
//class Student : public Person {
//public:
//    virtual ~Student() { cout << "~Student()" << endl; }
//};
//// 只有派生类Student的析构函数重写了Person的析构函数，下面的delete对象调用析构函
//// 数，才能构成多态，才能保证p1和p2指向的对象正确的调用析构函数。
//int main()
//{
//    Person* p1 = new Person;
//    Person* p2 = new Student;
//    delete p1;
//    delete p2;
//    return 0;
//}