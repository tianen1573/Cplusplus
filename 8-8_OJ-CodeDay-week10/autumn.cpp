#define _CRT_SECURE_NO_WARNINGS 1

/*用户分组*/
/* https://leetcode.cn/problems/group-the-people-given-the-group-size-they-belong-to/ */
//class Solution {
//public:
//    vector<vector<int>> groupThePeople(vector<int>& g) {
//        vector<vector<int>> vec;
//
//        for (int i = 0; i < g.size(); i++)
//        {
//            bool flag = true;
//            for (int j = 0; j < vec.size(); j++)
//                if (vec[j].size() < g[i] && g[i] == g[vec[j][0]])
//                {
//                    vec[j].push_back(i);
//                    flag = false;
//                    break;
//                }
//            if (flag)
//            {
//                vec.push_back(vector<int>(1, i));
//            }
//        }
//
//        return vec;
//
//    }
//};

/* 最多能完成排序的块 II*/
/* https://leetcode.cn/problems/max-chunks-to-make-sorted-ii/comments/ */
//// class Solution {
//// public:
////     int maxChunksToSorted(vector<int>& arr) {
//
////         vector<int> myarr = arr;
////         sort(myarr.begin(), myarr.end());
//
////         int res = 0;
////         long long sum1 = 0, sum2 = 0;
//
////         for(int i = 0; i < arr.size(); i++)
////         {
////             sum1 += arr[i];
////             sum2 += myarr[i];
////             if(sum1 == sum2) 
////                 res++;
////         }
//
////         return res;
//
////     }
//// };
//// //升序排列的myarr, 从头往后分割区间, 则其区间和, 一定小于等于对应下边arr的区间和
//// //相等时, 即代表可以切割
//
//class Solution {
//public:
//    int maxChunksToSorted(vector<int>& arr) {
//
//        int Min = 0x3f3f3f3f;
//        vector<int> minVal(arr.size(), 0);
//        for (int i = arr.size() - 1; i >= 0; i--)
//        {
//            Min = min(Min, arr[i]);
//            minVal[i] = Min;
//        }
//        int res = 1, Max = 0;
//        //对于第i个数 当且仅当i和它前面所有数的最大值 小于 i后面所有数的最小值时 可以把i和它前面的数分出去 结果 + 1 
//        for (int i = 0; i < arr.size() - 1; i++)
//        {
//            Max = max(Max, arr[i]);
//            if (Max <= minVal[i + 1])
//                res++;
//        }
//
//        return res;
//    }
//};


/*统计子矩阵*/
/* https://www.acwing.com/problem/content/4408/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//const int N = 503, M = 503;
//
//int sum[N][M] = { 0 };
//
//int n, m, k, v;
//long long res = 0;
//
//int main()
//{
//    //二维前缀和
//    scanf("%d%d%d", &n, &m, &k);
//    for (int i = 1; i <= n; i++)
//        for (int j = 1; j <= m; j++)
//        {
//            scanf("%d", &sum[i][j]);
//            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
//        }
//
//
//    //当行一定时, 优化列的判断--->O(N^3)
//    for (int i = 1; i <= n; i++)
//        for (int ii = 0; ii < i; ii++)
//            for (int jj = 0, j = 1; j <= m; j++)
//            {
//                while (jj < j && sum[i][j] - sum[i][jj] - sum[ii][j] + sum[ii][jj] > k) jj++;
//                res += j - jj;
//            }
//
//
//    cout << res;
//    return 0;
//}
