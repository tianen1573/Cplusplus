#define _CRT_SECURE_NO_WARNINGS 1

/* https://leetcode.cn/contest/weekly-contest-305/ */

/*������Ԫ�����Ŀ*/
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

/*���������¿ɵ���ڵ����Ŀ*/
//class Solution {
//public:
//    unordered_map<int, vector<int>> mvn;//������޽ڵ�, �����ı�
//    unordered_set<int> sr; //���޽ڵ�
//    bool st[100007];//�Ƿ����
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

/*��������Ƿ������Ч����*/
//class Solution {
//public:
//    bool validPartition(vector<int>& nums) {
//        const int N = 1e5 + 11;
//        int n = nums.size();
//        bool f[N] = { 0 };
//        f[0] = true;
//
//        for (int i = 1; i < n; i++)
//            if ((f[i - 1] && nums[i] == nums[i - 1]) ||//����1
//                (i > 1 && f[i - 2] && nums[i] == nums[i - 1] && nums[i] == nums[i - 2]) ||//����2
//                (i > 1 && f[i - 2] && nums[i] == nums[i - 1] + 1 && nums[i] == nums[i - 2] + 2))//����3
//                f[i + 1] = true;
//
//        return f[n];
//    }
//};

/*�����������*/
//class Solution {
//public:
//    int longestIdealString(string s, int k) {
//        int dp[26] = { 0 };//�� 'a' + i ��β���������
//
//        for (int i = 0; i < s.size(); i++)
//        {
//            dp[s[i] - 'a']++;//ͬԪ��
//            for (int j = 1; j <= k; j++)
//            {
//                if (s[i] - j >= 'a')//�����
//                    dp[s[i] - 'a'] = max(dp[s[i] - 'a'], dp[s[i] - j - 'a'] + 1);
//                if (s[i] + j <= 'z')//�ҽ���
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