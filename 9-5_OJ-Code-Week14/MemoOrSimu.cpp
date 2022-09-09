
/*1387. 将整数按权重排序*/
/* https://leetcode.cn/problems/sort-integers-by-the-power-value/ */

/*
* 题目数据较小, 可按要求暴力计算, 也可以记忆化存储已经求过的元素的权值
*/

class Solution {
public:

    unordered_map<int, int> mvc;//记忆化存储, 数据较小也可直接计算

    int GetW(int x)
    {
        //记忆化
        if(mvc.count(x)) return mvc[x] = mvc[x];
        //1
        if(x == 1) return mvc[x] = 0;
        //奇数
        if(x & 1) return mvc[x] = GetW(x * 3 + 1) + 1;
        //偶数
        else return mvc[x] = GetW(x >> 1) + 1;
    }

    int getKth(int lo, int hi, int k) {

        //存储排序结果
        vector<int> vec;
        for(int i = lo; i <= hi; i++)
            vec.push_back(i);
        
        //升序
        sort(vec.begin(), vec.end(), [&](int &a, int &b)
        {
            if(GetW(a) == GetW(b)) return a < b;

            return GetW(a) < GetW(b);
        });

        return vec[k-1];

    }
};