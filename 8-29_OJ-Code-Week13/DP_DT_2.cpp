

/*ţ��Ͱ*/
/* https://www.acwing.com/problem/content/description/1844/ */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <stdio.h>

using namespace std;


// /*
// * ״̬ת��, ��dp[i] ->> dp[i + x], dp[i + y]
// */
//
// int x, y, m;
// int maxV;
// bool dp[2000] = {false};

// int main()
// {
//     cin >> x >> y >> m;
    
//     dp[x] = dp[y] = true;
    
//     for(int i = x; i <= m; i++)
//         if(dp[i])
//             dp[i + x] = dp[i + y] = dp[i];
//     int i = 0;
//     for(i = m; i >= 0; i--)
//         if(dp[i]) break;
        
//     cout << i;
    
//     return 0;
    
// }

int main()
{
    int x = 1, y = 2, m = 3;
    scanf("%d %d %d", &x, &y, &m);
    
    int res = 0;
    
    /*
    * ÿ�� �ȵ��� iͰy������ ţ��, ������ �������Ͱ x������ ţ��
    */
    for(int i = 0; i <= m / y; i++)
        res = max(res, ((m - i * y) / x) * x + i * y);
        
    cout << res;
    
    return 0;
}
