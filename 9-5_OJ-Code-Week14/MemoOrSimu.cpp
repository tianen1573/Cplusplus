
/*1387. ��������Ȩ������*/
/* https://leetcode.cn/problems/sort-integers-by-the-power-value/ */

/*
* ��Ŀ���ݽ�С, �ɰ�Ҫ��������, Ҳ���Լ��仯�洢�Ѿ������Ԫ�ص�Ȩֵ
*/

class Solution {
public:

    unordered_map<int, int> mvc;//���仯�洢, ���ݽ�СҲ��ֱ�Ӽ���

    int GetW(int x)
    {
        //���仯
        if(mvc.count(x)) return mvc[x] = mvc[x];
        //1
        if(x == 1) return mvc[x] = 0;
        //����
        if(x & 1) return mvc[x] = GetW(x * 3 + 1) + 1;
        //ż��
        else return mvc[x] = GetW(x >> 1) + 1;
    }

    int getKth(int lo, int hi, int k) {

        //�洢������
        vector<int> vec;
        for(int i = lo; i <= hi; i++)
            vec.push_back(i);
        
        //����
        sort(vec.begin(), vec.end(), [&](int &a, int &b)
        {
            if(GetW(a) == GetW(b)) return a < b;

            return GetW(a) < GetW(b);
        });

        return vec[k-1];

    }
};