
/*哞加密*/
/* https://www.acwing.com/problem/content/description/1876/ */


/*究极模拟......*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

const int N = 51, M = 51;
typedef pair<char, char> PCC;

char mp[N][M];
int n, m, MaxCnt;
map <pair<char, char>, int> mpc;
PCC res;

void find(int x, int y)
{
    if(mp[x][y] == 'M') return ;
    
    if(x - 2 >= 0 &&
       mp[x][y] != mp[x - 1][y] && mp[x - 1][y] == mp[x - 2][y] &&
       mp[x - 1][y] != 'O' &&
       MaxCnt < ++mpc[{mp[x][y], mp[x - 1][y]}])
    {
        res.first = mp[x][y], res.second = mp[x - 1][y];
        MaxCnt = mpc[res];
    }
    if(x + 2 < n &&
       mp[x][y] != mp[x + 1][y] && mp[x + 1][y] == mp[x + 2][y] &&
       mp[x + 1][y] != 'O' &&
       MaxCnt < ++mpc[{mp[x][y], mp[x + 1][y]}])
    {
        res.first = mp[x][y], res.second = mp[x + 1][y];
        MaxCnt = mpc[res];
    }
    if(y - 2 >= 0 &&
       mp[x][y] != mp[x][y - 1] && mp[x][y - 1] == mp[x][y - 2] &&
       mp[x][y - 1] != 'O' &&
       MaxCnt < ++mpc[{mp[x][y], mp[x][y - 1]}])
    {
        res.first = mp[x][y], res.second = mp[x][y - 1];
        MaxCnt = mpc[res];
    }
    if(y + 2 < m &&
       mp[x][y] != mp[x][y + 1] && mp[x][y + 1] == mp[x][y + 2] &&
       mp[x][y + 1] != 'O' &&
       MaxCnt < ++mpc[{mp[x][y], mp[x][y + 1]}])
    {
        res.first = mp[x][y], res.second = mp[x][y + 1];
        MaxCnt = mpc[res];
    }
    if(x - 2 >= 0 && y - 2 >= 0 && 
       mp[x][y] != mp[x - 1][y - 1] && mp[x - 1][y - 1] == mp[x - 2][y - 2] && 
       mp[x - 1][y - 1] != 'O' &&
       MaxCnt < ++mpc[{mp[x][y], mp[x - 1][y - 1]}])
    {
        res.first = mp[x][y], res.second = mp[x - 1][y - 1];
        MaxCnt = mpc[res];
    }
    if(x - 2 >= 0 && y + 2 < m && 
       mp[x][y] != mp[x - 1][y + 1] && mp[x - 1][y + 1] == mp[x - 2][y + 2] && 
       mp[x - 1][y + 1] != 'O' &&
       MaxCnt < ++mpc[{mp[x][y], mp[x - 1][y + 1]}])
    {
        res.first = mp[x][y], res.second = mp[x - 1][y + 1];
        MaxCnt = mpc[res];
    }
    if(x + 2 < n && y + 2 < m && 
       mp[x][y] != mp[x + 1][y + 1] && mp[x + 1][y + 1] == mp[x + 2][y + 2] && 
       mp[x + 1][y + 1] != 'O' &&
       MaxCnt < ++mpc[{mp[x][y], mp[x + 1][y + 1]}])
    {
        res.first = mp[x][y], res.second = mp[x + 1][y + 1];
        MaxCnt = mpc[res];
    }
    if(x + 2 < n && y - 2 >= 0 && 
       mp[x][y] != mp[x + 1][y - 1] && mp[x + 1][y - 1] == mp[x + 2][y - 2] && 
       mp[x + 1][y - 1] != 'O' &&
       MaxCnt < ++mpc[{mp[x][y], mp[x + 1][y - 1]}])
    {
        res.first = mp[x][y], res.second = mp[x + 1][y - 1];
        MaxCnt = mpc[res];
    }
}

int main()
{
    cin >> n >> m;
    
    for (int i = 0; i < n; i ++ )
        for(int j = 0; j < m; j++)
            cin >> mp[i][j];
    
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            find(i, j);
    
    cout << MaxCnt << endl;
    
    return 0;
}
