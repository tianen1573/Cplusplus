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
			iterator it = insert(make_pair(key, V()));//�ڵ�ָ��

			return it->second;
		}

	private:
		myRBT::RBT<K, pair<K, V>, MapKeyOfT> _rbt;

	};

	void test_map()
	{
		string arr[] = { "ƻ��", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����", "ƻ��", "�㽶", "ƻ��", "�㽶" };

		map<string, int> countMap;
		for (auto& str : arr)
		{
			// 1��str����countMap�У�����pair(str, int()),Ȼ���ڶԷ��ش���++
			// 2��str��countMap�У�����value(����)�����ã�����++;
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