
/*670. 最大交换*/
/* https://leetcode.cn/problems/maximum-swap/solution/ */

/*
* 数值变大, 高位交换低位
* 模拟高位交换, 则被交换的低位应该从右遍历
* 低位的值越高越好, 且值相等时, 位越低越好
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