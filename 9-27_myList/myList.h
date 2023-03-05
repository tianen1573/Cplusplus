#pragma once

#include<assert.h>
#include<iostream>
#include<list>

using namespace std;


namespace qlz
{
	//�ڵ�ṹ
	template<typename T>//��������
	struct list_node
	{
		T _data;//Ԫ��
		list_node<T>* _next;//��ָ��
		list_node<T>* _prev;//ǰָ��

		list_node(const T& x = T())//Ĭ�Ϲ���
			:_data(x)
			, _next(nullptr)
			, _prev(nullptr)
		{}

	};


	//������֪ʶ��
	/*
	* 1. �� �������صķ�ʽ, ʵ�ַ��� ��Ա������const���� �� ��const����, ���ֵ�����������ͬ������
	* 2. ͨ��ʵ����������, ����const������, �ͷ�const������, ���ֵ��������ڲ�ͬ������, ָ�� ���÷���, ָ�뷵�ص�����
	* typedef _list_iterator<T, T&, T*>             iterator;
	* typedef _list_iterator<T, const T&, const T*> const_iterator;
	*
	* List �ĵ�����
	* ������������ʵ�ַ�ʽ������Ӧ���������ײ����ݽṹʵ�֣�
	*   1. ԭ��ָ̬�룬���磺vector
	*   2. ��ԭ��ָ̬����з�װ���������ʹ����ʽ��ָ����ȫ��ͬ��������Զ�������б���ʵ�����·�����
	* 	 1. ָ����Խ����ã������������б�������operator*()
	* 	 2. ָ�����ͨ��->��������ָ�ռ��Ա�����������б�������oprator->()
	* 	 3. ָ�����++����ƶ������������б�������operator++()��operator++(int)
	* 		����operator--()/operator--(int)�ͷ���Ҫ���أ����ݾ���Ľṹ������˫�����������ǰ�ƶ���������Ҫ���أ������forward_list�Ͳ���Ҫ����--
	* 	 4. ��������Ҫ�����Ƿ���ȵıȽϣ���˻���Ҫ����operator==()��operator!=()
	*/

	//���������
	template<typename T, typename Ref, typename Ptr>//��������, �������͵�����, �������͵�ָ��
	struct _list_iterator
	{
	public:
		typedef list_node<T> Node;
		typedef _list_iterator<T, Ref, Ptr> iterator;

		//ʹ�� std::find() ��Ҫ��Щ 
		typedef bidirectional_iterator_tag iterator_category;
		typedef T value_type;
		typedef Ptr pointer;
		typedef Ref reference;
		typedef ptrdiff_t difference_type;

		//�����������Ҫ��Щ
		typedef Ref Ref;
		typedef Ptr Ptr;

		Node* _node;

		//ָ������, ǳ��������
		_list_iterator(Node* node = nullptr)
			:_node(node)
		{}
		//Ĭ�����ɵĿ�������Ϊǳ����, ��ʹ��
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


		/* ����ѭ��˫���ͷ����
		* ���߼���, Node�ڵ�Ӧ�þ���Ԫ��, ��ʵ����, Node�ڵ� ��װ��Ԫ�غ�ǰ��ָ��
		* �߼���, ������ΪԪ�ص�"ָ��", ��Ԫ��Ϊ�ṹ������, �����ͨ�� (*). / -> ����Ԫ�صĳ�Ա����
		* ��ʵ����, ������ΪNode�ڵ��ָ��, (*). / -> ���ʵĵ��� Node�ڵ�� Ԫ�غ�ǰ��ָ��,
		* ������Ҫ�� (*). / -> ����
		* ++, -- ͬ��
		*/

		//*
		// ע��ģ������
		// const T& operator*()
		// T& operator*()
		Ref operator*()
		{
			return (_node->_data);
		}

		//->, ע��, ��Ԫ��Ϊ�ṹ������, �������������Ż�, it->(�õ�Ԫ�ص�ַ)->_val1 -----> it->_val
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

	/*���������(��д�߼�)*/
	//template<typename T, typename Ref, typename Ptr>//��������, �������͵�����, �������͵�ָ��
	//struct _reverse_list_iterator
	//{
	//	typedef list_node<T> Node;
	//	typedef _reverse_list_iterator<T, Ref, Ptr> reverse_iterator;
	//
	//	Node* _node;
	//
	//	//ָ������, ǳ��������
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
	//	/* ����ѭ��˫���ͷ����
	//	* ���߼���, Node�ڵ�Ӧ�þ���Ԫ��, ��ʵ����, Node�ڵ� ��װ��Ԫ�غ�ǰ��ָ��
	//	* �߼���, ������ΪԪ�ص�"ָ��", ��Ԫ��Ϊ�ṹ������, �����ͨ�� (*). / -> ����Ԫ�صĳ�Ա����
	//	* ��ʵ����, ������ΪNode�ڵ��ָ��, (*). / -> ���ʵĵ��� Node�ڵ�� Ԫ�غ�ǰ��ָ��,
	//	* ������Ҫ�� (*). / -> ����
	//	* ++, -- ͬ��
	//	*/
	//
	//	//*
	//	// ע��ģ������
	//	// const T& operator*()
	//	// T& operator*()
	//	Ref operator*()
	//	{
	//		Node* tmp= _node->_prev;
	//		return (tmp->_data);
	//	}
	//
	//	//->, ע��, ��Ԫ��Ϊ�ṹ������, �������������Ż�, it->(�õ�Ԫ�ص�ַ)->_val1 -----> it->_val
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
	/*���������(������)*/
	template<class iterator>
	struct _reverse_list_iterator
	{
	public:
		// ע�⣺�˴�typename����������ȷ���߱�������Ref��Iterator���е�һ�����ͣ������Ǿ�̬��Ա����
		// �������������ʱ�Ͳ�֪��Ref��Iterator�е����ͻ��Ǿ�̬��Ա����
		// ��Ϊ��̬��Ա����Ҳ�ǰ��� ����::��̬��Ա������ �ķ�ʽ���ʵ�
		typedef typename iterator::Ref Ref;
		typedef typename iterator::Ptr Ptr;
		typedef _reverse_list_iterator<iterator> reverse_iterator;
	public:
		// ����
		_reverse_list_iterator(iterator it)
			: _rit(it)
		{}

		// ����ָ��������Ϊ
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

		// ������֧���ƶ�
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

		// ������֧�ֱȽ�
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
	class list//˫���ͷѭ������
	{

	public:
		typedef list_node<T> Node;
		//ͨ��ʵ����������, ����const������, �ͷ�const������
		typedef _list_iterator<T, T&, T*> iterator;
		typedef _list_iterator<T, const T&, const T*> const_iterator;
		/*
		* ��Ȼ���� �� �������صķ�ʽ, ʵ�ַ��� ��Ա������const���� �� ��const����
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

		/*���������(������)*/
		/*typedef _reverse_list_iterator<T, T&, T*> reverse_iterator;
		typedef _reverse_list_iterator<T, const T&, const T*> const_reverse_iterator;*/
		/*���������(����)*/
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

			// ��l�е�Ԫ�ع�����ʱ��temp,Ȼ���뵱ǰ���󽻻�
			list<T> temp(l.begin(), l.end());
			this->swap(temp);
		}

		list<T>& operator=(list<T> l)
		{
			this->swap(l);
			return *this;
		}


		//���ý���
		void swap(list<T>& l)
		{
			std::swap(_head, l._head);
		}

		//�п�
		bool empty()const
		{
			return _head->_next == _head;
		}

		//Ԫ�ظ���
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

		//����Ԫ�ظ���
		void resize(size_t newsize, const T& val = T())
		{
			size_t oldsize = size();
			if (newsize <= oldsize)
			{
				// ��ЧԪ�ظ������ٵ�newsize
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

		//���
		void clear()
		{
			Node* cur = _head->_next;

			// ����ͷɾ��ɾ��
			while (cur != _head)
			{
				_head->_next = cur->_next;
				delete cur;
				cur = _head->_next;
			}
			//ֻ����ͷ�ڵ�
			_head->_next = _head->_prev = _head;
		}

		const_iterator begin() const//const����
		{
			return const_iterator(_head->_next);
		}

		const_iterator end() const//const����
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


		/*���������(����������)*/
		//const_reverse_iterator rbegin() const//const����
		//{
		//	return const_reverse_iterator(_head);
		//}
		//const_reverse_iterator rend() const//const����
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
		/*���������(��������)*/
		const_reverse_iterator rbegin() const//const����
		{
			return const_reverse_iterator(end());
		}
		const_reverse_iterator rend() const//const����
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

		//���ص�ǰ�ڵ������
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

		//������һ���ڵ�ĵ�����
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


		//��֧��[]
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
		Node* _head;//ͷ�ڵ�
	};



#pragma region ����

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
			// pos�Ƿ��ʧЧ������
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