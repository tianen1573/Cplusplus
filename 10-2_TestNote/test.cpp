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

#include<assert.h>

class Car {
public:
    virtual void Drive() {}
};
class Benz :public Car {
public:
    virtual void Drive() override { cout << "Benz-����" << endl; }
    virtual void Drive(int a) { cout << "Benz-����" << endl; }

};

namespace bit
{
    class string
    {
    public:
        typedef char* iterator;
        iterator begin()
        {
            return _str;
        }
        iterator end()
        {
            return _str + _size;
        }
        string(const char* str = "")
            :_size(strlen(str))
            , _capacity(_size)
        {
            //cout << "string(char* str)" << endl;
            _str = new char[_capacity + 1];
            strcpy(_str, str);
        }
        // s1.swap(s2)
        void swap(string& s)
        {
            ::swap(_str, s._str);
            ::swap(_size, s._size);
            ::swap(_capacity, s._capacity);
        }
        // ��������
        string(const string& s)
            :_str(nullptr)
        {
            cout << "string(const string& s) -- ���" << endl;
            string tmp(s._str);
            swap(tmp);
        }
        // ��ֵ����
        string& operator=(const string& s)
        {
            cout << "string& operator=(string s) -- ���" << endl;
            string tmp(s);
            swap(tmp);
            return *this;
        }
        // �ƶ�����
        string(string&& s)
            :_str(nullptr)
            , _size(0)
            , _capacity(0)
        {
            cout << "string(string&& s) -- �ƶ�����" << endl;
            swap(s);
        }
        // �ƶ���ֵ
        string& operator=(string&& s)
        {
            cout << "string& operator=(string&& s) -- �ƶ�����" << endl;
            swap(s);
            return *this;
        }
        ~string()
        {
            delete[] _str;
            _str = nullptr;
        }
        char& operator[](size_t pos)
        {
            assert(pos < _size);
            return _str[pos];
        }
        void reserve(size_t n)
        {
            if (n > _capacity)
            {
                char* tmp = new char[n + 1];
                strcpy(tmp, _str);
                delete[] _str;
                _str = tmp;
                _capacity = n;
            }
        }
        void push_back(char ch)
        {
            if (_size >= _capacity)
            {
                size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
                reserve(newcapacity);
            }
            _str[_size] = ch;
            ++_size;
            _str[_size] = '\0';
        }
        //string operator+=(char ch)
        string& operator+=(char ch)
        {
            push_back(ch);
            return *this;
        }
        const char* c_str() const
        {
            return _str;
        }
    private:
        char* _str;
        size_t _size;
        size_t _capacity; // �������������ʶ��\0
    };
}

template<class T>
struct ListNode
{
    ListNode* _next = nullptr;
    ListNode* _prev = nullptr;
    T _data;
};
template<class T>
class List
{
    typedef ListNode<T> Node;
public:
    List()
    {
        _head = new Node;
        _head->_next = _head;
        _head->_prev = _head;
    }
    void PushBack(T&& x)
    {
        //Insert(_head, x);
        Insert(_head, std::forward<T>(x));
    }
    void PushFront(T&& x)
    {
        //Insert(_head->_next, x);
        Insert(_head->_next, std::forward<T>(x));
    }
    void Insert(Node* pos, T&& x)
    {
        Node* prev = pos->_prev;
        Node* newnode = new Node;
        newnode->_data = std::forward<T>(x); // �ؼ�λ��
        // prev newnode pos
        prev->_next = newnode;
        newnode->_prev = prev;
        newnode->_next = pos;
        pos->_prev = newnode;
    }
    void Insert(Node* pos, const T& x)
    {
        Node* prev = pos->_prev;
        Node* newnode = new Node;
        newnode->_data = x; // �ؼ�λ��
        // prev newnode pos
        prev->_next = newnode;
        newnode->_prev = prev;
        newnode->_next = pos;
        pos->_prev = newnode;
    }
private:
    Node* _head;
};
int main()
{
    List<bit::string> lt;
    lt.PushBack("1111");
    lt.PushFront("2222");
    return 0;
}

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