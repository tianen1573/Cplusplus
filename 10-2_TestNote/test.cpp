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
//        cout << "Print()" << endl;//�ն�����Է��ʳ�Ա����
//    }
//    void PrintA()
//    {
//        //cout << _a << endl;//�ն����޳�Ա����
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
// ����䲻��ͨ�����룬��Ϊ�ڱ����ڼ䣬��������������ʵ����ʱ����Ҫ������ʵ������
// ͨ��ʵ��a1��T����Ϊint��ͨ��ʵ��d1��T����Ϊdouble���ͣ���ģ������б���ֻ��һ��T��
// �������޷�ȷ���˴����׸ý�Tȷ��Ϊint ���� double���Ͷ�����
// ע�⣺��ģ���У�������һ�㲻���������ת����������Ϊһ��ת�������⣬����������Ҫ���ڹ�
// Add(a1, d1);
// */
//
// // ��ʱ�����ִ���ʽ��1. �û��Լ���ǿ��ת�� 2. ʹ����ʽʵ����
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
//    virtual void Drive() override { cout << "Benz-����" << endl; }
//    virtual void Drive(int a) { cout << "Benz-����" << endl; }
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
//        // ��������
//        string(const string& s)
//            :_str(nullptr)
//        {
//            cout << "string(const string& s) -- ���" << endl;
//            string tmp(s._str);
//            swap(tmp);
//        }
//        // ��ֵ����
//        string& operator=(const string& s)
//        {
//            cout << "string& operator=(string s) -- ���" << endl;
//            string tmp(s);
//            swap(tmp);
//            return *this;
//        }
//        // �ƶ�����
//        string(string&& s)
//            :_str(nullptr)
//            , _size(0)
//            , _capacity(0)
//        {
//            cout << "string(string&& s) -- �ƶ�����" << endl;
//            swap(s);
//        }
//        // �ƶ���ֵ
//        string& operator=(string&& s)
//        {
//            cout << "string& operator=(string&& s) -- �ƶ�����" << endl;
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
//        size_t _capacity; // �������������ʶ��\0
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
//        newnode->_data = std::forward<T>(x); // �ؼ�λ��
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
//        newnode->_data = x; // �ؼ�λ��
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


//// ʹ�þ���
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
//    //��ʾ�󶨺���plus �����ֱ��ɵ��� func1 �ĵ�һ����������ָ��
//    std::function<int(int, int)> func1 = std::bind(Plus, placeholders::_1,
//        placeholders::_2);
//    //auto func1 = std::bind(Plus, placeholders::_1, placeholders::_2);
//    //func2������Ϊ function<void(int, int, int)> ��func1����һ��
//    //��ʾ�󶨺��� plus �ĵ�һ����Ϊ�� 1�� 2
//    auto  func2 = std::bind(Plus, 1, 2);
//    cout << func1(1, 2) << endl;
//    cout << func2() << endl;
//    Sub s;
//    // �󶨳�Ա����
//    std::function<int(int, int)> func3 = std::bind(&Sub::sub, s, placeholders::_1, placeholders::_2);
//    // ��������˳��
//    std::function<int(int, int)> func4 = std::bind(&Sub::sub, s, placeholders::_2, placeholders::_1);
//    cout << func3(1, 2) << endl;
//    cout << func4(1, 2) << endl;
//    return 0;
//}


//// ����
//// �ŵ㣺��һ��ʹ��ʵ������ʱ���������󡣽��������޸��ء��������ʵ������˳�����ɿ��ơ�
//// ȱ�㣺����
//#include <iostream>
//#include <mutex>
//#include <thread>
//using namespace std;
//class Singleton
//{
//public:
//	static Singleton* GetInstance() {
//		// ע������һ��Ҫʹ��Double-Check�ķ�ʽ���������ܱ�֤Ч�ʺ��̰߳�ȫ
//		if (nullptr == m_pInstance) {
//			m_mtx.lock();
//			if (nullptr == m_pInstance) {
//				m_pInstance = new Singleton();
//			}
//			m_mtx.unlock();
//		}
//		return m_pInstance;
//	}
//	// ʵ��һ����Ƕ����������    
//	class CGarbo {
//	public:
//		~CGarbo() {
//			if (Singleton::m_pInstance)
//				delete Singleton::m_pInstance;
//		}
//	};
//	// ����һ����̬��Ա�������������ʱ��ϵͳ���Զ������������������Ӷ��ͷŵ�������
//	static CGarbo Garbo;
//private:
//	// ���캯��˽��
//	Singleton() {};
//	// ������
//	Singleton(Singleton const&);
//	Singleton& operator=(Singleton const&);
//
//	static Singleton* m_pInstance; // ��������ָ��
//	static mutex m_mtx;   //������
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
//        operator double()//double() ���캯��
//        {
//            cout << "operator double()\n";
//
//            return double();
//        }
//};
//int main()
//{
//    using namespace N; //usingָʾ��
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
//	//auto c = 3, d = 4.0; // ���д�������ʧ�ܣ���Ϊc��d�ĳ�ʼ�����ʽ���Ͳ�ͬ
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
//		cout << str << "��������\n";
//	}
//
//};
// ��ֵ��������س�ȫ�ֺ�����ע�����س�ȫ�ֺ���ʱû��thisָ���ˣ���Ҫ����������
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
//	// 1. ���ι��캯����û��ʹ��explicit���Σ���������ת������
//	// explicit���ι��캯������ֹ����ת��---explicitȥ��֮�󣬴������ͨ������
//	Date(int year)
//		:_year(year)
//	{}
//	/*
//   // 2. ��Ȼ�ж�����������Ǵ�������ʱ�������������Բ����ݣ�û��ʹ��explicit���Σ���������ת������
//   // explicit���ι��캯������ֹ����ת��
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
//	// ��һ�����α������������Ͷ���ֵ
//	// ʵ�ʱ������������2023����һ������������������������d1������и�ֵ
//	d1 = 2023;
//	// ��1���ε���2�ſ�ʱ�����ʧ�ܣ���Ϊexplicit���ι��캯������ֹ�˵��ι��캯������ת��������
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
//    class B // B��������A����Ԫ
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
//	static int staticVar = 1;//��̬�洢��
//	int localVar = 1;//ջ
//	int num1[10] = { 1, 2, 3, 4 };//ջ
//	char char2[] = "abcd";//ջ "abcd"��ֻ��������ʱ"abcd"������char2������
//	const char* pChar3 = "abcd";//ջ����ʱpChar3ָ��"abcd"�洢�ĵ�ַ��������
//	int* ptr1 = (int*)malloc(sizeof(int) * 4);//ջ *ptr1�ڶ�
//	int* ptr2 = (int*)calloc(4, sizeof(int));//ջ *ptr2�ڶ�
//	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);//ջ *ptr2�ڶ�
//	free(ptr1);
//	free(ptr3);
//
//	//ջ���ڸߵ�ַ����������
//	//�ѣ��ڵ͵�ַ����������
//}
//
//void Test1()
//{
//	int* p1 = (int*)malloc(sizeof(int));
//	free(p1);
//	// 1.malloc/calloc/realloc��������ʲô��
//	int* p2 = (int*)calloc(4, sizeof(int));
//	int* p3 = (int*)realloc(p2, sizeof(int) * 10);
//	// ������Ҫfree(p2)��
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
// ����䲻��ͨ�����룬��Ϊ�ڱ����ڼ䣬��������������ʵ����ʱ����Ҫ������ʵ������
// ͨ��ʵ��a1��T����Ϊint��ͨ��ʵ��d1��T����Ϊdouble���ͣ���ģ������б���ֻ��һ��T��
// �������޷�ȷ���˴����׸ý�Tȷ��Ϊint ���� double���Ͷ�����
// ע�⣺��ģ���У�������һ�㲻���������ת����������Ϊһ��ת�������⣬����������Ҫ���ڹ�
// Add(a1, d1);
// */
// // ��ʱ�����ִ���ʽ��1. �û��Լ���ǿ��ת�� 2. ʹ����ʽʵ����
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
//    string _name = "peter"; // ����
//    int _age = 18;  // ����
//};
//// �̳к����Person�ĳ�Ա����Ա����+��Ա�����������������һ���֡��������ֳ���Student��Teacher������Person�ĳ�Ա����������ʹ�ü��Ӵ��ڲ鿴Student��Teacher���󣬿��Կ��������ĸ��á�����Print���Կ�����Ա�����ĸ��á�
//class Student : public Person
//{
//protected:
//    int _stuid; // ѧ��
//};
//class Teacher : public Person
//{
//protected:
//    int _jobid; // ����
//};

//// ʵ����ʾ���ּ̳й�ϵ�»����Ա�ĸ����ͳ�Ա���ʹ�ϵ�ı仯  
//class Person
//{
//public:
//        void Print()
//    {
//        cout << _name << endl;
//    }
//protected:
//    string _name = "peter"; // ����
//private:
//    int _age; // ����
//};
////class Student : protected Person
////class Student : private Person
//class Student : public Person
//{
//protected:
//    int _stunum; // ѧ��
//};

//class Person
//{
//protected:
//    string _name; // ����
//    string _sex;  // �Ա�
//    int _age; // ����
//};
//class Student : public Person
//{
//public:
//    int _No; // ѧ��
//};
//void Test()
//{
//    Student sobj;
//    // 1.���������Ը�ֵ���������/ָ��/����
//    Person pobj = sobj;
//    Person* pp = &sobj;
//    Person& rp = sobj;
//
//    //2.��������ܸ�ֵ�����������
//    //sobj = pobj;
//
//    // 3.�����ָ�����ͨ��ǿ������ת����ֵ���������ָ��
//    pp = &sobj;
//    Student* ps1 = (Student*)pp; // �������ת��ʱ���Եġ�
//    ps1->_No = 10;
//
//    pp = &pobj;
//    Student* ps2 = (Student*)pp; // �������ת��ʱ��Ȼ���ԣ����ǻ����Խ����ʵ�����
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


//// Student��_num��Person��_num�������ع�ϵ�����Կ�������������Ȼ���ܣ����Ƿǳ����׻���
//class Person
//{
//protected:
//    string _name = "С����"; // ����
//    int _num = 111;   // ���֤��
//};
//class Student : public Person
//{
//public:
//    void Print()
//    {
//        cout << " ����:" << _name << endl;
//        cout << " ���֤��:" << Person::_num << endl;
//        cout << " ѧ��:" << _num << endl;
//    }
//protected:
//    int _num = 999; // ѧ��
//};
//void Test()
//{
//    Student s1;
//    s1.Print();
//};

//// B�е�fun��A�е�fun���ǹ������أ���Ϊ������ͬһ������
//// B�е�fun��A�е�fun�������أ���Ա�������㺯������ͬ�͹������ء�
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
//    string _name; // ����
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
//            Person::operator=(s);//�������ֵ���������
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
//    int _num; //ѧ��
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
//	string _name; // ����
//};
//class Student : public Person
//{
//protected:
//	int _stuNum; // ѧ��
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
//	string _name; // ����
//public:
//	static int _count; // ͳ���˵ĸ�����
//};
//int Person::_count = 0;
//class Student : public Person
//{
//protected:
//	int _stuNum; // ѧ��
//};
//class Graduate : public Student
//{
//protected:
//	string _seminarCourse; // �о���Ŀ
//};
//void TestPerson()
//{
//	Student s1;
//	Student s2;
//	Student s3;
//	Graduate s4;
//	cout << " ���� :" << Person::_count << endl;
//	Student::_count = 0;
//	cout << " ���� :" << Person::_count << endl;
//}

//class Person
//{
//public:
//	string _name; // ����
//};
//class Student : public Person
//{
//protected:
//	int _num; //ѧ��
//};
//class Teacher : public Person
//{
//protected:
//	int _id; // ְ�����
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // ���޿γ�
//};
//void Test()
//{
//	// �������ж������޷���ȷ֪�����ʵ�����һ��
//	Assistant a;
//	//a._name = "peter";
//	// ��Ҫ��ʾָ�������ĸ�����ĳ�Ա���Խ�����������⣬�����������������޷����
//	a.Student::_name = "xxx";
//	a.Teacher::_name = "yyy";
//
//	1;
//}


//class Person
//{
//public:
//	string _name; // ����
//};
//class Student : virtual public Person
//{
//protected:
//	int _num; //ѧ��
//};
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // ְ�����
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // ���޿γ�
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
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//};
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
//	/*ע�⣺����д�����麯��ʱ����������麯���ڲ���virtual�ؼ���ʱ����ȻҲ���Թ�����д(��
//	Ϊ�̳к������麯�����̳������������������ɱ����麯������),���Ǹ���д�����Ǻܹ淶��������
//	����ʹ��*/
//	/*void BuyTicket() { cout << "��Ʊ-���" << endl; }*/
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
//// ֻ��������Student������������д��Person�����������������delete�������������
//// �������ܹ��ɶ�̬�����ܱ�֤p1��p2ָ��Ķ�����ȷ�ĵ�������������
//int main()
//{
//    Person* p1 = new Person;
//    Person* p2 = new Student;
//    delete p1;
//    delete p2;
//    return 0;
//}