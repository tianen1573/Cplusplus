#define _CRT_SECURE_NO_WARNINGS 1

//此.h为反向迭代器适配器代码

namespace qlz
{
	//_iterator<class T>::iterator, T&, T*
	//_iterator<class T>::iterator, const T&, const T*
	template<class iterator>
	struct _reverse_iterator
	{
	public:
		// 注意：此处typename的作用是明确告诉编译器，Ref是Iterator类中的一个类型，而不是静态成员变量
		// 否则编译器编译时就不知道Ref是Iterator中的类型还是静态成员变量
		// 因为静态成员变量也是按照 类名::静态成员变量名 的方式访问的
		typedef typename iterator::Ref Ref;
		typedef typename iterator::Ptr Ptr;
		typedef _reverse_iterator<iterator> reverse_iterator;
	public:
		// 构造
		_reverse_iterator(iterator it)
			: _rit(it)
		{}

		// 具有指针类似行为
		Ref operator*()
		{
			iterator temp(_rit);
			--temp;
			return *temp;
		}

		Ptr operator->()
		{
			return &(operator*());
		}

		// 迭代器支持移动
		reverse_iterator& operator++()
		{
			--_rit;
			return *this;
		}

		reverse_iterator operator++(int)
		{
			reverse_iterator temp(*this);
			--_rit;
			return temp;
		}

		reverse_iterator& operator--()
		{
			++_rit;
			return *this;
		}

		reverse_iterator operator--(int)
		{
			reverse_iterator temp(*this);
			++_rit;
			return temp;
		}

		// 迭代器支持比较
		bool operator!=(const reverse_iterator& l)const
		{
			return _rit != l._rit;
		}

		bool operator==(const reverse_iterator& l)const
		{
			return _rit == l._rit;
		}

		iterator _rit;
	};
}