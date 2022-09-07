
/*���ŵ�ӰԺ��λ*/
/* https://leetcode.cn/problems/cinema-seat-allocation/solution/ */


/*
* ʮ����......����ֱ���������¼
* 1. ͨ�� map ͳ��ĳ���ѱ�ԤԼ����λ���, Ȼ��ģ��
* 2. λ����, �����01״̬, ����Ϊ1,����Ϊ0, ��¼ĳ�ŵ�״̬
*   �� 2~5, 4~7, 6~9,���ֿ�λ���԰���4�˼�ͥ, ��0x0111100000, 0x0001111000, 0x0000011110 ����
    ���ܵõ���������״̬���ɰ���
    ����ֻͳ��2~9�����Ż�,��ٷ����
*/

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, vector<int>> miv;
        for(auto& vec : reservedSeats)
            miv[vec[0]].push_back(vec[1]);
        
        //��ͳ�ƿ��ſ��԰��ŵļ�ͥ
        int res = (n - miv.size()) * 2;

        bool st[11] = {false};
        for(auto& [r, pos] : miv)
        {
            memset(st, true, sizeof st);
            for(auto& p : pos)
                st[p] = false;
            if(st[2] && st[3] && st[4] && st[5])
            {
                st[2] = st[3] = st[4] = st[5] = false;
                res ++;
            }
            if(st[4] && st[5] && st[6] && st[7])
            {
                st[4] = st[5] = st[6] = st[7] = false;
                res ++;
            }
            else if(st[6] && st[7] && st[8] && st[9])
            {
                st[6] = st[7] = st[8] = st[9] = false;
                res ++;
            }
        }
        return res;
    }
};