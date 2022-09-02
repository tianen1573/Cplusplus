
/*每个元音包含偶数次的最长子字符串*/
/* https://leetcode.cn/problems/find-the-longest-substring-containing-vowels-in-even-counts/ */

/*
* 第一想法时前缀和差分, 统计aeiou的个数, 但复杂度过高 O(N^2);
* 看题解, 奇 - 奇 = 偶, 偶 - 偶 = 偶, 则将个数 转换为 奇偶状态;
* 记录各个状态第一次出现的位置, 相减即可
*------------------------------
* 1. aeiou 的数量 随着下标增加 不减
* 2. 将int的前五个字节 映射为 aeiou的 奇偶状态
*/

class Solution {
public:
    int findTheLongestSubstring(string s) {

        unordered_map<int, int> mss;
        int st = 0; mss[st] = -1;
        int res = 0;
        int i = 0;
        for(auto x : s)
        {
            
            if(x == 'a') st ^= 0x00001;
            else if(x == 'e') st ^= 0x00010;
            else if(x == 'i') st ^= 0x00100;
            else if(x == 'o') st ^= 0x01000;
            else if(x == 'u') st ^= 0x10000;

            if(mss.count(st)) res = max(res, i - mss[st]);
            else mss[st] = i;

            i++;
        }

        return res;

    }
};