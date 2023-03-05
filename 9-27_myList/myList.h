#pragma once

#include<assert.h>
#include<iostream>
#include<list>

using namespace std;


namespace qlz
{
	//节点结构
	template<typename T>//数据类型
	struct list_node
	{
		T _data;//元素
		list_node<T>* _next;//后指针
		list_node<T>* _prev;//前指针

		list_node(const T& x = T())//默认构造
			:_data(x)
			, _next(nullptr)
			, _prev(nullptr)
		{}

	};


	//迭代器知识点
	/*
	* 1. 以 函数重载的方式, 实现返回 成员变量的const引用 和 非const引用, 两种迭代器属于相同的类型
	* 2. 通过实例化的区别, 生成const迭代器, 和非const迭代器, 两种迭代器属于不同的类型, 指定 引用返回, 指针返回的类型
	* typedef _list_iterator<T, T&, T*>             iterator;
	* typedef _list_iterator<T, const T&, const T*> const_iterator;
	*
	* List 的迭代器
	* 迭代器有两种实现方式，具体应根据容器底层数据结构实现：
	*   1. 原生态指针，比如：vector
	*   2. 将原生态指针进行封装，因迭代器使用形式与指针完全相同，因此在自定义的类中必须实现以下方法：
	* 	 1. 指针可以解引用，迭代器的类中必须重载operator*()
	* 	 2. 指针可以通过->访问其所指空间成员，迭代器类中必须重载oprator->()
	* 	 3. 指针可以++向后移动，迭代器类中必须重载operator++()与operator++(int)
	* 		至于operator--()/operator--(int)释放需要重载，根据具体的结构来抉择，双向链表可以向前移动，所以需要重载，如果是forward_list就不需要重载--
	* 	 4. 迭代器需要进行是否相等的比较，因此还需要重载operator==()与operator!=()
	*/

	//正向迭代器
	template<typename T, typename Ref, typename Ptr>//数据类型, 数据类型的引用, 数据类型的指针
	struct _list_iterator
	{
	public:
		typedef list_node<T> Node;
		typedef _list_iterator<T, Ref, Ptr> iterator;

		//使用 std::find() 需要这些 
		typedef bidirectional_iterator_tag iterator_category;
		typedef T value_type;
		typedef Ptr pointer;
		typedef Ref reference;
		typedef ptrdiff_t difference_type;

		//反向迭代器需要这些
		typedef Ref Ref;
		typedef Ptr Ptr;

		Node* _node;

		//指针类型, 浅拷贝即可
		_list_iterator(Node* node = nullptr)
			:_node(node)
		{}
		//默认生成的拷贝构造为浅拷贝, 可使用
		/*_list_iterator(const iterator& it)
			:_node(it._node)
		{}*/

		//!=
		bool operator!=(const iterator& it) const
		{
			return _node != it._node;
		}

		//==
		bool operator==(const iterator& it) const
		{
			return _node == it._node;
		}


		/* 对于循环双向带头链表
		* 在逻辑上, Node节点应该就是元素, 而实际上, Node节点 封装了元素和前后指针
		* 逻辑上, 迭代器为元素的"指针", 若元素为结构体类型, 则可以通过 (*). / -> 访问元素的成员变量
		* 但实际上, 迭代器为Node节点的指针, (*). / -> 访问的的是 Node节点的 元素和前后指针,
		* 所以需要对 (*). / -> 重载
		* ++, -- 同理
		*/

		//*
		// 注意模板类型
		// const T& operator*()
		// T& operator*()
		Ref operator*()
		{
			return (_node->_data);
		}

		//->, 注意, 若元素为结构体类型, 编译器进行了优化, it->(得到元素地址)->_val1 -----> it->_val
		Ptr operator->()
		{
			return &(operator*());
		}

		// ++it
		iterator& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		// it++
		iterator operator++(int)
		{
			iterator tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		// --it
		iterator& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		// it--
		iterator operator--(int)
		{
			iterator tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

	};

	/*反向迭代器(重写逻辑)*/
	//template<typename T, typename Ref, typename Ptr>//数据类型, 数据类型的引用, 数据类型的指针
	//struct _reverse_list_iterator
	//{
	//	typedef list_node<T> Node;
	//	typedef _reverse_list_iterator<T, Ref, Ptr> reverse_iterator;
	//
	//	Node* _node;
	//
	//	//指针类型, 浅拷贝即可
	//	_reverse_list_iterator(Node* node = nullptr)
	//		:_node(node)
	//	{}
	//
	//	//!=
	//	bool operator!=(const reverse_iterator& it) const
	//	{
	//		return _node != it._node;
	//	}
	//
	//	//==
	//	bool operator==(const reverse_iterator& it) const
	//	{
	//		return _node == it._node;
	//	}
	//
	//
	//	/* 对于循环双向带头链表
	//	* 在逻辑上, Node节点应该就是元素, 而实际上, Node节点 封装了元素和前后指针
	//	* 逻辑上, 迭代器为元素的"指针", 若元素为结构体类型, 则可以通过 (*). / -> 访问元素的成员变量
	//	* 但实际上, 迭代器为Node节点的指针, (*). / -> 访问的的是 Node节点的 元素和前后指针,
	//	* 所以需要对 (*). / -> 重载
	//	* ++, -- 同理
	//	*/
	//
	//	//*
	//	// 注意模板类型
	//	// const T& operator*()
	//	// T& operator*()
	//	Ref operator*()
	//	{
	//		Node* tmp= _node->_prev;
	//		return (tmp->_data);
	//	}
	//
	//	//->, 注意, 若元素为结构体类型, 编译器进行了优化, it->(得到元素地址)->_val1 -----> it->_val
	//	Ptr operator->()
	//	{
	//		return &(operator*());
	//	}
	//
	//	// ++it
	//	reverse_iterator& operator++()
	//	{
	//		_node = _node->_prev;
	//		return *this;
	//	}
	//
	//	// it++
	//	reverse_iterator operator++(int)
	//	{
	//		reverse_iterator tmp(*this);
	//		_node = _node->_prev;
	//		return tmp;
	//	}
	//
	//	// --it
	//	reverse_iterator& operator--()
	//	{
	//		_node = _node->_next;
	//		return *this;
	//	}
	//
	//	// it--
	//	reverse_iterator operator--(int)
	//	{
	//		iterator tmp(*this);
	//		_node = _node->_next;
	//		return tmp;
	//	}
	//
	//};
	/*反向迭代器(适配器)*/
	template<class iterator>
	struct _reverse_list_iterator
	{
	public:
		// 注意：此处typename的作用是明确告诉编译器，Ref是Iterator类中的一个类型，而不是静态成员变量
		// 否则编译器编译时就不知道Ref是Iterator中的类型还是静态成员变量
		// 因为静态成员变量也是按照 类名::静态成员变量名 的方式访问的
		typedef typename iterator::Ref Ref;
		typedef typename iterator::Ptr Ptr;
		typedef _reverse_list_iterator<iterator> reverse_iterator;
	public:
		// 构造
		_reverse_list_iterator(iterator it)
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
			return _rit != l._rit;
		}

		iterator _rit;
	};

	//List
	template<typename T>
	class list//双向带头循环链表
	{

	public:
		typedef list_node<T> Node;
		//通过实例化的区别, 生成const迭代器, 和非const迭代器
		typedef _list_iterator<T, T&, T*> iterator;
		typedef _list_iterator<T, const T&, const T*> const_iterator;
		/*
		* 仍然可以 以 函数重载的方式, 实现返回 成员变量的const引用 和 非const引用
		* eg
		* typedef const _list_iterator<T, T&, T*> const_iterator;
		*
		* const iterator begin() const
		* {
		* 	return const iterator(_head->_next);
		* }
		*
		* const iterator end() const
		* {
		* 	return const iterator(_head);
		* }
		*
		* T& operator*()
		* {
		* 	return (it->_data);
		* }
		* const T& operator*() const
		* {
		* 	return (it->_data);
		* }
		*/

		/*反向迭代器(不复用)*/
		/*typedef _reverse_list_iterator<T, T&, T*> reverse_iterator;
		typedef _reverse_list_iterator<T, const T&, const T*> const_reverse_iterator;*/
		/*反向迭代器(复用)*/
		typedef _reverse_list_iterator<iterator> reverse_iterator;
		typedef _reverse_list_iterator<const_iterator> const_reverse_iterator;



		list()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		list(size_t n, const T& value = T())
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;

			for (int i = 0; i < n; ++i)
				push_back(value);
		}

		list(int n, const T& value = T())
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;

			for (int i = 0; i < n; ++i)
				push_back(value);
		}

		template <class Iterator>
		list(Iterator first, Iterator last)
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;

			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		list(const list<T>& l)
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;

			// 用l中的元素构造临时的temp,然后与当前对象交换
			list<T> temp(l.begin(), l.end());
			this->swap(temp);
		}

		list<T>& operator=(list<T> l)
		{
			this->swap(l);
			return *this;
		}


		//内置交换
		void swap(list<T>& l)
		{
			std::swap(_head, l._head);
		}

		//判空
		bool empty()const
		{
			return _head->_next == _head;
		}

		//元素个数
		size_t size()const
		{
			Node* cur = _head->_next;
			size_t count = 0;
			while (cur != _head)
			{
				count++;
				cur = cur->_next;
			}

			return count;
		}

		//设置元素个数
		void resize(size_t newsize, const T& val = T())
		{
			size_t oldsize = size();
			if (newsize <= oldsize)
			{
				// 有效元素个数减少到newsize
				while (newsize < oldsize)
				{
					pop_back();
					oldsize--;
				}
			}
			else
			{
				while (oldsize < newsize)
				{
					push_back(val);
					oldsize++;
				}
			}
		}

		//清空
		void clear()
		{
			Node* cur = _head->_next;

			// 采用头删除删除
			while (cur != _head)
			{
				_head->_next = cur->_next;
				delete cur;
				cur = _head->_next;
			}
			//只保留头节点
			_head->_next = _head->_prev = _head;
		}

		const_iterator begin() const//const对象
		{
			return const_iterator(_head->_next);
		}

		const_iterator end() const//const对象
		{
			return const_iterator(_head);
		}

		iterator begin()
		{
			return iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}


		/*反向迭代器(不复用正向)*/
		//const_reverse_iterator rbegin() const//const对象
		//{
		//	return const_reverse_iterator(_head);
		//}
		//const_reverse_iterator rend() const//const对象
		//{
		//	return const_reverse_iterator(_head->_next);
		//}
		//reverse_iterator rbegin()
		//{
		//	return reverse_iterator(_head);
		//}
		//reverse_iterator rend()
		//{
		//	return reverse_iterator(_head->_next);
		//}
		/*反向迭代器(复用正向)*/
		const_reverse_iterator rbegin() const//const对象
		{
			return const_reverse_iterator(end());
		}
		const_reverse_iterator rend() const//const对象
		{
			return const_reverse_iterator(begin());
		}
		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}
		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}


		void push_back(const T& val)
		{
			Node* node = new Node(val);

			Node* tail = _head->_prev;
			tail->_next = node;
			node->_prev = tail;
			node->_next = _head;
			_head->_prev = node;
		}

		//返回当前节点迭代器
		iterator insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;

			Node* newnode = new Node(x);

			// prev newnode cur
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;

			return iterator(newnode);
		}

		//返回下一个节点的迭代器
		iterator erase(iterator pos)
		{
			assert(pos != end());

			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;

			prev->_next = next;
			next->_prev = prev;
			delete cur;

			return iterator(next);
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}


		//不支持[]
		T& front()
		{
			return _head->_next->_val;
		}
		const T& front()const
		{
			return _head->_next->_val;
		}
		T& back()
		{
			return _head->_prev->_val;
		}
		const T& back()const
		{
			return _head->_prev->_val;
		}


	private:
		Node* _head;//头节点
	};



#pragma region 测试

	/*void ttest1()
		{
			list<int> lis1;
			lis1.push_back(1);
			lis1.push_back(2);
			lis1.push_back(3);
		}
		struct pPos
		{
			int _a1;
			int _a2;
			pPos(int a1 = 0, int a2 = 0)
				:_a1(a1)
				, _a2(a2)
			{}
		};
		void ttest2()
		{
			int x = 10;
			int* p1 = &x;
			cout << *p1 << endl;
			pPos aa;
			pPos* p2 = &aa;
			p2->_a1;
			p2->_a2;
			list<pPos> lt;
			lt.push_back(pPos(10, 20));
			lt.push_back(pPos(10, 21));
			list<pPos>::iterator it = lt.begin();

			cout << endl;
		}
		void FFunc(const list<int>& l)
		{
			list<int>::const_iterator it = l.begin();
			*it;

			cout << endl;
		}*/

	void test11()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		it = lt.begin();
		while (it != lt.end())
		{
			*it *= 2;
			++it;
		}
		cout << endl;

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	struct Pos
	{
		int _a1;
		int _a2;

		Pos(int a1 = 0, int a2 = 0)
			:_a1(a1)
			, _a2(a2)
		{}
	};
	void test22()
	{
		int x = 10;
		int* p1 = &x;

		cout << *p1 << endl;

		Pos aa;
		Pos* p2 = &aa;
		p2->_a1;
		p2->_a2;

		list<Pos> lt;
		lt.push_back(Pos(10, 20));
		lt.push_back(Pos(10, 21));

		list<Pos>::iterator it = lt.begin();
		while (it != lt.end())
		{
			//cout << (*it)._a1 << ":" << (*it)._a2 << endl;
			cout << it->_a1 << ":" << it->_a2 << endl;

			++it;
		}
		cout << endl;
	}
	void Funcc(const list<int>& l)
	{
		list<int>::const_iterator it = l.begin();
		while (it != l.end())
		{
			//*it = 10;

			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
	void test33()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		Funcc(lt);
	}
	void test44()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		it = lt.begin();
		while (it != lt.end())
		{
			*it *= 2;
			++it;
		}
		cout << endl;

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		lt.push_front(10);
		lt.push_front(20);
		lt.push_front(30);
		lt.push_front(40);

		lt.pop_back();
		lt.pop_back();

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		auto pos = find(lt.begin(), lt.end(), 4);
		if (pos != lt.end())
		{
			// pos是否会失效？不会
			lt.insert(pos, 40);
			//lt.insert(pos, 30);
			*pos *= 100;
		}

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	void test55()
	{
		list<int> l1;
		l1.push_back(4);
		l1.push_back(1);
		l1.push_back(3);
		l1.push_back(2);

		/*auto it = l1.begin();
		cout << *it << endl;
		auto rit = l1.rbegin();
		cout << *rit;*/

		for (auto rit = l1.rbegin(); rit != l1.rend(); rit++)
			cout << *rit << endl;



	}
#pragma endregion


}