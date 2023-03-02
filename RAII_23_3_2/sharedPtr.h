#pragma once

#include"ptr.h"
#include<mutex>

/* �� + ���� + ����
* ���ü���֧�ֶ����������ͬһ����Դ�����һ�����������ͷ���Դ
*/ 
namespace sharedPtr
{
    template<class T>
    class my_shared_ptr
    {
    public:
        my_shared_ptr(T* ptr = nullptr)
            :_ptr(ptr)
            , _pRefCount(new int(1))
            , _pmtx(new mutex)
        {}
        my_shared_ptr(const my_shared_ptr<T>& sp)
            :_ptr(sp._ptr)
            , _pRefCount(sp._pRefCount)
            , _pmtx(sp._pmtx)
        {
            AddRef();
        }
        void Release()
        {
            _pmtx->lock();
            bool flag = false;
            if (--(*_pRefCount) == 0 && _ptr)
            {
                cout << "delete:" << _ptr << endl;
                delete _ptr;
                delete _pRefCount;
                flag = true;
            }
            _pmtx->unlock();
            if (flag == true)
            {
                delete _pmtx;
            }
        }
        void AddRef()
        {
            _pmtx->lock();
            ++(*_pRefCount);
            _pmtx->unlock();
        }
        my_shared_ptr<T>& operator=(const my_shared_ptr<T>& sp)
        {
            //if (this != &sp) //��ͬ������ָ�룬����ָ��ͬһ����Դ������Դָ���жϺ���
            if (_ptr != sp._ptr)//�������ͬһ����Դ
            {
                Release();
                _ptr = sp._ptr;
                _pRefCount = sp._pRefCount;
                _pmtx = sp._pmtx;
                AddRef();
            }
            return *this;
        }
        int use_count()
        {
            return *_pRefCount;
        }
        ~my_shared_ptr()
        {
            Release();
        }
        // ��ָ��һ��ʹ��
        T& operator*()
        {
            return *_ptr;
        }
        T* operator->()
        {
            return _ptr;
        }
        T* get() const
        {
            return _ptr;
        }
    private:
        T* _ptr;
        int* _pRefCount;
        mutex* _pmtx;
    };

    // �򻯰汾��weak_ptrʵ��
    template<class T>
    class my_weak_ptr
    {
    public:
        my_weak_ptr()
            :_ptr(nullptr)
        {}
        my_weak_ptr(const my_shared_ptr<T>& sp)
            :_ptr(sp.get())
        {}
        my_weak_ptr<T>& operator=(const my_shared_ptr<T>& sp)
        {
            _ptr = sp.get();
            return *this;
        }
        T& operator*()
        {
            return *_ptr;
        }
        T* operator->()
        {
            return _ptr;
        }
    private:
        T* _ptr;
    };


    void func1()
    {

        my_shared_ptr<int> sp1(new int);// ���1
        my_shared_ptr<int> sp2(sp1);
        my_shared_ptr<int> sp3(sp1);

        cout << sp1.use_count() << ' ' << sp2.use_count() << ' ' << sp3.use_count() << endl;

        my_shared_ptr<int> sp4(new int);// ���2
        my_shared_ptr<int> sp5(sp4);

        cout << sp4.use_count() << ' ' << sp5.use_count() << endl;

        sp1 = sp1;
        cout << sp1.use_count() << ' ' << sp3.use_count() << endl;
        sp1 = sp2;
        cout << sp1.use_count() << ' ' << sp2.use_count() << ' ' << sp3.use_count() << endl;

        sp1 = sp4;
        cout << sp3.use_count() << ' ' << sp4.use_count() << endl;
        sp2 = sp4;
        cout << sp1.use_count() << ' ' << sp2.use_count() << ' ' << sp3.use_count() << endl;
        sp3 = sp4;// ��ʱ ���1 ���ɵ���Դ ʹ����Ϊ0 �����ͷ�����
        cout << sp1.use_count() << ' ' << sp4.use_count() << ' ' << sp3.use_count() << endl;

        *sp1 = 2;
        *sp2 = 3;

        // ��������ʱ������ָ��ȫ�������ˣ� �ͷ� ���2 ���ɵ���Դ
    }


    struct ListNode
    {
        int _data;
        my_weak_ptr<ListNode> _prev;
        my_weak_ptr<ListNode> _next;
        ~ListNode() { cout << "~ListNode()" << endl; }
    };
    /*struct ListNode
    {
        int _data;
        my_shared_ptr<ListNode> _prev;
        my_shared_ptr<ListNode> _next;
        ~ListNode() { cout << "~ListNode()" << endl; }
    };*/
    void func2()
    {
        my_shared_ptr<ListNode> node1(new ListNode);
        my_shared_ptr<ListNode> node2(new ListNode);
        cout << node1.use_count() << endl;
        cout << node2.use_count() << endl;
        node1->_next = node2;
        node2->_prev = node1;
        cout << node1.use_count() << endl;
        cout << node2.use_count() << endl;

    }
}


