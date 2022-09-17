
/*1624. 两个相同字符之间的最长子字符串*/
/* https://leetcode.cn/problems/largest-substring-between-two-equal-characters/ */

class Solution {

private:

    unordered_map<char, int> mcp;

public:
    int maxLengthBetweenEqualCharacters(string s) {

        int res = -1;

        for(int i = 0; i < s.size(); i++)
        {
            if(mcp.count(s[i]))
                res = max(res, i - mcp[s[i]] - 1);
            else
                mcp[s[i]] = i;
        }

        return res;
    }
};