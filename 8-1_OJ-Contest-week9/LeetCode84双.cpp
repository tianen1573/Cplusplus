#define _CRT_SECURE_NO_WARNINGS 1

/* https://leetcode.cn/contest/biweekly-contest-84/ */

/*�ϲ�������Ʒ*/
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

/*ͳ�ƻ�����*/
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
////i < j, �ñ������
////j - i != nums[j] - nums[i] ->>>> i - nums[i] != j - nums[j];
////��ֻ��ͳ���Ѿ����ֵ�Ԫ�ص� pos - nums[pos]ֵ �� ��ǰԪ�ز�ֵͬ ��Ԫ�ظ��� 

/*�����������*/
//class Solution {
//public:
//    map <int, long long> mtd;
//    long long taskSchedulerII(vector<int>& arr, int space) {
//        long long res = 0;
//        int n = arr.size(), i = 0;
//        while (true)
//        {
//            res++;
//            if (mtd[arr[i]] == 0)//�������͵�һ�γ���, ֱ�ӿ���
//            {
//                mtd[arr[i]] = res;
//                i++;
//            }
//            else if (res - mtd[arr[i]] > space)//���ʱ������, ����
//            {
//                mtd[arr[i]] = res;
//                i++;
//            }
//            else//˲�Ƶ����������, ����
//            {
//                res = mtd[arr[i]] + space + 1;
//                mtd[arr[i]] = res;
//                i++;
//            }
//            if (i == n)//ȫ����
//                break;
//
//        }
//        return res;
//    }
//};

/*����������������滻����--̰��*/
//class Solution {
//public:
//    long long minimumReplacement(vector<int>& nums) {
//        long long res = 0;
//        int n = nums.size();
//        int last = nums[n - 1];
//        for (int i = n - 1; i >= 0; i--)
//        {
//            if (nums[i] <= last) last = nums[i];
//            else
//            {
//                int k = (nums[i] + last - 1) / last;
//                last = nums[i] / k;
//                res += k - 1;
//            }
//        }
//
//        return res;
//    }
//};
////��Դ: /* https://leetcode.cn/problems/minimum-replacements-to-sort-the-array/solution/by-endlesscheng-d11y/ */
