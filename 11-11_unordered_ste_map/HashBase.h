#pragma once

#include<iostream>
#include<string>
#include<vector>
using namespace std;

namespace myHash_bucket
{

	template<typename T>
	struct HashNode
	{
		T _data;
		HashNode<T>* _next;

		HashNode()
		{}

		HashNode(const T& data)
			:_data(data)
			, _next(nullptr)
		{}
	};

	//ǰ������, ��������Ҫ��ϣ��ָ��
	template<typename K, typename T, class ToINT, class KOT>
	class HashTable;

	template<typename K, typename T, class ToINT, class KOT>
	struct __hash_iterator
	{
	public:
		typedef HashNode<T> Node;
		typedef HashTable<K, T, ToINT, KOT> HT;
		typedef __hash_iterator<K, T, ToINT, KOT> Self;

		__hash_iterator()
		{}
		__hash_iterator(Node* node, HT* pht)
			:_node(node)
			, _ht(pht)
		{}
		__hash_iterator(const Self& it)
			:_node(it._node)
			, _ht(it._ht)
		{}
		~__hash_iterator()
		{}

		T& operator*() const
		{
			return _node->_data;
		}
		T* operator->() const
		{
			return &(_node->_data);
		}

		Self& operator++()
		{
			if (_node->_next)
			{
				_node = _node->_next;
			}
			else
			{
				ToINT toint;
				KOT kot;

				//_tab��˽�г�Ա�������������ʣ� ������������Ϊ��ϣ�����Ԫ�࣬����
				size_t hashi = toint(kot(_node->_data)) % _ht->_tab.size();
				++hashi;

				for (; hashi < _ht->_tab.size(); ++hashi)
				{
					if (_ht->_tab[hashi])
					{
						_node = _ht->_tab[hashi];
						break;
					}
				}

				if (hashi == _ht->_tab.size())
				{
					_node = nullptr;
				}
			}

			return *this;
		}
		Self& operator++(int)
		{
			Self tmp(*this);

			++(*this);

			return tmp;
		}

		bool operator!=(const Self& s) const
		{
			return _node != s._node;
		}

		bool operator==(const Self& s) const
		{
			return _node == s._node;
		}

	private:
		Node* _node;
		HT* _ht;
	};

	template<typename K, typename T, class ToINT, class KOT>
	class HashTable
	{
		
	public:
		
		typedef HashNode<T> Node;

		//������������Ϊ��ϣ�����Ԫ
		template<class K, class T, class Hash, class KeyOfT>
		friend struct __hash_iterator;

		typedef __hash_iterator<K, T, ToINT, KOT> iterator;

		//������������Ϊ�������� ������Ч����ģ��ȣ�����Ͱ����������
		inline size_t __stl_next_prime(size_t n)
		{
			static const size_t __stl_num_primes = 28;
			static const size_t __stl_prime_list[__stl_num_primes] =
			{
				53, 97, 193, 389, 769,
				1543, 3079, 6151, 12289, 24593,
				49157, 98317, 196613, 393241, 786433,
				1572869, 3145739, 6291469, 12582917, 25165843,
				50331653, 100663319, 201326611, 402653189, 805306457,
				1610612741, 3221225473, 4294967291
			};

			for (size_t i = 0; i < __stl_num_primes; ++i)
			{
				if (__stl_prime_list[i] > n)
				{
					return __stl_prime_list[i];
				}
			}

			return -1;
		}
	public:
		~HashTable()
		{
			for (size_t i = 0; i < _tab.size(); ++i)
			{
				Node* cur = _tab[i];
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}
				_tab[i] = nullptr;
			}
		}

		iterator begin()
		{
			for (size_t i = 0; i < _tab.size(); ++i)
			{
				if (_tab[i])
				{
					return iterator(_tab[i], this);
				}
			}

			return end();
		}
		iterator end()
		{
			return iterator(nullptr, this);
		}

		pair<iterator, bool> insert(const T& data)
		{
			KOT kot;
			ToINT toint;

			auto ret = find(kot(data));
			if (ret != end())
			{
				return make_pair(ret, false);
			}

			//��������Ϊ1,��ʾͰ���ˣ� ��Ҫ����
			if (_size == _tab.size())
			{
				//��ɢ�й�ϣ�� ����ʱ��Ҫ����insert�� ���Դ���һ����ʱ��ϣ��
				//����ɢ�й�ϣ�� �����ݽڵ���Խ��и��ã�����Ҫ����insert������ֻ�贴��һ����ʱvector
				vector<Node*> newTab;
				newTab.resize(__stl_next_prime(_tab.size()), nullptr);

				//���ɱ�����ӳ��Ǩ�Ƶ��±�
				for (auto& cur : _tab)
				{
					if (cur == nullptr) continue;

					Node* old = cur;

					while (cur)
					{
						Node* next = cur->_next;

						//ͷ��
						size_t hashi = toint(kot(cur->_data)) % newTab.size();
						cur->_next = newTab[hashi];
						newTab[hashi] = cur;

						cur = next;
					}

					//�ÿ�
					old = nullptr;
				}

				_tab.swap(newTab);
			}

			//ͷ��
			size_t hashi = toint(kot(data)) % _tab.size();
			Node* newNode = new Node(data);
			newNode->_next = _tab[hashi];
			_tab[hashi] = newNode;
			++_size;

			return make_pair(iterator(newNode, this), true);//���������ʱ����Ҫ��ϣ��ָ��

		}

		iterator find(const K& key)
		{
			if (_tab.size() == 0)
			{
				return end();
			}

			ToINT toint;
			KOT kot;
			size_t hashi = toint(key) % _tab.size();
			Node* cur = _tab[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					return iterator(cur, this);
				}

				cur = cur->_next;
			}



			return end();
		}

		bool erase(const K& key)
		{
			if (_tab.size() == 0)
			{
				return false;
			}

			ToINT toint;
			KOT kot;
			size_t hashi = toint(key) % _tab.size();
			Node* prev = nullptr;
			Node* cur = _tab[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					break;
				}

				prev = cur;
				cur = cur->_next;
			}

			//������
			if (cur == nullptr)
			{
				return false;
			}
			else if (prev == nullptr)//Ϊ��һ��
			{
				_tab[hashi] = cur->_next;
			}
			else
			{
				prev->_next = cur->_next;
			}

			delete cur;
			cur = nullptr;
			--_size;

			return true;
		}

		size_t size()
		{
			return _size;
		}

	private:
		vector<Node*> _tab;
		size_t _size = 0;
	};

}


