#define _CRT_SECURE_NO_WARNINGS 1

/*1346. 检查整数及其两倍数是否存在*/
/* https://leetcode.cn/problems/check-if-n-and-its-double-exist/submissions/ */
//class Solution {
//public:
//    bool checkIfExist(vector<int>& arr) {
//        bool hash[4011] = { 0 };
//        int _0cnt = 0;
//        for (auto x : arr)
//        {
//            if (x == 0) _0cnt++;
//            hash[x + 2000] = true;
//        }
//        for (auto x : arr)
//        {
//            if (x && x * 2 + 2000 < 4011 && hash[x * 2 + 2000]) return true;
//            if (x == 0)
//                if (_0cnt > 1) return true;
//        }
//        return false;
//    }
//};