
/*672. 灯泡开关 Ⅱ*/
/* https://leetcode.cn/problems/bulb-switcher-ii/submissions/ */

class Solution {
public:
    int flipLights(int n, int presses) {
        if(presses == 0) return 1;
        if(n == 1){
            return 2;
        }
        else if(n == 2){
            if(presses == 1) return 3;
            else return 4;
        }
        else{
            if(presses == 1) return 4;
            else if(presses == 2) return 7;
            else return 8;
        }
    }
};

//作者：sen-xm
