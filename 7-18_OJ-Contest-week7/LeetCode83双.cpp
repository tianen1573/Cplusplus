#define _CRT_SECURE_NO_WARNINGS 1

/* https://leetcode.cn/contest/biweekly-contest-83/ */

/*6128. ��õ��˿�����*/
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

/*6129. ȫ0���������Ŀ*/
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

/*6130. �����������ϵͳ*/
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
//            it->second = number; // �Ż���ֱ���ڵ������ϸ�ֵ
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
////���ߣ�endlesscheng

/*�����ܵõ����������*/
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
////res�ǰ����Ȼ��ֵ�,��Ҫ��ÿ�����ȵ������ж�Ҫ����
////�����ֱ�Ӽ�����������ж��ٸ�1~k