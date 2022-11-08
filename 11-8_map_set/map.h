#pragma once

#include"RBTree.h"

namespace myMap
{
	template<typename K, typename V>
	class map
	{

		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V> & kv)
			{
				return kv.first;
			}
		};

	public:
		typedef typename myRBT::RBT<K, pair<K, V>, MapKeyOfT>::iterator iterator;
		typedef typename myRBT::RBT<K, pair<K, V>, MapKeyOfT>::const_iterator const_iterator;

		iterator begin()
		{
			return _rbt.begin();
		}
		iterator end()
		{
			return _rbt.end();
		}

		iterator insert(const pair<K, V>& kv)
		{
			return _rbt.insert(kv).first;
		}

		V& operator[](const K& key)
		{
			iterator it = insert(make_pair(key, V()));//节点指针

			return it->second;
		}

	private:
		myRBT::RBT<K, pair<K, V>, MapKeyOfT> _rbt;

	};

	void test_map()
	{
		string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };

		map<string, int> countMap;
		for (auto& str : arr)
		{
			// 1、str不在countMap中，插入pair(str, int()),然后在对返回次数++
			// 2、str在countMap中，返回value(次数)的引用，次数++;
			countMap[str]++;
		}

		map<string, int>::iterator it = countMap.begin();
		while (it != countMap.end())
		{
			cout << it->first << ":" << it->second << endl;
			++it;
		}

		for (auto& kv : countMap)
		{
			cout << kv.first << ":" << kv.second << endl;
		}
	}

}