
/*剑指 Offer 11. 旋转数组的最小数字*/
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
            //只要右边比中间大，那右边一定是有序数组
            if (numbers[r] > numbers[mid]) {
                r = mid;
            } else if (numbers[r] < numbers[mid]) {
                l = mid + 1;
             //去重
            } else r--;
        }
        return numbers[l];
    }
};