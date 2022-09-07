

/*1385. ���������ľ���ֵ*/
/* https://leetcode.cn/problems/find-the-distance-value-between-two-arrays/ */

/*
* ģ��
*/

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {

        sort(arr2.begin(), arr2.end());
        int res = arr1.size();

        for(auto& x : arr1)
        {
            int l = x - d, r = x + d;
            for(auto& y : arr2)
            {
                if(y > r) break;
                if(y >= l && y <= r)
                {
                    res--;
                    break;
                }
            }
        }

        return res;

    }
};