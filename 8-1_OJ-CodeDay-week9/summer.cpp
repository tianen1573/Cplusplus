#define _CRT_SECURE_NO_WARNINGS 1

/*�����ǵڼ���*/
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

/*ͳ�Ƶ���*/
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
//        while (i < str.size() && str[i] == ' ') i++;//�ҵ��ʿ�ͷ
//        j = i + 1;
//        while (j < str.size() && str[j] != ' ' && str[j] != '.') j++;//�ҵ��ʽ�β��һ��
//
//        if (str[i] == '.') cout << endl;
//        else cout << j - i << ' ';
//
//        i = j;
//    }
//    return 0;
//}