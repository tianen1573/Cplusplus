#define _CRT_SECURE_NO_WARNINGS 1

/*�û�����*/
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

/* ������������Ŀ� II*/
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
//// //�������е�myarr, ��ͷ����ָ�����, ���������, һ��С�ڵ��ڶ�Ӧ�±�arr�������
//// //���ʱ, ����������и�
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
//        //���ڵ�i���� ���ҽ���i����ǰ�������������ֵ С�� i��������������Сֵʱ ���԰�i����ǰ������ֳ�ȥ ��� + 1 
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


/*ͳ���Ӿ���*/
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
//    //��άǰ׺��
//    scanf("%d%d%d", &n, &m, &k);
//    for (int i = 1; i <= n; i++)
//        for (int j = 1; j <= m; j++)
//        {
//            scanf("%d", &sum[i][j]);
//            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
//        }
//
//
//    //����һ��ʱ, �Ż��е��ж�--->O(N^3)
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
