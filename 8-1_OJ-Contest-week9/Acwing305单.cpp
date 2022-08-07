#define _CRT_SECURE_NO_WARNINGS 1

/* https://leetcode.cn/contest/weekly-contest-305/ */

/*算术三元组的数目*/
//class Solution {
//public:
//    set<int> sv;
//    int arithmeticTriplets(vector<int>& nums, int diff) {
//        int res = 0;
//        for (auto x : nums)
//            sv.insert(x);
//        for (auto x : nums)
//            if (sv.count(x + diff) && sv.count(x + diff + diff)) res++;
//
//        return res;
//    }
//};

/*受限条件下可到达节点的数目*/
//class Solution {
//public:
//    unordered_map<int, vector<int>> mvn;//存非受限节点, 和它的边
//    unordered_set<int> sr; //受限节点
//    bool st[100007];//是否遍历
//    int reachableNodes(int n, vector<vector<int>>& q, vector<int>& r) {
//        for (auto x : r)
//            sr.insert(x);
//        for (auto arr : q)
//        {
//            if (sr.count(arr[0]) || sr.count(arr[1])) continue;
//
//            mvn[arr[0]].push_back(arr[1]);
//            mvn[arr[1]].push_back(arr[0]);
//        }
//
//        int res = 0;
//        queue<int> que;
//        que.push(0), res = 1, st[0] = true;
//        while (que.size())
//        {
//            int top = que.front();
//            que.pop();
//
//            for (auto x : mvn[top])
//            {
//                if (st[x]) continue;
//
//                que.push(x);
//                res++;
//                st[x] = true;
//            }
//
//
//        }
//        return res;
//    }
//};

/*检查数组是否存在有效划分*/

/*最长理想子序列*/
//class Solution {
//public:
//    int longestIdealString(string s, int k) {
//        int dp[26] = { 0 };//以 'a' + i 结尾的最长子序列
//
//        for (int i = 0; i < s.size(); i++)
//        {
//            dp[s[i] - 'a']++;//同元素
//            for (int j = 1; j <= k; j++)
//            {
//                if (s[i] - j >= 'a')//左界限
//                    dp[s[i] - 'a'] = max(dp[s[i] - 'a'], dp[s[i] - j - 'a'] + 1);
//                if (s[i] + j <= 'z')//右界性
//                    dp[s[i] - 'a'] = max(dp[s[i] - 'a'], dp[s[i] + j - 'a'] + 1);
//            }
//        }
//        int res = 0;
//        for (auto x : dp)
//            res = max(res, x);
//
//        return res;
//
//    }
//};