#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#include"ptr.h"

/*
* ���е�auto_ptr����ָ��ʵ��˼��Ϊ ��Դ����Ȩת��
* 1. ���ܽ���׳��쳣������Դ�ͷŵ�����
* 2. ��������Դ����Ȩת�Ƶĺ���˼�룬�޶�����Դֻ����һ��
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
			autoPtr._ptr = nullptr;//��autoPtr����Դ��ת�Ƹ�*this
		}
		my_auto_ptr<T>& operator=(my_auto_ptr<T>& autoPtr)
		{
			//����Ƿ��Լ����Լ���ֵ
			if (this != &autoPtr)
			{
				//��⵱ǰ����ָ���Ƿ�����Դ---1
				if (_ptr)
				{
					delete _ptr;
				}
				_ptr = autoPtr._ptr;
				autoPtr._ptr = nullptr; // --2

				/* ���û�м���Լ����Լ���ֵ
				* ��һ�����Ὣ�������Դ�ͷ�
				* �ڶ������Ὣ��Դָ���ÿ�
				* ��ԭ���Ƿ���Դ���ͷţ�й¶��
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
		// ��ָ��һ��ʹ��
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
		my_auto_ptr<int> sp2(sp1); // ����Ȩת��

		// sp1����
		*sp2 = 10;
		cout << *sp2 << endl;
		//cout << *sp1 << endl; *sp1 == *nullptr
	}
}



