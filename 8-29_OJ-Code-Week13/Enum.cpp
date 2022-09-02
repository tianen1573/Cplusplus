

/*马拉松*/
/* https://www.acwing.com/problem/content/description/1904/ */

/*
* dis为到达N点的距离, dif为 跳过某地能节省的距离 的最大值
*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 11;

int main()
{
    int p[4][2];
    int a, b, c;
    int dif = 0, dis = 0;
    
    
    int n = 0; cin >> n;
    cin >> p[1][0] >> p[1][1];
    cin >> p[2][0] >> p[2][1];
    dis = a = abs(p[2][0] - p[1][0]) + abs(p[2][1] - p[1][1]);
    
    for(int i = 3; i <= n; i++)
    {
        cin >> p[3][0] >> p[3][1];
        dis += b = abs(p[3][0] - p[2][0]) + abs(p[3][1] - p[2][1]);
        c = abs(p[3][0] - p[1][0]) + abs(p[3][1] - p[1][1]);
        
        dif = max(dif, a + b - c);
        
        a = b;
        p[1][0] = p[2][0], p[1][1] = p[2][1];
        p[2][0] = p[3][0], p[2][1] = p[3][1];
    }
    
    cout << dis - dif;
    
    return 0;
}