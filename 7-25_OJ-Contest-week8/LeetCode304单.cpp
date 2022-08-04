#define _CRT_SECURE_NO_WARNINGS 1


/* https://leetcode.cn/contest/weekly-contest-304/ */

/*使数组中所有元素都等于零*/
//class Solution {
//public:
//    int minimumOperations(vector<int>& nums) {
//        set<int> se;
//
//        for (auto x : nums)
//        {
//            if (x) se.insert(x);
//        }
//
//        return se.size();
//
//    }
//};

/*分组的最大数量*/
//class Solution {
//public:
//    int maximumGroups(vector<int>& grades) {
//        int cnt = 0, N = grades.size();
//
//        for (; ; cnt++)
//        {
//            if (cnt * (cnt + 1) > 2 * N) break;
//        }
//
//        return cnt - 1;
//    }
//};

/*找到离给定两个节点最近的节点*/
//class Solution {
//public:
//    int closestMeetingNode(vector<int>& edges, int node1, int node2)
//    {
//        //const int N = 1e5 + 11;
//        //int res1[N], res2[N];不支持变长数组
//        int n = edges.size();
//        int res1[n], res2[n];
//        for (int i = 0; i < n; i++)
//            res1[i] = res2[i] = -1;
//        res1[node1] = res2[node2] = 0;
//
//        int n1 = node1, n2 = node2, step = 1;
//        while (~edges[n1])
//        {
//            n1 = edges[n1];
//            if (res1[n1] != -1) break;//遇环退出
//            res1[n1] = step++;
//        }
//        step = 1;
//        while (~edges[n2])
//        {
//            n2 = edges[n2];
//            if (res2[n2] != -1) break;
//            res2[n2] = step++;
//        }
//
//        int res = 1e5 + 7, pos = -1;
//        for (int i = 0; i < n; i++)
//            if (res1[i] != -1 && res2[i] != -1)
//                if (res > max(res1[i], res2[i]))
//                {
//                    res = max(res1[i], res2[i]);
//                    pos = i;
//                }
//        return pos;
//    }
//};

/*图中的最长环*/
//class Solution {
//public:
//    vector<bool> st;//统计是否遍历过
//    vector<int> p;//全局
//    vector<int> in_stk;//统计元素是否在此次遍历中, 以深度为标识
//    int ans = -1;
//
//    void dfs(int u, int dis)
//    {
//        st[u] = true;//标识遍历
//        in_stk[u] = dis;//深度入栈
//        int ne = p[u];//下一个节点
//        if (~ne)//存在
//        {
//            if (!st[ne])//未遍历
//            {
//                dfs(ne, dis + 1);
//            }
//            else if (in_stk[ne])//遍历过, 且在此次遍历中
//            {
//                ans = max(ans, dis + 1 - in_stk[ne]);//dis+1是ne的深度, 减去第一次深度, 差为环长度
//            }
//        }
//        in_stk[u] = 0;//遍历结束, 退栈
//    }
//
//    int longestCycle(vector<int>& edges) {
//        int n = edges.size();
//        st = vector<bool>(n);
//        in_stk = vector<int>(n);
//        this->p = edges;
//
//        for (int i = 0; i < n; i++)
//        {
//            if (!st[i])
//                dfs(i, 1);
//        }
//
//        return ans;
//    }
//};