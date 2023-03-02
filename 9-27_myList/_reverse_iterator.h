#define _CRT_SECURE_NO_WARNINGS 1

//��.hΪ�������������������

namespace qlz
{
	//_iterator<class T>::iterator, T&, T*
	//_iterator<class T>::iterator, const T&, const T*
	template<class iterator>
	struct _reverse_iterator
	{
	public:
		// ע�⣺�˴�typename����������ȷ���߱�������Ref��Iterator���е�һ�����ͣ������Ǿ�̬��Ա����
		// �������������ʱ�Ͳ�֪��Ref��Iterator�е����ͻ��Ǿ�̬��Ա����
		// ��Ϊ��̬��Ա����Ҳ�ǰ��� ����::��̬��Ա������ �ķ�ʽ���ʵ�
		typedef typename iterator::Ref Ref;
		typedef typename iterator::Ptr Ptr;
		typedef _reverse_iterator<iterator> reverse_iterator;
	public:
		// ����
		_reverse_iterator(iterator it)
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
			return _rit == l._rit;
		}

		iterator _rit;
	};
}