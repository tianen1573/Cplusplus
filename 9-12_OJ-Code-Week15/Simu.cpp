
/*670. ��󽻻�*/
/* https://leetcode.cn/problems/maximum-swap/solution/ */

/*
* ��ֵ���, ��λ������λ
* ģ���λ����, �򱻽����ĵ�λӦ�ô��ұ���
* ��λ��ֵԽ��Խ��, ��ֵ���ʱ, λԽ��Խ��
*/


class Solution {
public:

    // static string IntTostr(int val)
    // {
    //     string res;
    //     while(val)
    //     {
    //         res += val % 10 + '0';
    //         val /= 10;
    //     }

    //     reverse(res.begin(), res.end());
    //     return res;
    // }

    int maximumSwap(int num) {

        string str = to_string(num);
        //cout << str;

        for(int i = 0; i < str.size(); i++)
        {
            char Max = str[i];
            int pos = -1;
            for(int j = str.size() - 1; j > i; j--)
                if(str[j] > Max)
                {
                    Max = str[j];
                    pos = j;
                }
            if(~pos)
            {
                str[pos] = str[i];
                str[i] = Max;
                int res = stoi(str);
                return res;
            }
        }

        return num;

    }
};