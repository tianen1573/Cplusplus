#pragma once

#include"HashBase.h"

namespace myUnMap
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

	template<class K, class V, class ToINT = HashToINT<K>>
	class unordered_map
	{
	private:
		struct KeyOfT
		{
			//可不对K修饰，对pair整体修饰
			const K& operator()(const pair<const K, V>& kv)
			{
				return kv.first;
			}
		};

	public:
		//template<typename K, typename T, class ToINT, class KOT>
		typedef  myHash_bucket::HashTable<K, pair<const K, V>, HashToINT<K>, KeyOfT> HT;
		typedef typename HT::iterator iterator;

		iterator begin()
		{
			return _ht.begin();
		}
		iterator end()
		{
			return _ht.end();
		}
		pair<iterator, bool> insert(const pair<const K,V>& kv)
		{
			return _ht.insert(kv);
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

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = _ht.insert(make_pair(key, V()));

			return ret.first->second;
		}

	private:
		HT _ht;

	};

	void test_map()
	{
		unordered_map<string, string> dict;
		dict.insert(make_pair("sort", "排序"));
		dict.insert(make_pair("string", "字符串"));
		dict.insert(make_pair("left", "左边"));

		unordered_map<string, string>::iterator it = dict.begin();
		while (it != dict.end())
		{
			cout << it->first << ":" << it->second << endl;
			++it;
		}
		cout << endl;

		unordered_map<string, int> countMap;
		string arr[] = { "苹果", "", "苹果", "梨子", "苹果", "苹果", "西瓜", "苹果", "西瓜", "西瓜", "西瓜" };
		for (auto e : arr)
		{
			countMap[e]++;
		}

		for (auto& kv : countMap)
		{
			cout << kv.first << ":" << kv.second << endl;
		}

		countMap.erase("苹果");
		countMap.erase("香蕉");
		cout << endl;

		auto itt = countMap.find("西瓜");
		if (itt != countMap.end())
		{
			cout << itt->first << ":" << itt->second << endl;
		}
		

		for (auto& kv : countMap)
		{
			cout << kv.first << ":" << kv.second << endl;
		}
	}
}
