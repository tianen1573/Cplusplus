
/*里程表*/
/* https://www.acwing.com/problem/content/description/1914/ */

/*
* 数据为10^16, 直接遍历模拟会超时
* 根据哞数字的规律, 逆思维模拟哞数字, 判断是否在答案区间
* by yxc
*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;


int main()
{
    int res = 0;
    LL x, y;
    cin >> x >> y;
    
    //位数
    for(int i = 3; i <= 17; i++)
        for(int k = 0; k < 10; k++)//相同的数字为k
            for(int j = 0; j < 10; j++)//不同的那个为j
                if(k != j)//两种数字
                {
                    //找一个位置放置不同的数字
                    for(int u = 0; u < i; u++)
                    {
                        string str(i, '0' + k);
                        str[u] = '0' + j;
                        //去掉前导0
                        if(str[0] != '0')
                        {
                            LL val = stoll(str);
                            if(val >= x && val <= y) res++;
                        }
                    }
                    
                }
    cout << res;
    return 0;
}