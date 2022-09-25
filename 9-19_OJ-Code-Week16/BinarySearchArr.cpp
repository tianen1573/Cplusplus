
/*��ָ Offer 11. ��ת�������С����*/
/* https://leetcode.cn/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/ */

class Solution {
public:
    int minArray(vector<int>& numbers) {
        // int _min = 9999;

        // for(auto& v : numbers)
        // {
        //     if(v < _min)
        //     {
        //         _min = v;
        //     }
        // }
        // return _min;

        int l = 0, r = numbers.size() - 1;
        while (l < r) 
        {
            int mid = ((r - l) >> 1) + l;
            //ֻҪ�ұ߱��м�����ұ�һ������������
            if (numbers[r] > numbers[mid]) {
                r = mid;
            } else if (numbers[r] < numbers[mid]) {
                l = mid + 1;
             //ȥ��
            } else r--;
        }
        return numbers[l];
    }
};