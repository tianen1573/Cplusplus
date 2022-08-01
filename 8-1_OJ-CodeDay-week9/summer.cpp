#define _CRT_SECURE_NO_WARNINGS 1

/*今天是第几天*/
/* https://www.acwing.com/problem/content/description/3394/ */
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int year = 0;
    int month = 0;
    int day = 0;
    int sum_day = 0;
    int days[] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
    while (~scanf("%d%d%d", &year, &month, &day))
    {
        sum_day = month == 1 ? day : days[month - 2] + day;
        if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && month > 2)
        {
            sum_day += 1;
        }
        printf("%d\n", sum_day);
    }
    return 0;
}