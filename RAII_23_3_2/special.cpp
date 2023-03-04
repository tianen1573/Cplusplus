#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//class HeapOnly
//{
//public:
//    void DeleteHeap()//1
//    {
//        delete this;//类内可调用析构
//    }
//
//    static void s_DeleteHeap(HeapOnly* p)//2
//    {
//        delete p;//类内可调用析构
//    }
//    
//private:
//    ~HeapOnly()
//    {
//        cout << "~HeapOnly" << endl;
//    }
//};
//
//int main()
//{
//    //HeapOnly ho;
//
//    HeapOnly* ho1 = new HeapOnly();
//    ho1->DeleteHeap();
//
//    HeapOnly* ho2 = new HeapOnly();
//    ho2->s_DeleteHeap(ho2);
//
//    return 0;
//}

//class HeapOnly
//{
//public:
//    static HeapOnly* CreateObject()
//    {
//        return new HeapOnly;
//    }
//
//    HeapOnly(const HeapOnly&)
//    {
//        cout << "CopyHeapOnly()" << endl;
//    }
//    /*HeapOnly& operator=(const HeapOnly& ho)
//    {
//        cout << "operator=HeapOnly()" << endl;
//
//        return *this;
//    }*/
//private:
//    HeapOnly() 
//    {
//        cout << "HeapOnly()" << endl;
//    }
//
//    void operator=(const HeapOnly& ho);
//    //HeapOnly(const HeapOnly& ho) = delete;
//
//};
//
//int main()
//{
//    //HeapOnly ho;
//
//    HeapOnly* ho1 = HeapOnly::CreateObject();
//
//    //HeapOnly ho2(*ho1);
//    //ho2 = *ho1;
//
//
//    return 0;
//}

//class StackOnly
//{
//public:
//    static StackOnly CreateObj()
//    {
//        return StackOnly();
//    }
//
//    // 禁掉operator new可以把下面用new 调用拷贝构造申请对象给禁掉
//    // StackOnly obj = StackOnly::CreateObj();
//    // StackOnly* ptr3 = new StackOnly(obj);
//    void* operator new(size_t size) = delete;
//    void operator delete(void* p) = delete;
//private:
//    StackOnly()
//        :_a(0)
//    {}
//private:
//    int _a;
//};

//// 饿汉模式
//// 优点：简单
//// 缺点：可能会导致进程启动慢，且如果有多个单例类对象实例启动顺序不确定。
//class Singleton
//{
//public:
//    static Singleton* GetInstance()
//    {
//        return &m_instance;
//    }
//
//private:
//    // 构造函数私有
//    Singleton() {};
//
//    // C++98 防拷贝
//    Singleton(Singleton const&);
//    Singleton& operator=(Singleton const&);
//    // or
//    // C++11
//    Singleton(Singleton const&) = delete;
//    Singleton& operator=(Singleton const&) = delete;
//
//    static Singleton m_instance;
//};
//
//Singleton Singleton::m_instance;  // 在程序入口之前就完成单例对象的初始化

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
	// 后构造的先析构
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
Singleton::CGarbo Garbo;
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
