
/*ÿ��Ԫ������ż���ε�����ַ���*/
/* https://leetcode.cn/problems/find-the-longest-substring-containing-vowels-in-even-counts/ */

/*
* ��һ�뷨ʱǰ׺�Ͳ��, ͳ��aeiou�ĸ���, �����Ӷȹ��� O(N^2);
* �����, �� - �� = ż, ż - ż = ż, �򽫸��� ת��Ϊ ��ż״̬;
* ��¼����״̬��һ�γ��ֵ�λ��, �������
*------------------------------
* 1. aeiou ������ �����±����� ����
* 2. ��int��ǰ����ֽ� ӳ��Ϊ aeiou�� ��ż״̬
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