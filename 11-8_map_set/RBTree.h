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

	//�ڵ�
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

	//������
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
			//�����ң� ��������� 
			
			//�������ýڵ�ʱ�� �ýڵ�Ϊ �����ڵ㡯������������
			//����ǰ�ڵ����Һ��ӣ���++Ϊ��������������ڵ�
			if (_node->_right)
			{
				Node* left = _node->_right;

				while (left->_left)
				{
					left = left->_left;
				}

				_node = left;
			}
			//��û��������������������Ѿ��������ˣ�����������Ϊ���ڵ����
			//��ԭ��Ϊ�������� �򸸽ڵ㻹δ���ʣ� ��Ϊ���������򸸽ڵ�������ڵ���Ҳ�������
			//�������ϣ� ֱ�� �� ��Ϊ�������Ľڵ���� ���� ȫ��������
			else
			{
				Node* parent = _node->_parent;
				Node* cur = _node;

				//���ڵ㲻������Ϊ���ڵ�
				//Ϊ�������������ϱ���
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
			//�����ң� ��������� 

			//�������ýڵ�ʱ�� �ýڵ�Ϊ �����ڵ㡯��������һ���ڵ�Ϊ�����������ҽڵ�
			//����ǰ�ڵ������ӣ���--Ϊ�������������ҽڵ�
			if (_node->_left)
			{
				Node* right = _node->_left;

				while (right->_right)
				{
					right = right->_right;
				}

				_node = right;
			}
			//��û�������������丸�ڵ����֮�� ֱ�ӷ����˸ýڵ�
			//��ԭ��Ϊ�������� �򸸽ڵ㻹δ���ʣ� ��Ϊ���������򸸽ڵ��ѱ����ʣ��Ҿ���--
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
		RBT<K, T, KeyOfT>& operator= (RBT<K, T, KeyOfT> rbt)//�β�����������ģ� �ں�������ʱ������
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

			//��ʼ���½ڵ�
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

			//����ƽ��
			//���״��ڣ� ����Ϊ��ɫ,���Ϻ����; ����Ϊ��ɫ�����е���
			//���ײ����ڣ���Ϊ���ڵ㣬ֻ��������ڵ����ɫ
			while (parent && parent->_colour == RED)
			{
				Node* grandfat = parent->_parent;
				assert(grandfat);//��Ϊ���ڵ�Ϊ��ɫ�� ����һ����һ����ɫ���ڵ�
				assert(grandfat->_colour == BLACK);

				//�������ұ�
				if (parent == grandfat->_left)
				{
					Node* uncle = grandfat->_right;
					//1. ������ڣ� ������Ϊ��ɫ
					//�� �����׺������Ϊ��ɫ��үү��ɺ�ɫ���������ϵ���
					if (uncle && uncle->_colour == RED)
					{
						parent->_colour = BLACK;
						uncle->_colour = BLACK;
						grandfat->_colour = RED;
						//�� cur = grandfat, �������ϴ���
						cur = grandfat;
						parent = cur->_parent;
					}
					//���岻���ڣ��������������Ϊ��ɫ
					//�� ��Ҫ��ת����ɫ
					else
					{
						if (cur == parent->_left)
						{
							// 2. ��������������
							//    g
							//  p   u
							//c
							//үү�ڵ�����������ڣ�����
							RotateR(grandfat);
							grandfat->_colour = RED;
							parent->_colour = BLACK;
						}
						else
						{
							// 2. ��������������
							//      g
							//  p       u
							//    c
							//���׽ڵ�������үү�ڵ��������Լ���ڣ�����
							RotateL(parent);
							RotateR(grandfat);
							cur->_colour = BLACK;
							grandfat->_colour = RED;
						}

						break;// ��������Ϻ����
					}
				}
				else//���������
				{
					Node* uncle = grandfat->_left;
					//1. ������ڣ� ������Ϊ��ɫ
					//�� �����׺������Ϊ��ɫ��үү��ɺ�ɫ���������ϵ���
					if (uncle && uncle->_colour == RED)
					{
						parent->_colour = BLACK;
						uncle->_colour = BLACK;
						grandfat->_colour = RED;
						//�� cur = grandfat, �������ϴ���
						cur = grandfat;
						parent = cur->_parent;
					}
					//���岻���ڣ��������������Ϊ��ɫ
					//�� ��Ҫ��ת����ɫ
					else
					{
						if (cur == parent->_right)
						{
							// 3. ��������������
							//    g
							//  u   p
							//        c
							//үү�ڵ�����������ڣ�����
							RotateL(grandfat);
							grandfat->_colour = RED;
							parent->_colour = BLACK;
						}
						else
						{
							// 2. ��������������
							//      g
							//  u       p
							//        c
							//���׽ڵ�������үү�ڵ��������Լ���ڣ�����
							RotateR(parent);
							RotateL(grandfat);
							cur->_colour = BLACK;
							grandfat->_colour = RED;
						}

						break;// ��������Ϻ����
					}
				}

			}

			_root->_colour = BLACK;//���ڵ�һ��Ϊ��ɫ

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
				cout << "���ڵ����ɫΪ��ɫ�� Υ������" << endl;
				return true;
			}

			// ��ɫ�ڵ�������׼ֵ
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
			Node* subR = parent->_right;//�������ڵ��������
			Node* subRL = subR->_left;//��������������

			parent->_right = subRL;//1. ������������ɸ��ڵ��������
			if (subRL)
			{
				subRL->_parent = parent;//2. �������������ĸ��ڵ�
			}

			Node* Pparent = parent->_parent;//��¼���ڵ�ĸ��ڵ�

			subR->_left = parent;//3. �����ڵ���subR��������
			parent->_parent = subR;//4. �����丸�ڵ�

			if (_root == parent)//����Ǹ��ڵ�
			{
				_root = subR;
				subR->_parent = nullptr;
			}
			else
			{
				subR->_parent = Pparent;// 5. �������ڵ�
				//���ڵ���������
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
					cout << "ĳ��·���ĺ�ɫ�ڵ�����������" << endl;
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
				cout << "���������ĺ�ɫ�ڵ�" << endl;
				return false;
			}

			return PrevCheck(root->_left, blackNum, benchmark)
				&& PrevCheck(root->_right, blackNum, benchmark);
		}

	private:
		Node* _root = nullptr;
	};
}



