
/*1370. �����½��ַ���*/
/* https://leetcode.cn/problems/increasing-decreasing-string/ */



 /* 
 * �ڶ�������, ��������ͬ�ַ�, ��ee,��ѡ�� e ʱ, ʣ�µ�eΪ��С�����, ������ڶ���
 * ��ʾ��3����������....
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