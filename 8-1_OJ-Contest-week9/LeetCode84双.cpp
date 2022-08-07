#define _CRT_SECURE_NO_WARNINGS 1

/* https://leetcode.cn/contest/biweekly-contest-84/ */

/*合并相似物品*/
//class Solution {
//public:
//    map <int, int> mvw;
//    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
//
//        for (auto arr : items1)
//            mvw[arr[0]] += arr[1];
//        for (auto arr : items2)
//            mvw[arr[0]] += arr[1];
//
//        vector<vector<int>> res(mvw.size(), vector<int>(2));
//        int len = 0;
//        for (auto x : mvw)
//        {
//            res[len][0] = x.first;
//            res[len][1] = x.second;
//            len++;
//        }
//        return res;
//    }
//};

/*统计坏数对*/
//class Solution {
//public:
//    map <int, int> msc;
//    long long countBadPairs(vector<int>& nums) {
//        long long res = 0;
//        int cnt = 0;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            res += (cnt - msc[i - nums[i]]);
//            cnt++;
//            msc[i - nums[i]]++;
//        }
//
//        return res;
//
//    }
//};
////i < j, 用遍历解决
////j - i != nums[j] - nums[i] ->>>> i - nums[i] != j - nums[j];
////则只需统计已经出现的元素的 pos - nums[pos]值 和 当前元素不同值 的元素个数 

/*任务调度器Ⅱ*/
//class Solution {
//public:
//    map <int, long long> mtd;
//    long long taskSchedulerII(vector<int>& arr, int space) {
//        long long res = 0;
//        int n = arr.size(), i = 0;
//        while (true)
//        {
//            res++;
//            if (mtd[arr[i]] == 0)//任务类型第一次出现, 直接开干
//            {
//                mtd[arr[i]] = res;
//                i++;
//            }
//            else if (res - mtd[arr[i]] > space)//间隔时间满足, 开干
//            {
//                mtd[arr[i]] = res;
//                i++;
//            }
//            else//瞬移到满足的天数, 开干
//            {
//                res = mtd[arr[i]] + space + 1;
//                mtd[arr[i]] = res;
//                i++;
//            }
//            if (i == n)//全干完
//                break;
//
//        }
//        return res;
//    }
//};

/* 将数组排序的最少替换次数 */