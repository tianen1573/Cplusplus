

/*1360. 日期之间隔几天*/
/* https://leetcode.cn/problems/number-of-days-between-two-dates/ */


/*
* 日期类重载符号
*/


public class Date
{
public:
    int _y, _m, _d;
    Date& DDate(string& D)//构造
    {
        _y = stoi(D.substr(0, 4));
        _m = stoi(D.substr(5, 2));
        _d = stoi(D.substr(8, 2));
        return *this;
    }
    bool operator>(Date& d)
    {
        if(_y != d._y) return _y > d._y;
        if(_m != d._m) return _m > d._m;
         
        return _d > d._d;
    }
    bool operator==(Date& d)
    {
        return _y == d._y
            && _m == d._m
            && _d == d._d;
    }
};
int GetMonthDays(int year, int month)
{
    static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int day = days[month];
    if ((month == 2)
        && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))//闰年2月
        day++;
 
    return day;
}

class Solution {
public:
    int daysBetweenDates(string D1, string D2) {
        Date Min, Max;
        if(D1 > D2)
        {
            Max.DDate(D1);
            Min.DDate(D2);
        }
        else
        {
            Max.DDate(D2);
            Min.DDate(D1);
        }
        //if(Min == Min) return 0;
        int cnt = 0;
        while(!(Min == Max))
        {
            Min._d++;
            if(Min._d > GetMonthDays(Min._y, Min._m))
            {
                Min._d = 1;
                Min._m++;
            }
            
            if(Min._m > 12)
            {
                Min._y++;
                Min._m = 1;
            }
            cnt++;
        }
        return cnt;

    }
};