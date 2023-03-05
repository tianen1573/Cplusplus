#pragma once

#include<iostream>
#include<vector>
#include<assert.h>

using namespace std;

namespace qlz
{
	template<class T>//ģ������

	class vector
	{
	public:

		//vector��������ԭ��ָ��, ������������������, ����Ϊģ������ָ��;
		typedef T* iterator;
		typedef const T* const_iterator;

		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		//const_iterator begin() const, ���ɺ�������
		//��Ϊ��һ���β�, �������ָ���ǲ�ͬ����, һ���Ƿ�constָ��, һ����constָ��
		const_iterator cbegin() const
		{
			return _start;
		}
		const_iterator cend() const
		{
			return _finish;
		}


		//�޲�Ĭ�Ϲ���
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{}

		//��������
		vector(const vector<T>& vec)
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			reverse(vec.capacity());

			/*for (size_t i = 0; i < vec.size(); i++)
			{
				_start[i] = vec._start[i];
			}

			_finish = _start + vec.size();
			_endOfStorage = _start + vec.capacity();*/

			//������ʵ��
			iterator it = begin();
			const_iterator vit = vec.cbegin();
			while (vit != vec.cend())
			{
				//����������
				*it++ = *vit++;
			}
			_finish = it;

		}

		//n��Ԫ��
		vector(size_t n, const T& val = T())
			//ע���Ա��������˳��
			:_start(new T[n])
			, _finish(_start + n)
			, _endOfStorage(_start + n)
		{
			for (size_t i = 0; i < n; i++)
			{
				//����������
				_start[i] = val;
			}
		}
		/*
		* �����Ͻ����ṩ��vector(size_t n, const T& value = T())֮��
		* vector(int n, const T& value = T())�Ͳ���Ҫ�ṩ�ˣ����Ƕ��ڣ�
		* vector<int> v(10, 10);
		* �������ڱ���ʱ����ΪT�Ѿ���ʵ����Ϊint����10��10��������Ĭ����Ϊint����,������������ͬ
		* �����ǹ���10��10������size_t �� int ������ͬ���ͣ�ǡ�õ��������������ģ�������ͬһ����
		* ���ԣ��Ͳ�����vector(size_t n, const T& value = T())������췽�������ǵ���������
		* ��Ϊ vector(InputIterator first, InputIterator last) ģ��Inpuʵ����Ϊintʱ, �β��б������
		* ����10 �� 10��������һ�����䣬����ʱ�ͱ�����
		* ����Ҫ�ù��췽��, ��ֹ�ܵ����������캯��
		*/
		vector(int n, const T& val = T())
			//ע���Ա��������˳��
			:_start(new T[n])
			, _finish(_start + n)
			, _endOfStorage(_start + n)
		{
			for (int i = 0; i < n; i++)
			{
				//����������
				_start[i] = val;
			}
		}

		//����������
		template<class InputIterator>//������ģ��
		vector(InputIterator first, InputIterator last)
		{
			//����push_back
			while (first != last)
			{
				//δȷ������, ����push_back, ÿ��ѯ���Ƿ���Ҫ����
				push_back(*first);
				++first;
			}
		}

		~vector()
		{
			delete[] _start;
			_start = _finish = _endOfStorage = nullptr;
		}


	private:
		bool Full()
		{
			if (_finish == _endOfStorage)
			{
				return true;
			}

			return false;
		}
	public:
		size_t capacity() const
		{
			return _endOfStorage - _start;
		}

		size_t size() const
		{
			return _finish - _start;
		}

		bool empty() const
		{
			if (_finish == _start)
			{
				return true;
			}

			return false;
		}

		void reverse(size_t n)
		{
			if (n <= capacity())
			{
				return;
			}

			size_t oldSize = size();

			T* tmp = new T[n];

			for (size_t i = 0; i < oldSize; i++)
			{
				tmp[i] = _start[i];//ģ������T�ĸ�ֵ����
			}
			delete[] _start;

			_start = tmp;
			tmp = nullptr;
			_finish = _start + oldSize;
			_endOfStorage = _start + n;

		}

		void resize(size_t n, const T& val = T())
		{
			if (n <= _finish - _start)
			{
				_finish = _start + n;
			}
			else
			{
				reverse(n);

				iterator cur = _finish;
				_finish = _start + n;
				while (cur != _finish)
				{
					//�Ѿ�ȷ��������λ, ֱ��ʹ�ø�ֵ, ���ٵ���
					*cur = val;
					cur++;
				}
			}
		}


		//�����βε�����, ���β��滻Ϊ�ն���
		void swap(vector<T>& vec)
		{
			::swap(_start, vec._start);//std
			::swap(_finish, vec._finish);
			::swap(_endOfStorage, vec._endOfStorage);
		}



		//��Ԫ������, ��ֹ����������
		iterator insert(iterator it, const T& val)
		{
			assert(it <= _finish);//�Ϸ�����

			if (Full())
			{
				size_t pos = it - _start;

				reverse(capacity() == 0 ? 2 : capacity() * 2);

				it = _start + pos;//���ò���λ�õ�����, ��ֹ������ʧЧ
			}

			iterator end = _finish - 1;//_finish���ڵ�ַ, Ϊ�µ�vector���һ��Ԫ�ص�λ��

			while (end >= it)
			{
				*(end + 1) = *end;
				end--;
			}

			*it = val;
			_finish++;
			return it;//���ز���λ�õĵ�����
		}

		//����insert
		void push_back(const T& val)
		{
			insert(_finish, val);
		}

		//���ر�ɾ����λ�õĵ�����
		iterator erase(iterator it)
		{
			assert(!empty());//�ǿ�

			// Ų�����ݽ���ɾ��
			iterator begin = it;
			while (begin != _finish - 1) {
				*begin = *(begin + 1);
				++begin;
			}

			--_finish;
			return it;
		}

		//����erase
		void pop_back()
		{
			erase(_finish - 1);
		}

		vector<T>& operator= (vector<T> vec)
		{
			swap(vec);
			return *this;
		}

		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}

		const T& operator[](size_t pos)const
		{
			assert(pos < size());
			return _start[pos];
		}

		T& front()
		{
			return *_start;
		}

		const T& front()const
		{
			return *_start;
		}

		T& back()
		{
			return *(_finish - 1);
		}

		const T& back()const
		{
			return *(_finish - 1);
		}



	private:

		//����ҿ�
		//û��Ҫ���ó�ʼֵ, ��Ϊ��Ƶ��ʹ�ó�ʼ���б�
		iterator _start;//ͷ
		iterator _finish;//β == ͷָ�� + ʵ�ʴ�С
		iterator _endOfStorage;// == ͷָ�� + �������
	};

	void Test1()
	{
		qlz::vector<int> v1;
		qlz::vector<int> v2(10, 5);

		int array[] = { 1,2,3,4,5 };
		qlz::vector<int> v3(array, array + sizeof(array) / sizeof(array[0]));

		qlz::vector<int> v4(v3);

		for (size_t i = 0; i < v2.size(); ++i)
		{
			cout << v2[i] << " ";
		}
		cout << endl;

		auto it = v3.begin();
		while (it != v3.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : v4)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void Test2()
	{
		qlz::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		cout << v.size() << endl;
		cout << v.capacity() << endl;
		cout << v.front() << endl;
		cout << v.back() << endl;
		cout << v[0] << endl;
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		v.pop_back();
		v.pop_back();
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		v.insert(v.begin(), 0);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		v.erase(v.begin() + 1);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		/*qlz::vector<int> vvv;
		vvv.push_back(1);
		vvv.push_back(2);
		vvv.push_back(3);
		vvv.push_back(4);
		vvv.push_back(5);

		qlz::vector<char> vv;
		vv.push_back('a');
		vv.push_back('b');
		vv.push_back('c');
		vv.push_back('d');*/

	}

	void Test3()
	{
		vector<int*> vec;
		int a = 1, b = 2, c = 3;
		vec.push_back(&a);
		vec.push_back(&c);
		vec.push_back(&b);

		for (auto& ptr : vec)
		{
			cout << *ptr << ' ';
		}


	}
}