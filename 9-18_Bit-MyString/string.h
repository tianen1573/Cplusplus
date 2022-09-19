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

#pragma region 其他
		//swap
		void swap(string& str)
		{
			std::swap(_str, str._str);
			std::swap(_size, str._size);
			std::swap(_capacity, str._capacity);
		}

		//c指针
		const char* c_str() const
		{
			return _str;
		}

		//substr
		string substr(size_t pos, size_t len) const
		{
			assert(pos < _size);//合法下标
			size_t realLen = len;
			//len = 1, 对应的是 提取pos位置的元素
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

#pragma region 构造函数
		//无参
// _str(nullptr) 错误: 转换成c指针 用cout输出的结束条件为 *p = '\0', 解引用了空指针
// _str("\0") 错误: 常量字符串默认存在'\0'
		string()
			: _str(new char[1])
			, _size(0)
			, _capacity(0)
		{
			_str[0] = '\0';
		}

		//常量字符串
		string(const char* str)
		{
			size_t len = strlen(str);
			_size = len;
			_capacity = len;
			_str = new char[len + 1];

			strcpy(_str, str);
		}
		////常量字符串全缺省默认构造
		//string(const char* str = "")
		//{
		//	size_t len = strlen(str);
		//	_size = len;
		//	_capacity = len;
		//	_str = new char[len + 1];
		//	
		//	strcpy(_str, str);
		//}

		//常量字符串前n个字符
		string(const char* str, size_t n)
		{
			size_t len = strlen(str);
			len = len > n ? n : len;

			_size = _capacity = len;
			_str = new char[_capacity + 1];

			//strcpy 遇到\0结束, 不支持此前结束
			for (size_t i = 0; i < _size; i++)
			{
				_str[i] = str[i];
			}
			_str[_size] = '\0';

		}

		//n个字符 ch
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

		/*拷贝构造*/
		////传统写法
		//string(const string& str)
		//	:_str(new char[str._capacity + 1])
		//	, _size(str._size)
		//	, _capacity(str._capacity)
		//{
		//	//string对象可包含'\0', 而strcpy无法copy'\0'
		//	memcpy(_str, str._str, _capacity + 1);
		//}
		//
		//现代写法
		string(const string& str)
			: _str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			string tmp(str._str);
			swap(tmp);
		}

		//sting对象 第 pos位置的 后n个字符
		string(const string& str, size_t pos, size_t n = npos)
			
		{
			assert(pos < str._size);//合法下标
			*this = str.substr(pos, n);

			//*this += str.substr(pos, n);
			//错误语句
			//swap(str.substr(pos, n));
		}  

		//析构函数
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
#pragma endregion

#pragma region 空间操作
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

#pragma region 增删改查
		
		//push_back
		void push_back(char ch)
		{
			//是否扩容
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

#pragma region 操作符重载
		
		//逻辑操作符
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

		//运算操作符
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
	
#pragma region 迭代器
		
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
		size_t _capacity;//最大有效存储长度
		size_t _size;//实际长度
		char* _str;//字符串地址
	public:

		//静态成员变量 : 声明定义分离
		static size_t npos;
		//C++11特性 : 加上const可直接在类内定义静态变量
		//const static size_t npos = -1;
	};
	size_t string::npos = -1;

#pragma region 输入输出
	//<<
	ostream& operator<<(std::ostream& out, const string& str)
	{
		for (size_t i = 0; i < str.size(); ++i)
		{
			out << str[i];
		}
		return out;
	}

	////>> -- 基础版本
	//istream& operator>>(istream& in, string& str)
	//{
	//	//清理并设置初始容量
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
	
	//升级版--减少扩容操作
	istream& operator>>(istream& in, string& str)
	{
		//清理并设置初始容量
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





