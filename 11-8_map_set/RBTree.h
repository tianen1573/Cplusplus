#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<vector>
#include<assert.h>
#include<set>

using namespace std;

#define x first 
#define y second 

namespace myRBT
{
	enum Colour
	{
		RED,
		BLACK
	};

	//节点
	template<typename T>
	struct RBTNode
	{

		T _data;
		Colour _colour;
		struct RBTNode<T>* _left;
		struct RBTNode<T>* _right;
		struct RBTNode<T>* _parent;

		RBTNode(const T& data)
			:_data(data)
			, _colour(RED)
			, _left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
		{}
	};

	//迭代器
	template<typename T, typename Ref, typename Ptr>
	struct __RBTreeIterator
	{
		typedef RBTNode<T> Node;
		typedef __RBTreeIterator<T, Ref, Ptr> Self;

		Node* _node;

		__RBTreeIterator(Node* node)
			:_node(node)
		{}

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &(_node->_data);
		}

		bool operator!=(const Self& it) const
		{
			return _node != it._node;
		}

		bool operator==(const Self& it) const
		{
			return _node == it._node;
		}

		Self& operator++()
		{
			//左中右， 中序遍历， 
			
			//遍历到该节点时， 该节点为 ‘根节点’，访问右子树
			//若当前节点有右孩子，则++为其右子树的最左节点
			if (_node->_right)
			{
				Node* left = _node->_right;

				while (left->_left)
				{
					left = left->_left;
				}

				_node = left;
			}
			//若没有右子树，则这颗子树已经访问完了，向上至父亲为根节点的树
			//若原树为左子树， 则父节点还未访问， 若为右子树，则父节点的树所在的树也访问完毕
			//继续向上， 直至 有 作为左子树的节点出现 或者 全部访问完
			else
			{
				Node* parent = _node->_parent;
				Node* cur = _node;

				//父节点不存在则为根节点
				//为右子树仍需向上遍历
				while (parent && cur == parent->_right)
				{
					parent = parent->_parent;
					cur = cur->_parent;
				}

				_node = parent;
			}


			return *this;
		}

		Self& operator--()
		{
			//左中右， 中序遍历， 

			//遍历到该节点时， 该节点为 ‘根节点’，则其上一个节点为左子树的最右节点
			//若当前节点有左孩子，则--为其左子树的最右节点
			if (_node->_left)
			{
				Node* right = _node->_left;

				while (right->_right)
				{
					right = right->_right;
				}

				_node = right;
			}
			//若没有左子树，则其父节点访问之后， 直接访问了该节点
			//若原树为左子树， 则父节点还未访问， 若为右子树，则父节点已被访问，且就是--
			else
			{
				Node* parent = _node->_parent;
				Node* cur = _node;

				while (parent && cur == parent->_left)
				{
					cur = cur->_parent;
					parent = parent->_parent;
				}

				_node = parent;
			}


			return *this;
		}

	};

	template<typename K, typename T, typename KeyOfT>
	struct RBT
	{
	public:
		typedef RBTNode<T> Node;
		typedef __RBTreeIterator<T, T&, T*> iterator;
		typedef __RBTreeIterator<T, const T&, const T*> const_iterator;


		RBT()
			:_root(nullptr)
		{}
		RBT(const RBT<K, T, KeyOfT>& rbt)
		{
			_root = _myCopy(rbt._root);
		}
		RBT<K, T, KeyOfT>& operator= (RBT<K, T, KeyOfT> rbt)//形参是深拷贝出来的， 在函数结束时会销毁
		{
			swap(_root, rbt._root);

			return (*this);
		}
		~RBT()
		{
			_Destory(_root);
		}

		iterator begin()
		{
			Node* left = _root;

			while (left && left->_left)
			{
				left = left->_left;
			}

			return iterator(left);
		}
		iterator end()
		{
			return iterator(nullptr);
		}

		const_iterator cbegin() const
		{
			Node* left = _root;

			while (left && left->_left)
			{
				left = left->_left;
			}

			return (const_iterator)left;
		}
		const_iterator cend() const
		{
			return (const_iterator)nullptr;
		}

		pair<iterator, bool> insert(const T& data)
		{
			KeyOfT kot;

			if (_root == nullptr)
			{
				_root = new Node(data);
				_root->_colour = BLACK;
				return make_pair(iterator(_root), true);
			}

			Node* parent = _root;
			Node* cur = _root;

			while (cur)
			{

				if (kot(data) > kot(cur->_data))
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (kot(data) < kot(cur->_data))
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return make_pair(iterator(cur), false);
				}
			}

			//初始化新节点
			cur = new Node(data);
			cur->_parent = parent;
			if (kot(data) > kot(parent->_data))
			{
				parent->_right = cur;
			}
			else
			{
				parent->_left = cur;
			}
			Node* ret = cur;

			//控制平衡
			//父亲存在， 父亲为黑色,符合红黑树; 父亲为红色，进行调整
			//父亲不存在，则为根节点，只需调整根节点的颜色
			while (parent && parent->_colour == RED)
			{
				Node* grandfat = parent->_parent;
				assert(grandfat);//因为父节点为红色， 则其一定有一个黑色父节点
				assert(grandfat->_colour == BLACK);

				//叔叔在右边
				if (parent == grandfat->_left)
				{
					Node* uncle = grandfat->_right;
					//1. 叔叔存在， 且叔叔为红色
					//则 将父亲和叔叔变为黑色，爷爷变成红色，继续向上调整
					if (uncle && uncle->_colour == RED)
					{
						parent->_colour = BLACK;
						uncle->_colour = BLACK;
						grandfat->_colour = RED;
						//令 cur = grandfat, 继续向上处理
						cur = grandfat;
						parent = cur->_parent;
					}
					//叔叔不存在，或者叔叔存在且为黑色
					//则 需要旋转并变色
					else
					{
						if (cur == parent->_left)
						{
							// 2. 左子树的左子树
							//    g
							//  p   u
							//c
							//爷爷节点右旋，父变黑，祖变红
							RotateR(grandfat);
							grandfat->_colour = RED;
							parent->_colour = BLACK;
						}
						else
						{
							// 2. 左子树的右子树
							//      g
							//  p       u
							//    c
							//父亲节点左旋，爷爷节点右旋，自己变黑，祖变红
							RotateL(parent);
							RotateR(grandfat);
							cur->_colour = BLACK;
							grandfat->_colour = RED;
						}

						break;// 调整后符合红黑树
					}
				}
				else//叔叔在左边
				{
					Node* uncle = grandfat->_left;
					//1. 叔叔存在， 且叔叔为红色
					//则 将父亲和叔叔变为黑色，爷爷变成红色，继续向上调整
					if (uncle && uncle->_colour == RED)
					{
						parent->_colour = BLACK;
						uncle->_colour = BLACK;
						grandfat->_colour = RED;
						//令 cur = grandfat, 继续向上处理
						cur = grandfat;
						parent = cur->_parent;
					}
					//叔叔不存在，或者叔叔存在且为黑色
					//则 需要旋转并变色
					else
					{
						if (cur == parent->_right)
						{
							// 3. 右子树的右子树
							//    g
							//  u   p
							//        c
							//爷爷节点左旋，父变黑，祖变红
							RotateL(grandfat);
							grandfat->_colour = RED;
							parent->_colour = BLACK;
						}
						else
						{
							// 2. 右子树的左子树
							//      g
							//  u       p
							//        c
							//父亲节点右旋，爷爷节点左旋，自己变黑，祖变红
							RotateR(parent);
							RotateL(grandfat);
							cur->_colour = BLACK;
							grandfat->_colour = RED;
						}

						break;// 调整后符合红黑树
					}
				}

			}

			_root->_colour = BLACK;//根节点一定为黑色

			return make_pair(iterator(ret), true);

		}
		iterator find(const K& key)
		{
			KeyOfT kot;

			Node* cur = _root;

			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					return (iterator)cur;
				}
				else if (key > kot(cur->_data))
				{
					cur = cur->_right;
				}
				else
				{
					cur = cur->_left;
				}
			}

			return (iterator)nullptr;
		}


		bool IsBalance()
		{
			if (_root == nullptr)
			{
				return true;
			}

			if (_root->_colour == RED)
			{
				cout << "根节点的颜色为红色， 违法规则" << endl;
				return true;
			}

			// 黑色节点数量基准值
			int benchmark = 0;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_colour == BLACK)
					++benchmark;

				cur = cur->_left;
			}

			return PrevCheck(_root, 0, benchmark);
		}

	private:
		Node* _myCopy(Node* root)
		{
			if (root == nullptr)
			{
				return nullptr;
			}

			Node* cur = new Node(root->_data);
			cur->_left = _myCopy(root->_left);
			cur->_right = _myCopy(root->_right);

			return cur;
		}
		void _Destory(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}

			_Destory(root->_left);
			_Destory(root->_right);
			delete(root);
			root = nullptr;

			return;
		}

		void RotateL(Node* parent)
		{
			Node* subR = parent->_right;//待左旋节点的右子树
			Node* subRL = subR->_left;//右子树的左子树

			parent->_right = subRL;//1. 将右左子树变成父节点的右子树
			if (subRL)
			{
				subRL->_parent = parent;//2. 更换右左子树的父节点
			}

			Node* Pparent = parent->_parent;//记录父节点的父节点

			subR->_left = parent;//3. 将父节点变成subR的左子树
			parent->_parent = subR;//4. 更换其父节点

			if (_root == parent)//如果是根节点
			{
				_root = subR;
				subR->_parent = nullptr;
			}
			else
			{
				subR->_parent = Pparent;// 5. 更换父节点
				//父节点是左子树
				if (Pparent->_left == parent)
				{
					Pparent->_left = subR;// 6. 

				}
				else
				{
					Pparent->_right = subR;// 6. 
				}
			}


		}
		void RotateR(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;

			parent->_left = subLR;
			if (subLR)
			{
				subLR->_parent = parent;
			}

			Node* Pparent = parent->_parent;
			subL->_right = parent;
			parent->_parent = subL;

			if (_root == parent)
			{
				_root = subL;
				subL->_parent = nullptr;
			}
			else
			{
				subL->_parent = Pparent;
				if (Pparent->_left == parent)
				{
					Pparent->_left = subL;
				}
				else
				{
					Pparent->_right = subL;
				}
			}

		}
		void RotateLR(Node* parent)
		{
			Node* subL = parent->_left;

			RotateL(subL);
			RotateR(parent);

		}
		void RotateRL(Node* parent)
		{
			Node* subR = parent->_right;

			RotateR(subR);
			RotateL(parent);

		}

		bool PrevCheck(Node* root, int blackNum, int& benchmark)
		{
			if (root == nullptr)
			{

				if (blackNum != benchmark)
				{
					cout << "某条路径的黑色节点的数量不相等" << endl;
					return false;
				}
				else
				{
					return true;
				}
			}

			if (root->_colour == BLACK)
			{
				++blackNum;
			}

			if (root->_colour == RED && root->_parent->_colour == RED)
			{
				cout << "存在连续的红色节点" << endl;
				return false;
			}

			return PrevCheck(root->_left, blackNum, benchmark)
				&& PrevCheck(root->_right, blackNum, benchmark);
		}

	private:
		Node* _root = nullptr;
	};
}



