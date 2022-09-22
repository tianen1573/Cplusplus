
/*�ַ������*/
/* https://leetcode.cn/problems/multiply-strings/ */

class Solution {

    //�˷�, A��Ϊ�ַ������ֲ���, ��������
    string mul(string A, int b)
    {
        unsigned carry = 0;
        
        if(b == 0) return "0";
        for (int i = 0; i < A.size(); i ++ )
        {
            int a = A[i] - '0';
            A[i] = (a * b + carry) % 10 + '0';
            carry = (a * b + carry) / 10;
        }
        
        while(carry > 0)//ʣ���λ
        {
            A.push_back(carry % 10 + '0');
            carry /= 10;
        }

        reverse(A.begin(), A.end());
        return A;
        
    }
    //�ӷ�, ans��Ϊ��, ������
    static void sum(string& strA, string& strB)
    {
        reverse(strA.begin(), strA.end());
        reverse(strB.begin(), strB.end());
        int carry = 0;
        int i = 0;

        for (; i < strA.size() && i < strB.size(); i++)
        {
            int a = strA[i] - '0', b = strB[i] - '0';
            strA[i] = (a + b + carry) % 10 + '0';
            carry = (a + b + carry) / 10;
        }

        while (i < strA.size())
        {
            int a = strA[i] - '0';
            strA[i] = (a + carry) % 10 + '0';
            carry = (a + carry) / 10;
            i++;
        }
        while (i < strB.size())
        {
            int b = strB[i] - '0';
            strA.push_back('0' + (b + carry) % 10 );
            carry = (b + carry) / 10;
            i++;
        }
        if (carry == 1) strA.push_back('1');
        reverse(strA.begin(), strA.end());
        return;
    }

public:
    string multiply(string num1, string num2) {

        reverse(num1.begin(), num1.end());
        string ans = "0";

        for(int i = 0; i < num2.size(); i++)
        {
            string mulVal = mul(num1, num2[i] - '0');
            if(mulVal != "0")//�ж��Ƿ�Ϊ0
            {
                for(int j = i; j < num2.size() - 1; j++)
                {
                    mulVal += '0';
                }
            }
            sum(ans, mulVal);
        }
        return ans;
    }
};