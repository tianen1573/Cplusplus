#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#include"ptr.h"

/*
* 库中的auto_ptr智能指针实现思想为 资源管理权转移
* 1. 他能解决抛出异常导致资源释放的问题
* 2. 但由于资源管理权转移的核心思想，限定了资源只能有一份
*/

namespace autoPtr
{
	template<class T>
	class my_auto_ptr
	{
	public:
		my_auto_ptr(T* ptr = nullptr)
			:_ptr(ptr)
		{}
		my_auto_ptr(my_auto_ptr<T>& autoPtr)
			:_ptr(autoPtr._ptr)
		{
			autoPtr._ptr = nullptr;//将autoPtr的资源，转移给*this
		}
		my_auto_ptr<T>& operator=(my_auto_ptr<T>& autoPtr)
		{
			//检测是否自己给自己赋值
			if (this != &autoPtr)
			{
				//检测当前智能指针是否有资源---1
				if (_ptr)
				{
					delete _ptr;
				}
				_ptr = autoPtr._ptr;
				autoPtr._ptr = nullptr; // --2

				/* 如果没有检测自己给自己赋值
				* 第一个语句会将管理的资源释放
				* 第二个语句会将资源指针置空
				* 则原先那份资源被释放，泄露了
				*/
			}
		}

		~my_auto_ptr()
		{
			if (_ptr)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
			}
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

	private:
		T* _ptr;

	};

	void func1()
	{
		my_auto_ptr<int> sp1(new int);
		my_auto_ptr<int> sp2(sp1); // 管理权转移

		// sp1悬空
		*sp2 = 10;
		cout << *sp2 << endl;
		//cout << *sp1 << endl; *sp1 == *nullptr
	}
}



