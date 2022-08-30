#define _CRT_SECURE_NO_WARNINGS 1

#include<bits/stdc++.h>
using namespace std;



/*1359. ��Ч�Ŀ��������Ŀ*/
/* https://leetcode.cn/problems/count-all-valid-pickup-and-delivery-options/ */


/* dp[i][j] Ϊ ����Ϊi, ����Ϊj �ĸ���
* ��dp[i][j] ���Ը��� dp[i-1][j] �� dp[i][j-1];
* ��dp[i][j]�Ż�Ϊ dp[j], jΪ���͵ĸ���, �� forѭ����Աi ������ ���ռ�
* ��dp[j] ���Ը��� dp[j + 1](i - 1) �� dp[j - 1](i);
* ���dp[0]����dp[1] ���Ƿ�����
*/

class Solution {
public:
   int countOrders(int n)
   {
       const int MOD = 1e9 + 7;
       int col = 0, row = n;
       vector<int> dp(n + 1, 0);
       dp[0] = 1;
       for (long long i = row; i > 0; i--)
       {
           vector<int> newdp(n + 1, 0);
           for (long long j = col; j >= 1; j--)
           {
               newdp[j + 1] = dp[j] * i % MOD;
               dp[j - 1] = (dp[j - 1] + dp[j] * j) % MOD;
           }

           newdp[1] = dp[0] * i % MOD;
           col++;
           dp = newdp;
       }
       for (long long j = col; j >= 1; j--)
           dp[j - 1] = (dp[j - 1] + dp[j] * j) % MOD;
       return dp[0];
   }
};
