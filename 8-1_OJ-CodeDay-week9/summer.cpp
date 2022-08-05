#define _CRT_SECURE_NO_WARNINGS 1

/*今天是第几天*/
/* https://www.acwing.com/problem/content/description/3394/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//    int year = 0;
//    int month = 0;
//    int day = 0;
//    int sum_day = 0;
//    int days[] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
//    while (~scanf("%d%d%d", &year, &month, &day))
//    {
//        sum_day = month == 1 ? day : days[month - 2] + day;
//        if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && month > 2)
//        {
//            sum_day += 1;
//        }
//        printf("%d\n", sum_day);
//    }
//    return 0;
//}

/*统计单词*/
/* https://www.acwing.com/activity/content/problem/content/7324/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//int cnt, i = 0, j = 0;
//
//int main()
//{
//    string str;
//    getline(cin, str);
//    while (i < str.size())
//    {
//        while (i < str.size() && str[i] == ' ') i++;//找单词开头
//        j = i + 1;
//        while (j < str.size() && str[j] != ' ' && str[j] != '.') j++;//找单词结尾后一个
//
//        if (str[i] == '.') cout << endl;
//        else cout << j - i << ' ';
//
//        i = j;
//    }
//    return 0;
//}

/*进制转换*/
/* https://www.acwing.com/problem/content/description/3455/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//int sum = 0;
//string num;
//
//int main()
//{
//    while (cin >> num)
//    {
//
//        int pos = 2, val = 0, flag = 1;
//        if (num[0] == '-')
//        {
//            flag = -1;
//            pos = 3;
//        }
//        sum = 0;
//        for (; pos < num.size(); pos++)
//        {
//            if (num[pos] >= 'a') val = num[pos] - 'a' + 10;
//            else val = num[pos] - '0';
//            sum = sum * 16 + val;
//        }
//        cout << sum * flag << endl;
//    }
//    return 0;
//}

/*a+b*/
/* https://www.acwing.com/problem/content/3599/ */
//#include<string>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//string strA, strB;
//
//void sum()
//{
//    int carry = 0;
//    int i = 0;
//
//    for (; i < strA.size() && i < strB.size(); i++)
//    {
//        int a = strA[i] - '0', b = strB[i] - '0';
//        strA[i] = (a + b + carry) % 10 + '0';
//        carry = (a + b + carry) / 10;
//    }
//
//    while (i < strA.size())
//    {
//        int a = strA[i] - '0';
//        strA[i] = (a + carry) % 10 + '0';
//        carry = (a + carry) / 10;
//        i++;
//    }
//    while (i < strB.size())
//    {
//        int b = strB[i] - '0';
//        strA.push_back('0' + (b + carry) % 10);
//        carry = (b + carry) / 10;
//        i++;
//    }
//    if (carry == 1) strA.push_back('1');
//
//    return;
//}
//
//int main()
//{
//    while (cin >> strA >> strB)
//    {
//        reverse(strA.begin(), strA.end());
//        reverse(strB.begin(), strB.end());
//        sum();
//        reverse(strA.begin(), strA.end());
//        cout << strA << endl;
//    }
//
//    return 0;
//}

/*切木棍*/
/* https://www.acwing.com/problem/content/description/3670/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//int n, cnt;
//
//int main()
//{
//    while (~scanf("%d", &n))
//    {
//        if (n % 2 == 1)
//            cnt = 0;
//        else
//        {
//            cnt = n / 2 - 1;
//            if (n % 4 == 0)
//                cnt--;
//            cnt /= 2;
//        }
//
//        printf("%d\n", cnt);
//    }
//
//
//    return 0;
//}
////1. n必须为偶数
////2. 其中一对直角边长度和为 n / 2, 则分配给两个边有[1, n/2), 即 n / 2 - 1 中分法
////3. 不能为正方形, 一个数对为一种, 和顺序无关.