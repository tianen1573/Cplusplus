#define _CRT_SECURE_NO_WARNINGS 1

#include"string.h"


//Test
void test1()
{
	cout << "STL" << endl;
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
void test2()
{
	string s1("helloSTl");
	string s2;

	cin >> s1 >> s2;
	cout << s1 << endl << s2;
	s2 = s1;
	cout << s1 << endl << s2;
}
void test3()
{
	string s1("Hello");
	string s2("Mystring");

	cout << s1 + '!' << endl;
	cout << s1 + " Bit" << endl;
	cout << s1 + s2 << endl;


	cout << (s1 += '!') <<endl;
	cout << (s1 += " Bit") << endl;
	cout << (s1 += s2) << endl;
}
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

int main()
{


	/*Bit::test1();
	cout << endl;
	test1();*/

	/*Bit::test2();
	cout << endl;
	test2();*/

	/*Bit::test3();
	cout << endl;
	test3();*/

	/*Bit::test4();
	cout << endl;
	test4();*/

	/*Bit::test5();
	cout << endl;
	test5();*/

	Bit::test6();
	cout << endl;
	test6();

	return 0;
}