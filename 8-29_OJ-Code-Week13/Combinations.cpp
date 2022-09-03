
/*密码锁*/
/* https://www.acwing.com/problem/content/description/1353/ */

/*
* 分别求三位密码每个位置的重复字符的个数, 三者相乘就是重复密码的个数
* 1. hash表, 统计各个位置有多少不重复的, 然后减去得到重复的
* 2. 用圆环上点的距离判断是否重复
*/


#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    int y[3], n[3];
    
    cin >> N;
    cin >> y[0] >> y[1] >> y[2];
    cin >> n[0] >> n[1] >> n[2];
    
    if(N <= 5)
    {
        cout << N*N*N;
        return 0;
    }
    
    int res = 1;
    for(int i = 0; i < 3; i++)
    {
        int dis = abs(y[i] - n[i]);
        res *= (max(0, 5 - dis) + max(0, 5 - (N - dis)));
    }
    
    cout << 250 - res;
    
    return 0;
}