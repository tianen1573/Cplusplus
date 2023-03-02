#pragma once

#include"ptr.h"
#include<mutex>

/* 锁 + 计数 + 引用
* 引用计数支持多个拷贝管理同一个资源，最后一个析构对象释放资源
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
            //if (this != &sp) //不同的智能指针，可能指向同一份资源，用资源指针判断合理
            if (_ptr != sp._ptr)//如果不是同一份资源
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
        // 像指针一样使用
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

    // 简化版本的weak_ptr实现
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

        my_shared_ptr<int> sp1(new int);// 语句1
        my_shared_ptr<int> sp2(sp1);
        my_shared_ptr<int> sp3(sp1);

        cout << sp1.use_count() << ' ' << sp2.use_count() << ' ' << sp3.use_count() << endl;

        my_shared_ptr<int> sp4(new int);// 语句2
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
        sp3 = sp4;// 此时 语句1 生成的资源 使用者为0 触发释放条件
        cout << sp1.use_count() << ' ' << sp4.use_count() << ' ' << sp3.use_count() << endl;

        *sp1 = 2;
        *sp2 = 3;

        // 函数结束时，智能指针全部析构了， 释放 语句2 生成的资源
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


