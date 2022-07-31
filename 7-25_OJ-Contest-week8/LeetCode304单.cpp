#define _CRT_SECURE_NO_WARNINGS 1


/* https://leetcode.cn/contest/weekly-contest-304/ */

/*6132. 使数组中所有元素都等于零*/
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

/*6133. 分组的最大数量*/
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

/*6134. 找到离给定两个节点最近的节点*/
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