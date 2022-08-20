#define _CRT_SECURE_NO_WARNINGS 1

/*1450. 在既定时间做作业的学生人数*/
/* https://leetcode.cn/problems/number-of-students-doing-homework-at-a-given-time/ */
//class Solution {
//public:
//    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
//        const int N = 1011;
//        int sum[N] = { 0 };
//
//        for (auto x : startTime)
//            sum[x]++;
//        for (auto x : endTime)
//            sum[x + 1]--;
//
//        for (int i = 1; i < N; i++)
//            sum[i] += sum[i - 1];
//        return sum[queryTime];
//    }
//};