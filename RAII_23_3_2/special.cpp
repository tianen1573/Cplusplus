#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//class HeapOnly
//{
//public:
//    void DeleteHeap()//1
//    {
//        delete this;//���ڿɵ�������
//    }
//
//    static void s_DeleteHeap(HeapOnly* p)//2
//    {
//        delete p;//���ڿɵ�������
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
//    // ����operator new���԰�������new ���ÿ�������������������
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

//// ����ģʽ
//// �ŵ㣺��
//// ȱ�㣺���ܻᵼ�½�����������������ж�����������ʵ������˳��ȷ����
//class Singleton
//{
//public:
//    static Singleton* GetInstance()
//    {
//        return &m_instance;
//    }
//
//private:
//    // ���캯��˽��
//    Singleton() {};
//
//    // C++98 ������
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
//Singleton Singleton::m_instance;  // �ڳ������֮ǰ����ɵ�������ĳ�ʼ��

// ����
// �ŵ㣺��һ��ʹ��ʵ������ʱ���������󡣽��������޸��ء��������ʵ������˳�����ɿ��ơ�
// ȱ�㣺����
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;
class Singleton
{
public:
	static Singleton* GetInstance() {
		// ע������һ��Ҫʹ��Double-Check�ķ�ʽ���������ܱ�֤Ч�ʺ��̰߳�ȫ
		if (nullptr == m_pInstance) {
			m_mtx.lock();
			if (nullptr == m_pInstance) {
				m_pInstance = new Singleton();
			}
			m_mtx.unlock();
		}
		return m_pInstance;
	}
	// ʵ��һ����Ƕ����������    
	// �����������
	class CGarbo {
	public:
		~CGarbo() {
			if (Singleton::m_pInstance)
				delete Singleton::m_pInstance;
		}
	};
	// ����һ����̬��Ա�������������ʱ��ϵͳ���Զ������������������Ӷ��ͷŵ�������
	static CGarbo Garbo;
private:
	// ���캯��˽��
	Singleton() {};
	// ������
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);

	static Singleton* m_pInstance; // ��������ָ��
	static mutex m_mtx;   //������
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
