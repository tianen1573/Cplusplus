#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;

int main()
{
	string s1 = { '1','\0','2','3' };
	string s2(s1);
	string s3; s3 = s1;

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;

	return 0;
}