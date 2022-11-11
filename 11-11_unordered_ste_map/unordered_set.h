#pragma once

#include"HashBase.h"

namespace myUnSet
{
	//将key转换为size_t类型
	template<typename K>
	struct HashToINT
	{
		size_t operator()(const K& key)
		{
			return (size_t)key;
		}
	};
	//对string类型进行特化
	template<>
	struct HashToINT<string>
	{
		//BKDR思想
		size_t operator()(const string& key)
		{
			size_t res = 0;
			for (auto& ch : key)
			{
				res *= 131;
				res += ch;
			}

			return res;
		}
	};

	template<class K, class ToINT = HashToINT<K>>
	class unordered_set
	{
	private:
		struct KeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
		
	public:
		//template<typename K, typename T, class ToINT, class KOT>
		typedef  myHash_bucket::HashTable<K, const K, HashToINT<K>, KeyOfT> HT;
		typedef typename HT::iterator iterator;

		iterator begin()
		{
			return _ht.begin();
		}
		iterator end()
		{
			return _ht.end();
		}
		pair<iterator, bool> insert(const K& key)
		{
			return _ht.insert(key);
		}
		bool erase(const K& key)
		{
			return _ht.erase(key);
		}
		iterator find(const K& key)
		{
			return _ht.find(key);
		}
		size_t size()
		{
			return _ht.size();
		}

	private:
		HT _ht;

	};

	void test_set()
	{
		unordered_set<int> s;
		s.insert(2);
		s.insert(3);
		s.insert(1);
		s.insert(2);
		s.insert(5);

		//unordered_set<int>::iterator it = s.begin();
		auto it = s.begin();
		while (it != s.end())
		{
			cout << *it << " ";
			++it;
		}

		auto find_1 = s.find(1);
		if (find_1 != s.end())
		{
			cout << *find_1;
		}

		cout << endl;
	}
}
