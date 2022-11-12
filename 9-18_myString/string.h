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
			string tmp(str._str);//Cָ�빹�죬���ǿ�������
			swap(tmp);
		}

		//sting���� �� posλ�õ� ��n���ַ�
		string(const string& str, size_t pos, size_t n = npos)
			
		{
			assert(pos < str._size);//�Ϸ��±�
			*this = str.substr(pos, n);

			//*this += str.substr(pos, n);
			
			//�������
			// substr�ķ���ֵ����const����, �޷��޸�, ������Ϊswap��ʵ�δ���
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
		//resize
		void resize(size_t n, char ch = '\0')
		{
			if (n > _size)
			{
				reserve(n);
				for (_size; _size < n; _size++)
				{
					_str[_size] = ch;
				}
				_str[_size] = '\0';
			}
			else
			{
				_str[n] = '\0';
				_size = n;
			}
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

		//substr
		string substr(size_t pos, size_t len = npos) const
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

		//instert -- ���÷���ֵ ����Ϊ ��ֵ�����
		string& insert(size_t pos, char ch)
		{
			assert(pos < _size);

			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}

			size_t end = ++_size;

			while (end > pos)
			{
				_str[end] = _str[end - 1];
				end--;
			}

			_str[pos] = ch;

			return *this;
		}
		string& insert(size_t pos, const char* str)
		{
			assert(pos < _size);

			size_t len = strlen(str);

			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			size_t end = _size + len;

			while (end >= pos + len)
			{
				_str[end] = _str[end - len];
				end--;
			}

			strncpy(_str + pos, str, len);//������'\0', ֻ������Ч�ַ�
			//memcpy(_str + pos, str, len);
			_size += len;

			return *this;
		}
		string& insert(size_t pos, const string& str)
		{
			assert(pos < _size);

			size_t len = str._size;

			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			size_t end = _size + len;

			while (end >= pos + len)
			{
				_str[end] = _str[end - len];
				end--;
			}

			//strncpy(_str + pos, str._str, len);//������'\0', ֻ������Ч�ַ�
			memcpy(_str + pos, str._str, len);
			_size += len;

			return *this;
		}
		/*
		* ����
		* ����substring �� buffer ����ͨ�� (ת����string)�ض� + substr ʵ��
		*/

		//find
		size_t find(char ch, size_t pos = 0) const
		{
			assert(pos < _size);

			for (size_t i = pos; i < _size; ++i)
			{
				if (ch == _str[i])
				{
					return i;
				}
			}

			return npos;
		}
		size_t find(const char* sub, size_t pos = 0) const
		{
			assert(sub);
			assert(pos < _size);

			const char* ptr = strstr(_str + pos, sub);//cstrig�⺯��, ����ƥ��ĵ�һ���ַ��ĵ�ַ
			if (ptr == nullptr)
			{
				return npos;
			}
			else
			{
				return ptr - _str;
			}
		}

		//erase
		string& erase(size_t pos = 0, size_t len = npos)
		{
			assert(pos < _size);

			if (len == npos || pos + len >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				memcpy(_str + pos, _str + pos + len, _size - pos - len + 1);
				_size -= len;
			}

			return *this;
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

#pragma region ��Ա����
	private:
		size_t _capacity;//�����Ч�洢����
		size_t _size;//ʵ�ʳ���
		char* _str;//�ַ�����ַ
	public:

		//��̬��Ա���� : �����������
		static size_t npos;
		//C++11���� : ����const��ֱ�������ڶ��徲̬����
		//const static size_t npos = -1;  
#pragma endregion

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

	//����
	void test1()
	{
		cout << "MyString" << endl;
		string s1;
		string s2("String");
		string s3("HelloSTL", 5);
		string s4(20, 'o');
		string s5(s2);
		string s6(s4, 10);

		cout << s1 << endl;
		cout << s2 << endl;
		cout << s3 << endl;
		cout << s4 << endl;
		cout << s5 << endl;
		cout << s6 << endl;

	}
	//������
	void test2()
	{
		string s1("helloSTl");
		string s2;

		cin >> s1 >> s2;
		cout << s1 << endl << s2 << endl;
		s2 = s1;
		cout << s1 << endl << s2 << endl;
	}
	void test3()
	{
		string s1("Hello");
		string s2("Mystring");

		cout << s1 + '!' << endl;
		cout << s1 + " Bit" << endl;
		cout << s1 + s2 << endl;


		cout << (s1 += '!') << endl;
		cout << (s1 += " Bit") << endl;
		cout << (s1 += s2) << endl;
	}
	//��ɾ�Ĳ�
	void DealUrl(const string& url)
	{
		size_t pos1 = url.find("://");
		if (pos1 == string::npos)
		{
			cout << "�Ƿ�url" << endl;
			return;
		}
		// ��Ϣ��16:08����
		string protocol = url.substr(0, pos1);
		cout << protocol << endl;

		size_t pos2 = url.find('/', pos1 + 3);
		if (pos2 == string::npos)
		{
			cout << "�Ƿ�url" << endl;
			return;
		}
		string domain = url.substr(pos1 + 3, pos2 - pos1 - 3);
		cout << domain << endl;

		string uri = url.substr(pos2 + 1);
		cout << uri << endl << endl;
	}
	void test4()
	{
		string url1 = "https://cplusplus.com/reference/string/string/";
		string url2 = "https://image.baidu.com/search/detail?ct=503316480&z=0&ipn=d&word=ascall&step_word=&hs=0&pn=0&spn=0&di=7108135681917976577&pi=0&rn=1&tn=baiduimagedetail&is=0%2C0&istype=0&ie=utf-8&oe=utf-8&in=&cl=2&lm=-1&st=undefined&cs=2613959014%2C543572025&os=2740573600%2C1059518451&simid=2613959014%2C543572025&adpicid=0&lpn=0&ln=179&fr=&fmq=1660115697093_R&fm=&ic=undefined&s=undefined&hd=undefined&latest=undefined&copyright=undefined&se=&sme=&tab=0&width=undefined&height=undefined&face=undefined&ist=&jit=&cg=&bdtype=0&oriquery=&objurl=https%3A%2F%2Fgimg2.baidu.com%2Fimage_search%2Fsrc%3Dhttp%3A%2F%2Fimg.php.cn%2Fupload%2Fimage%2F147%2F157%2F796%2F1593765739620093.png%26refer%3Dhttp%3A%2F%2Fimg.php.cn%26app%3D2002%26size%3Df9999%2C10000%26q%3Da80%26n%3D0%26g%3D0n%26fmt%3Dauto%3Fsec%3D1662707704%26t%3Da68cb238bbb3f99d0554098c785d526e&fromurl=ippr_z2C%24qAzdH3FAzdH3Fooo_z%26e3Brir_z%26e3BvgAzdH3FuwqAzdH3F9c9amd_z%26e3Bip4s&gsm=1&rpstart=0&rpnum=0&islist=&querylist=&nojc=undefined&dyTabStr=MCwzLDIsNCw2LDEsNSw3LDgsOQ%3D%3D";
		string url3 = "ftp://ftp.cs.umd.edu/pub/skipLists/skiplists.pdf";

		DealUrl(url1);
		DealUrl(url2);
		DealUrl(url3);
	}
	void test5()
	{
		string s1;
		s1.resize(20);
		cout << s1 << endl;

		string s2("hello");
		s2.resize(20, 'x');
		cout << s2 << endl;
		s2.resize(10);
		cout << s2 << endl;

	}
	void test6()
	{
		string s("12345678");
		string s1("12345678");

		cout << s.erase(0, 5) << endl;
		cout << s1.erase(6, 9) << endl;
		cout << string("123456").erase();

	}

}




