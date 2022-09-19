#pragma once

#include<iostream>
#include<assert.h>
#include<string>
#include<algorithm>
using namespace std;

namespace Bit
{

	/*using std::cout;
	using std::cin;
	using std::endl;*/

	class string
	{

		typedef char* iterator;
		typedef const char* const_iterator;
	public:

#pragma region ����
		//swap
		void swap(string& str)
		{
			std::swap(_str, str._str);
			std::swap(_size, str._size);
			std::swap(_capacity, str._capacity);
		}

		//cָ��
		const char* c_str() const
		{
			return _str;
		}

		//substr
		string substr(size_t pos, size_t len) const
		{
			assert(pos < _size);//�Ϸ��±�
			size_t realLen = len;
			//len = 1, ��Ӧ���� ��ȡposλ�õ�Ԫ��
			if (len == npos || pos + len > _size)
			{
				realLen = _size - pos;
			}

			string tmp;
			for (size_t i = 0; i < realLen; i++)
			{
				tmp += _str[pos + i];
			}

			return tmp;
		}
		 
#pragma endregion

#pragma region ���캯��
		//�޲�
// _str(nullptr) ����: ת����cָ�� ��cout����Ľ�������Ϊ *p = '\0', �������˿�ָ��
// _str("\0") ����: �����ַ���Ĭ�ϴ���'\0'
		string()
			: _str(new char[1])
			, _size(0)
			, _capacity(0)
		{
			_str[0] = '\0';
		}

		//�����ַ���
		string(const char* str)
		{
			size_t len = strlen(str);
			_size = len;
			_capacity = len;
			_str = new char[len + 1];

			strcpy(_str, str);
		}
		////�����ַ���ȫȱʡĬ�Ϲ���
		//string(const char* str = "")
		//{
		//	size_t len = strlen(str);
		//	_size = len;
		//	_capacity = len;
		//	_str = new char[len + 1];
		//	
		//	strcpy(_str, str);
		//}

		//�����ַ���ǰn���ַ�
		string(const char* str, size_t n)
		{
			size_t len = strlen(str);
			len = len > n ? n : len;

			_size = _capacity = len;
			_str = new char[_capacity + 1];

			//strcpy ����\0����, ��֧�ִ�ǰ����
			for (size_t i = 0; i < _size; i++)
			{
				_str[i] = str[i];
			}
			_str[_size] = '\0';

		}

		//n���ַ� ch
		string(size_t n, char ch)
			:_str(new char[n + 1])
			, _size(n)
			, _capacity(n)
		{
			for (size_t i = 0; i < _size; i++)
			{
				_str[i] = ch;
			}
			_str[_size] = '\0';
		}

		/*��������*/
		////��ͳд��
		//string(const string& str)
		//	:_str(new char[str._capacity + 1])
		//	, _size(str._size)
		//	, _capacity(str._capacity)
		//{
		//	//string����ɰ���'\0', ��strcpy�޷�copy'\0'
		//	memcpy(_str, str._str, _capacity + 1);
		//}
		//
		//�ִ�д��
		string(const string& str)
			: _str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			string tmp(str._str);
			swap(tmp);
		}

		//sting���� �� posλ�õ� ��n���ַ�
		string(const string& str, size_t pos, size_t n = npos)
			
		{
			assert(pos < str._size);//�Ϸ��±�
			*this = str.substr(pos, n);

			//*this += str.substr(pos, n);
			//�������
			//swap(str.substr(pos, n));
		}  

		//��������
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
#pragma endregion

#pragma region �ռ����
		//reserve
		void reserve(size_t n)
		{
			if (n <= _size) return;

			char* tmp = new char[n + 1];

			memcpy(tmp, _str, _capacity + 1);

			delete[] _str;
			_str = tmp;
			tmp = nullptr;
			_capacity = n;
		}

		//size
		size_t size() const
		{
			return _size;
		}
		//capacity
		size_t capacity() const
		{
			return _capacity;
		}

		//clear()
		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}
#pragma endregion

#pragma region ��ɾ�Ĳ�
		
		//push_back
		void push_back(char ch)
		{
			//�Ƿ�����
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}

			_str[_size] = ch;
			_size++;
			_str[_size] = '\0';
		}
		//append
		void append(const char* str)
		{
			size_t len = strlen(str);

			if (len + _size > _capacity)
			{
				reserve(len + _size);
			}

			strcpy(_str + _size, str);
			//strcat(_str + _size, str);

			_size += len;
		}
		void append(const string& str)
		{
			size_t len = str._size;

			if (len + _size > _capacity)
			{
				reserve(len + _size);
			}

			memcpy(_str + _size, str._str, str._size + 1);

			_size += len;
		}

#pragma endregion

#pragma region ����������
		
		//�߼�������
		bool operator>(const string& str) const
		{
			return strcmp(_str, str._str) > 0;
		}
		bool operator==(const string& str) const
		{
			return strcmp(_str, str._str) == 0;
		}
		bool operator>=(const string& str) const
		{
			return *this > str || *this == str;
		}
		bool operator<=(const string& str) const
		{
			return !(*this > str);
		}
		bool operator<(const string& str) const
		{
			return !(*this >= str);
		}
		bool operator!=(const string& str) const
		{
			return !(*this == str);
		}

		//���������
		string& operator=(string str)
		{
			swap(str);
			return *this;
		}
		string& operator+=(const char ch)
		{
			push_back(ch);
			return *this;
		}
		string operator+(const char ch)
		{
			string tmp(*this);
			tmp += ch;
			return tmp;
		}
		string& operator+=(const string& str)
		{
			append(str);
			return *this;
		}
		string operator+(const string& str)
		{
			string tmp(*this);
			tmp.append(str);
			return tmp;
		}
		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}
		string operator+(const char* str)
		{
			string tmp(*this);
			tmp.append(str);
			return tmp;
		}
		
		//[]
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}
		
#pragma endregion
	
#pragma region ������
		
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}


		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}


#pragma endregion


	private:
		size_t _capacity;//�����Ч�洢����
		size_t _size;//ʵ�ʳ���
		char* _str;//�ַ�����ַ
	public:

		//��̬��Ա���� : �����������
		static size_t npos;
		//C++11���� : ����const��ֱ�������ڶ��徲̬����
		//const static size_t npos = -1;
	};
	size_t string::npos = -1;

#pragma region �������
	//<<
	ostream& operator<<(std::ostream& out, const string& str)
	{
		for (size_t i = 0; i < str.size(); ++i)
		{
			out << str[i];
		}
		return out;
	}

	////>> -- �����汾
	//istream& operator>>(istream& in, string& str)
	//{
	//	//�������ó�ʼ����
	//	str.clear();
	//	str.reserve(64);
	//
	//	char ch;
	//
	//	ch = in.get();
	//	while (ch != ' ' && ch != '\n')
	//	{
	//		str += ch;
	//		ch = in.get();
	//	}
	//
	//	return in;
	//}
	
	//������--�������ݲ���
	istream& operator>>(istream& in, string& str)
	{
		//�������ó�ʼ����
		str.clear();
		str.reserve(64);

		const int N = 32;
		char buff[N];
		size_t i = 0;
	
		char ch;
	
		ch = in.get();
		while (ch != ' ' && ch != '\n')
		{
			buff[i++] = ch;

			if (i == N - 1)
			{
				buff[i] = '\0';
				str += buff;
				i = 0;
			}

			ch = in.get();
		}

		buff[i] = '\0';
		str += buff;
	
		return in;
	}

#pragma endregion

	void test1()
	{
		string s1("hello");
		//string s2(s1); s2 += 'c';
		string s3(s1); s3 += "world";
		// s4(s1); s4 += s1;
		string s5(s3, 4, 19);

		//cout << s1.c_str() << endl;
		//cout << s2.c_str() << endl;
		//cout << s3.substr(4, 5) << endl;
		//cout << s3.substr(4, 19) << endl;

		cout << s5.c_str() << endl;


	}
}





