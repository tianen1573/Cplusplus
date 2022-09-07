
/*安排电影院座位*/
/* https://leetcode.cn/problems/cinema-seat-allocation/solution/ */


/*
* 十亿排......不能直接用数组记录
* 1. 通过 map 统计某排已被预约的座位情况, 然后模拟
* 2. 位运算, 抽象成01状态, 无人为1,有人为0, 记录某排的状态
*   与 2~5, 4~7, 6~9,三种空位可以安排4人家庭, 即0x0111100000, 0x0001111000, 0x0000011110 相与
    若能得到上述三个状态即可安排
    可以只统计2~9进行优化,如官方题解
*/

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, vector<int>> miv;
        for(auto& vec : reservedSeats)
            miv[vec[0]].push_back(vec[1]);
        
        //先统计空排可以安排的家庭
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