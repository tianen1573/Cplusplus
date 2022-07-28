#define _CRT_SECURE_NO_WARNINGS 1

/* https://leetcode.cn/contest/weekly-contest-302/ */

/*611. 数组能形成多少数对*/
//class Solution {
//public:
//    vector<int> numberOfPairs(vector<int>& nums) {
//
//        map<int, int> m;
//
//        for (auto x : nums)
//            m[x]++;
//        int tcnt = 0, ocnt = 0;
//        for (auto p : m)
//        {
//            tcnt += p.second / 2;
//            ocnt += p.second % 2;
//        }
//
//        vector<int>res = { tcnt, ocnt };
//
//        return res;
//
//    }
//};

/*6120. 数位和相等数对的最大和*/
//class Solution {
//public:
//    int maximumSum(vector<int>& nums) {
//        pair<int, int> pii[100011];
//
//        //记录{数位和， 数值}
//        for (int i = 0; i < nums.size(); i++)
//        {
//            int v = nums[i];
//            int sum = 0;
//            while (v)
//            {
//                sum += v % 10;
//                v /= 10;
//            }
//            pii[i] = { sum, nums[i] };
//        }
//        //排序，将相同数位和的元素排在一起
//        sort(pii, pii + nums.size());
//
//        int _max = -1;
//        //双指针:i，j 遍历 相同数位和区间 求 最大值和次大值
//        for (int i = 0; i < nums.size(); i++)
//        {
//            //初始化
//            int fm = pii[i].second, sm = -pii[i].second - 5;//若不存在相加小于-1，不更新
//            for (int j = i + 1; j < nums.size(); j++)
//            {
//
//                //更新最大 和次大
//                if (pii[j].first == pii[i].first)
//                {
//                    if (pii[j].second >= fm)
//                    {
//                        sm = fm;
//                        fm = pii[j].second;
//                    }
//                    else if (pii[j].second > sm) sm = pii[j].second;
//                }
//                //更新_max 和 i
//                else
//                {
//                    _max = max(_max, fm + sm);
//                    i = j - 1;
//                    break;
//                }
//            }
//            _max = max(_max, fm + sm);
//        }
//        return _max;
//    }
//};

/*6121. 裁剪数字后查询第 K 小的数字*/
//class Solution
//{
//public:
//    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
//        int n = nums.size(), m = queries.size();
//        typedef pair<string, int> PSI;
//        vector<PSI> strs(n);
//        vector<int>res;
//
//        for (int i = 0; i < n; i++) strs[i] = { nums[i], i };
//
//        for (auto& q : queries)
//        {
//            int k = q[0], t = q[1];
//            sort(strs.begin(), strs.end(), [&](PSI& a, PSI& b)//自定义排序
//                {
//                    for (int i = a.first.size() - t; i < a.first.size(); i++)//先字典序
//                    {
//                        if (a.first[i] < b.first[i]) return true;
//                        else if (a.first[i] > b.first[i]) return false;
//                    }
//                    return a.second < b.second;//再下标
//                });
//
//            res.push_back(strs[k - 1].second);
//        }
//
//        return res;
//
//    }
//};

/*6122. 使数组可以被整除的最少删除次数*/
//class Solution {
//    //res 是numsD数组的最小公因子，最小公因子难求，我们知道最大公因子
//    //将nums数组排序，在小于最大公因子之前，第一个除尽的就是答案
//public:
//
//    int gcd(int a, int b)
//    {
//        if (b > a) return gcd(b, a);
//
//        if (a % b == 0) return b;
//        else return gcd(b, a % b);
//    }
//
//    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
//
//        int _minrem = numsDivide[0];
//        for (int i = 0; i < numsDivide.size(); i++)
//            _minrem = gcd(_minrem, numsDivide[i]);
//
//        //cout << _minrem;
//
//        map<int, int> m;
//        int res = 0;
//
//        for (auto x : nums)
//            m[x]++;
//        for (auto x : m)
//            if (_minrem % x.first == 0) return res;
//            else res += x.second;
//
//        return -1;
//
//    }
//};