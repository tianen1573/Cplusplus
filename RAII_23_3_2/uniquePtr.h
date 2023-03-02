#pragma once

#include"ptr.h"

/* 禁止拷贝赋值
* 通过c++11语法，禁止生成默认拷贝/赋值成员函数
* 则拷贝/赋值在编写阶段就有编译器报错，禁止编译
*/

namespace uniquePtr
{
	template<class T>
	class my_unique_ptr
	{
	public:
		my_unique_ptr(T* ptr)
			:_ptr(ptr)
		{}
		~my_unique_ptr()
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
		my_unique_ptr(const my_unique_ptr<T>& sp) = delete;
		my_unique_ptr<T>& operator=(const my_unique_ptr<T>& sp) = delete;
	private:
		T* _ptr;
	};

	void func1()
	{
		uniquePtr::my_unique_ptr<int> sp1(new int);
		//uniquePtr::my_unique_ptr<int> sp2(sp1);

		std::unique_ptr<int> sp11(new int);
		//std::unique_ptr<int> sp2(sp1);
	}
}
