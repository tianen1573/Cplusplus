#pragma once

#include"ptr.h"

/* ��ֹ������ֵ
* ͨ��c++11�﷨����ֹ����Ĭ�Ͽ���/��ֵ��Ա����
* �򿽱�/��ֵ�ڱ�д�׶ξ��б�����������ֹ����
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
		// ��ָ��һ��ʹ��
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
