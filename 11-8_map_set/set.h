#pragma once

#include"RBTree.h"

namespace mySet
{
	template<typename K>
	class set
	{

		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};

	public:
			typedef typename myRBT::RBT<K, K, SetKeyOfT>::iterator iterator;
			typedef typename myRBT::RBT<K, K, SetKeyOfT>::const_iterator const_iterator;

			iterator begin()
			{
				return _rbt.begin();
			}
			iterator end()
			{
				return _rbt.end();
			}

			iterator insert(const K& key)
			{
				return _rbt.insert(key).first;
			}

	private:
		myRBT::RBT<K, K, SetKeyOfT> _rbt;

	};

	void test_set()
	{
		set<int> s;

		set<int>::iterator it = s.begin();
		while (it != s.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		s.insert(3);
		s.insert(2);
		s.insert(1);
		s.insert(5);
		s.insert(3);
		s.insert(6);
		s.insert(4);
		s.insert(9);
		s.insert(7);


		it = s.begin();
		while (it != s.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

}