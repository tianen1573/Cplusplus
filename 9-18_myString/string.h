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
			string tmp(str._str);//C指针构造，不是拷贝构造
			swap(tmp);
		}

		//sting对象 第 pos位置的 后n个字符
		string(const string& str, size_t pos, size_t n = npos)
			
		{
			assert(pos < str._size);//合法下标
			*this = str.substr(pos, n);

			//*this += str.substr(pos, n);
			
			//错误语句
			// substr的返回值具有const属性, 无法修改, 不能作为swap的实参传递
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

		//substr
		string substr(size_t pos, size_t len = npos) const
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

		//instert -- 引用返回值 可作为 右值或参数
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

			strncpy(_str + pos, str, len);//不拷贝'\0', 只拷贝有效字符
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

			//strncpy(_str + pos, str._str, len);//不拷贝'\0', 只拷贝有效字符
			memcpy(_str + pos, str._str, len);
			_size += len;

			return *this;
		}
		/*
		* 复用
		* 对于substring 和 buffer 可以通过 (转换成string)截断 + substr 实现
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

			const char* ptr = strstr(_str + pos, sub);//cstrig库函数, 返回匹配的第一个字符的地址
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

#pragma region 成员变量
	private:
		size_t _capacity;//最大有效存储长度
		size_t _size;//实际长度
		char* _str;//字符串地址
	public:

		//静态成员变量 : 声明定义分离
		static size_t npos;
		//C++11特性 : 加上const可直接在类内定义静态变量
		//const static size_t npos = -1;  
#pragma endregion

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

	//构造
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
	//操作符
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
	//增删改查
	void DealUrl(const string& url)
	{
		size_t pos1 = url.find("://");
		if (pos1 == string::npos)
		{
			cout << "非法url" << endl;
			return;
		}
		// 休息到16:08继续
		string protocol = url.substr(0, pos1);
		cout << protocol << endl;

		size_t pos2 = url.find('/', pos1 + 3);
		if (pos2 == string::npos)
		{
			cout << "非法url" << endl;
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




