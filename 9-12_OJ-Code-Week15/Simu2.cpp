
/*1619. ɾ��ĳЩԪ�غ�������ֵ*/
/* https://leetcode.cn/problems/mean-of-array-after-removing-some-elements/ */

/*
* ����ģ��
*/


class Solution {
public:
    double trimMean(vector<int>& arr) {

        sort(arr.begin(), arr.end());

       double sum = 0;

        for(int i = arr.size() / 20; i < arr.size() * 19 / 20; i++)
            sum += arr[i];
        
        sum /= (1.0 * arr.size() * 0.9);
        return sum;

    }
};