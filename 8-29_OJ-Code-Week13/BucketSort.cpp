
/*1370. 上升下降字符串*/
/* https://leetcode.cn/problems/increasing-decreasing-string/ */



 /* 
 * 第二条规则, 若存在相同字符, 如ee,当选到 e 时, 剩下的e为最小或最大, 不满足第二条
 * 但示例3好像不是这样....
 */  


class Solution {
public:
    string sortString(string s) {

        int ch[26] = {0};
        for(char x : s)
            ch[x - 'a']++;

        string res;

        while(res.size() < s.size())
        {
            for(int i = 0; i < 26; i++)
                if(ch[i])
                {
                    res += i + 'a';
                    ch[i]--;
                }
            
            for(int i = 25; i >= 0; i--)
                if(ch[i])
                {
                    res += i + 'a';
                    ch[i]--;
                }
        }
        return res;
    }
};