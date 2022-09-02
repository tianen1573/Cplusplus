
/*奶牛线路*/
/* https://www.acwing.com/problem/content/description/1894/ */


/*
* 只允许一条航线, 且存在先后顺序, 模拟即可
*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

bool Dep = false, Dest = false;
int res = 9999;

int dep = 0, dest = 0, N;

int main()
{
    cin >> dep >> dest >> N;
    
    int cnt, mon;
    
    for(int i = 0; i < N; i++)
    {
        int city;
        cin >> mon >> cnt;
        for(int j = 0; j < cnt ; j++)
        {
            cin >> city;
            if(Dep && Dest) continue;
            //先出发地, 再目标地
            if(city == dep) Dep = true;
            if(Dep && city == dest) Dest = true;
        }
        //更新费用
        if(Dep && Dest) res = min(res, mon);
        
        Dep = Dest = false;
    }
    
    res = res == 9999 ? -1 : res;
    cout << res;
    
    return 0;
}