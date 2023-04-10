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

#include<assert.h>

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


// 懒汉
// 优点：第一次使用实例对象时，创建对象。进程启动无负载。多个单例实例启动顺序自由控制。
// 缺点：复杂
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;
class Singleton
{
public:
	static Singleton* GetInstance() {
		// 注意这里一定要使用Double-Check的方式加锁，才能保证效率和线程安全
		if (nullptr == m_pInstance) {
			m_mtx.lock();
			if (nullptr == m_pInstance) {
				m_pInstance = new Singleton();
			}
			m_mtx.unlock();
		}
		return m_pInstance;
	}
	// 实现一个内嵌垃圾回收类    
	class CGarbo {
	public:
		~CGarbo() {
			if (Singleton::m_pInstance)
				delete Singleton::m_pInstance;
		}
	};
	// 定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数从而释放单例对象
	static CGarbo Garbo;
private:
	// 构造函数私有
	Singleton() {};
	// 防拷贝
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);

	static Singleton* m_pInstance; // 单例对象指针
	static mutex m_mtx;   //互斥锁
};
Singleton* Singleton::m_pInstance = nullptr;
Singleton::CGarbo Singleton::Garbo;
mutex Singleton::m_mtx;


int main()
{
	thread t1([] {cout << Singleton::GetInstance() << endl; });
	thread t2([] {cout << Singleton::GetInstance() << endl; });
	t1.join();
	t2.join();
	cout << Singleton::GetInstance() << endl;
	cout << Singleton::GetInstance() << endl;
	return 0;
}
