#pragma once

#include<iostream>
#include<vector>
#include<assert.h>

using namespace std;

namespace qlz
{
	template<class T>//模板类型

	class vector
	{
	public:

		//vector迭代器是原生指针, 我们声明两个迭代器, 类型为模板类型指针;
		typedef T* iterator;
		typedef const T* const_iterator;

		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		//const_iterator begin() const, 构成函数重载
		//因为第一个形参, 即对象的指针是不同类型, 一个是非const指针, 一个是const指针
		const_iterator cbegin() const
		{
			return _start;
		}
		const_iterator cend() const
		{
			return _finish;
		}


		//无参默认构造
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{}

		//拷贝构造
		vector(const vector<T>& vec)
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			reverse(vec.capacity());

			/*for (size_t i = 0; i < vec.size(); i++)
			{
				_start[i] = vec._start[i];
			}

			_finish = _start + vec.size();
			_endOfStorage = _start + vec.capacity();*/

			//迭代器实现
			iterator it = begin();
			const_iterator vit = vec.cbegin();
			while (vit != vec.cend())
			{
				//已设置容量
				*it++ = *vit++;
			}
			_finish = it;

		}

		//n个元素
		vector(size_t n, const T& val = T())
			//注意成员变量声明顺序
			:_start(new T[n])
			, _finish(_start + n)
			, _endOfStorage(_start + n)
		{
			for (size_t i = 0; i < n; i++)
			{
				//已设置容量
				_start[i] = val;
			}
		}
		/*
		* 理论上将，提供了vector(size_t n, const T& value = T())之后
		* vector(int n, const T& value = T())就不需要提供了，但是对于：
		* vector<int> v(10, 10);
		* 编译器在编译时，认为T已经被实例化为int，而10和10编译器会默认其为int类型,这两个类型相同
		* 本意是构造10个10，但是size_t 和 int 不是相同类型，恰好迭代器构造的两个模板参数是同一类型
		* 所以，就不会走vector(size_t n, const T& value = T())这个构造方法，而是迭代器构造
		* 因为 vector(InputIterator first, InputIterator last) 模板Inpu实例化为int时, 形参列表更符合
		* 但是10 和 10根本不是一个区间，编译时就报错了
		* 故需要该构造方法, 防止跑到迭代器构造函数
		*/
		vector(int n, const T& val = T())
			//注意成员变量声明顺序
			:_start(new T[n])
			, _finish(_start + n)
			, _endOfStorage(_start + n)
		{
			for (int i = 0; i < n; i++)
			{
				//已设置容量
				_start[i] = val;
			}
		}

		//迭代器构造
		template<class InputIterator>//迭代器模板
		vector(InputIterator first, InputIterator last)
		{
			//复用push_back
			while (first != last)
			{
				//未确定容量, 调用push_back, 每次询问是否需要扩容
				push_back(*first);
				++first;
			}
		}

		~vector()
		{
			delete[] _start;
			_start = _finish = _endOfStorage = nullptr;
		}


	private:
		bool Full()
		{
			if (_finish == _endOfStorage)
			{
				return true;
			}

			return false;
		}
	public:
		size_t capacity() const
		{
			return _endOfStorage - _start;
		}

		size_t size() const
		{
			return _finish - _start;
		}

		bool empty() const
		{
			if (_finish == _start)
			{
				return true;
			}

			return false;
		}

		void reverse(size_t n)
		{
			if (n <= capacity())
			{
				return;
			}

			size_t oldSize = size();

			T* tmp = new T[n];

			for (size_t i = 0; i < oldSize; i++)
			{
				tmp[i] = _start[i];//模板类型T的赋值运算
			}
			delete[] _start;

			_start = tmp;
			tmp = nullptr;
			_finish = _start + oldSize;
			_endOfStorage = _start + n;

		}

		void resize(size_t n, const T& val = T())
		{
			if (n <= _finish - _start)
			{
				_finish = _start + n;
			}
			else
			{
				reverse(n);

				iterator cur = _finish;
				_finish = _start + n;
				while (cur != _finish)
				{
					//已经确定容量到位, 直接使用赋值, 减少调用
					*cur = val;
					cur++;
				}
			}
		}


		//接受形参的引用, 将形参替换为空对象
		void swap(vector<T>& vec)
		{
			::swap(_start, vec._start);//std
			::swap(_finish, vec._finish);
			::swap(_endOfStorage, vec._endOfStorage);
		}



		//传元素引用, 防止无意义的深拷贝
		iterator insert(iterator it, const T& val)
		{
			assert(it <= _finish);//合法插入

			if (Full())
			{
				size_t pos = it - _start;

				reverse(capacity() == 0 ? 2 : capacity() * 2);

				it = _start + pos;//重置插入位置迭代器, 防止迭代器失效
			}

			iterator end = _finish - 1;//_finish所在地址, 为新的vector最后一个元素的位置

			while (end >= it)
			{
				*(end + 1) = *end;
				end--;
			}

			*it = val;
			_finish++;
			return it;//返回插入位置的迭代器
		}

		//复用insert
		void push_back(const T& val)
		{
			insert(_finish, val);
		}

		//返回被删除的位置的迭代器
		iterator erase(iterator it)
		{
			assert(!empty());//非空

			// 挪动数据进行删除
			iterator begin = it;
			while (begin != _finish - 1) {
				*begin = *(begin + 1);
				++begin;
			}

			--_finish;
			return it;
		}

		//复用erase
		void pop_back()
		{
			erase(_finish - 1);
		}

		vector<T>& operator= (vector<T> vec)
		{
			swap(vec);
			return *this;
		}

		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}

		const T& operator[](size_t pos)const
		{
			assert(pos < size());
			return _start[pos];
		}

		T& front()
		{
			return *_start;
		}

		const T& front()const
		{
			return *_start;
		}

		T& back()
		{
			return *(_finish - 1);
		}

		const T& back()const
		{
			return *(_finish - 1);
		}



	private:

		//左闭右开
		//没必要设置初始值, 因为会频繁使用初始化列表
		iterator _start;//头
		iterator _finish;//尾 == 头指针 + 实际大小
		iterator _endOfStorage;// == 头指针 + 最大容量
	};

	void Test1()
	{
		qlz::vector<int> v1;
		qlz::vector<int> v2(10, 5);

		int array[] = { 1,2,3,4,5 };
		qlz::vector<int> v3(array, array + sizeof(array) / sizeof(array[0]));

		qlz::vector<int> v4(v3);

		for (size_t i = 0; i < v2.size(); ++i)
		{
			cout << v2[i] << " ";
		}
		cout << endl;

		auto it = v3.begin();
		while (it != v3.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : v4)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void Test2()
	{
		qlz::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		cout << v.size() << endl;
		cout << v.capacity() << endl;
		cout << v.front() << endl;
		cout << v.back() << endl;
		cout << v[0] << endl;
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		v.pop_back();
		v.pop_back();
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		v.insert(v.begin(), 0);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		v.erase(v.begin() + 1);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		/*qlz::vector<int> vvv;
		vvv.push_back(1);
		vvv.push_back(2);
		vvv.push_back(3);
		vvv.push_back(4);
		vvv.push_back(5);

		qlz::vector<char> vv;
		vv.push_back('a');
		vv.push_back('b');
		vv.push_back('c');
		vv.push_back('d');*/

	}

	void Test3()
	{
		vector<int*> vec;
		int a = 1, b = 2, c = 3;
		vec.push_back(&a);
		vec.push_back(&c);
		vec.push_back(&b);

		for (auto& ptr : vec)
		{
			cout << *ptr << ' ';
		}


	}
}