#define _CRT_SECURE_NO_WARNINGS 1

#include<bits/stdc++.h>
using namespace std;

/*1346. ������������������Ƿ����*/
/* https://leetcode.cn/problems/check-if-n-and-its-double-exist/submissions/ */
//class Solution {
//public:
//    bool checkIfExist(vector<int>& arr) {
//        bool hash[4011] = { 0 };
//        int _0cnt = 0;
//        for (auto x : arr)
//        {
//            if (x == 0) _0cnt++;
//            hash[x + 2000] = true;
//        }
//        for (auto x : arr)
//        {
//            if (x && x * 2 + 2000 < 4011 && hash[x * 2 + 2000]) return true;
//            if (x == 0)
//                if (_0cnt > 1) return true;
//        }
//        return false;
//    }
//};

/*1359. ��Ч�Ŀ��������Ŀ*/
/* https://leetcode.cn/problems/count-all-valid-pickup-and-delivery-options/ */
//class Solution {
//public:
//    int countOrders(int n)
//    {
//        const int MOD = 1e9 + 7;
//        int col = 0, row = n;
//        vector<int> dp(n + 1, 0);
//        dp[0] = 1;
//        for (long long i = row; i > 0; i--)
//        {
//            vector<int> newdp(n + 1, 0);
//            for (long long j = col; j >= 1; j--)
//            {
//                newdp[j + 1] = dp[j] * i % MOD;
//                dp[j - 1] = (dp[j - 1] + dp[j] * j) % MOD;
//            }
//
//            newdp[1] = dp[0] * i % MOD;
//            col++;
//            dp = newdp;
//        }
//        for (long long j = col; j >= 1; j--)
//            dp[j - 1] = (dp[j - 1] + dp[j] * j) % MOD;
//        return dp[0];
//    }
//};
//    /* dp[i][j] Ϊ ����Ϊi, ����Ϊj �ĸ���
//    * ��dp[i][j] ���Ը��� dp[i-1][j] �� dp[i][j-1];
//    * ��dp[i][j]�Ż�Ϊ dp[j], jΪ���͵ĸ���, �� forѭ����Աi ������ ���ռ�
//    * ��dp[j] ���Ը��� dp[j + 1](i - 1) �� dp[j - 1](i);
//    * ���dp[0]����dp[1] ���Ƿ�����
//    */