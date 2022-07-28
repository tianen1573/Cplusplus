#define _CRT_SECURE_NO_WARNINGS 1

/* https://leetcode.cn/contest/biweekly-contest-83/ */

/*6128. 最好的扑克手牌*/
//class Solution {
//public:
//    string bestHand(vector<int>& ranks, vector<char>& suits) {
//
//        int cnt[15] = { 0 };
//        int color[4] = { 0 };
//
//        for (int i = 0; i < 5; i++)
//        {
//            cnt[ranks[i]]++;
//            color[suits[i] - 'a']++;
//        }
//        int Max = 1;
//
//        for (int i = 1; i <= 14; i++) Max = max(Max, cnt[i]);
//
//        for (auto x : color)
//            if (x == 5) return "Flush";
//
//        if (Max >= 3) return "Three of a Kind";
//        if (Max == 2) return "Pair";
//
//        return "High Card";
//
//    }
//};

/*6129. 全0子数组的数目*/
//class Solution {
//public:
//    long long zeroFilledSubarray(vector<int>& nums) {
//
//        long long res = 0, Cnt = 0;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            if (nums[i] == 0) Cnt++;
//            else if (Cnt)
//            {
//                res += (Cnt * (Cnt + 1) / 2);
//                Cnt = 0;
//            }
//        }
//        res += (Cnt * (Cnt + 1) / 2);
//        return res;
//    }
//};

/*6130. 设计数字容器系统*/
//class NumberContainers {
//public:
//    map<int, int> m;
//    NumberContainers() {
//        m.clear();
//    }
//
//    void change(int index, int number) {
//        m[index] = number;
//    }
//
//    int find(int number) {
//        for (auto& p : m)
//        {
//            if (p.second == number)
//                return p.first;
//        }
//        return -1;
//    }
//};
//
// /*
// * Your NumberContainers object will be instantiated and called as such:
// * NumberContainers* obj = new NumberContainers();
// * obj->change(index,number);
// * int param_2 = obj->find(number);
// */
//class NumberContainers {
//    map<int, int> m;
//    map<int, set<int>> ms;
//
//public:
//    void change(int index, int number) {
//        auto it = m.find(index);
//        if (it != m.end()) {
//            ms[it->second].erase(index);
//            it->second = number; // 优化：直接在迭代器上赋值
//        }
//        else m[index] = number;
//        ms[number].insert(index);
//    }
//
//    int find(int number) {
//        auto it = ms.find(number);
//        return it == ms.end() || it->second.empty() ? -1 : *it->second.begin();
//    }
//};
//
////作者：endlesscheng

/*不可能得到的最短序列*/
//class Solution {
//public:
//    int shortestSequence(vector<int>& rolls, int k) {
//        set<int> h;
//        int res = 0;
//        for (int x : rolls)
//        {
//            h.insert(x);
//            if (h.size() == k)
//            {
//                h.clear();
//                res++;
//            }
//        }
//        return res + 1;
//
//    }
//};
////res是按长度划分的,又要求每个长度的子序列都要存在
////则可以直接计算从左至右有多少个1~k