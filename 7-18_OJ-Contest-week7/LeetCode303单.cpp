#define _CRT_SECURE_NO_WARNINGS 1

/* https://leetcode.cn/contest/weekly-contest-303 */

/*6124. 第一次出现两次的字母*/
//class Solution {
//public:
//    char repeatedCharacter(string s) {
//        int cnt[26] = { 0 };
//
//        for (auto x : s)
//        {
//            if (cnt[x - 'a'] + 1 == 2) return x;
//            cnt[x - 'a']++;
//        }
//        return 'a';
//    }
//};

/*6125. 相等行列对*/
//class Solution {
//public:
//
//    bool isE(vector<int>& a, vector<int>& b)
//    {
//        for (int i = 0; i < a.size(); i++)
//            if (a[i] != b[i]) return false;
//
//        return true;
//    }
//
//    int equalPairs(vector<vector<int>>& grid) {
//
//        const int N = grid.size() + 5;
//        int n = grid.size();
//        vector<int> Cnums[N], Rnums[N];
//
//        for (int i = 0; i < n; i++)
//            Rnums[i] = grid[i];
//        for (int j = 0; j < n; j++)
//            for (int i = 0; i < n; i++)
//                Cnums[j].push_back(grid[i][j]);
//
//        int res = 0;
//        for (int i = 0; i < n; i++)
//            for (int j = 0; j < n; j++)
//                if (isE(Rnums[i], Cnums[j])) res++;
//
//
//        return res;
//
//    }
//};

/*6126. 设计食物评分系统*/
//class FoodRatings {
//public:
//
//    unordered_map<string, pair<int, string>> frc;
//    unordered_map<string, set<pair<int, string>>> hash;
//    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
//        int n = foods.size();
//        for (int i = 0; i < n; i++)
//        {
//            frc[foods[i]] = { ratings[i], cuisines[i] };
//            hash[cuisines[i]].insert({ -ratings[i], foods[i] });
//        }
//    }
//
//    void changeRating(string food, int newRating) {
//        int oldR = frc[food].first;
//        string cui = frc[food].second;
//        frc[food] = { newRating, cui };
//        hash[cui].erase({ -oldR, food });
//        hash[cui].insert({ -newRating, food });
//    }
//
//    string highestRated(string cuisine) {
//        return hash[cuisine].begin()->second;
//    }
//};
//
// /*
// * Your FoodRatings object will be instantiated and called as such:
// * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
// * obj->changeRating(food,newRating);
// * string param_2 = obj->highestRated(cuisine);
// */

/*6127. 优质数对的个数*/
//class Solution {
//public:
//    long long countExcellentPairs(vector<int>& nums, int k) {
//
//        sort(nums.begin(), nums.end());
//        nums.erase(unique(nums.begin(), nums.end()), nums.end());
//
//
//        int cnt[30] = { 0 };
//        for (auto x : nums)
//        {
//            int s = 0;
//            while (x) s += x & 1, x >>= 1;//统计1的个数
//            cnt[s]++;
//        }
//
//        long long res = 0;
//        for (int j = 1; j < 30; j++)
//            for (int i = 1; i < 30; i++)
//                if (i + j >= k)
//                    res += cnt[i] * cnt[j];
//
//        return res;
//
//    }
//};
////a + b == (a&b) + (a|b),二进制位1的个数是等价的
////则统计数组元素二进制1的个数,然后模拟遍历 i+j >= k, 对应的元素个数相乘
