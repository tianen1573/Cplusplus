
/*重新排列奶牛*/
/* https://www.acwing.com/problem/content/1923/ */

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 111;

int a[N], b[N], f[N], s[N];
int n;

int find(int x)  // 并查集
{
    if (f[x] != x) f[x] = find(f[x]);
    return f[x];
}


int main()
{
    cin >> n;
    
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    for (int i = 0; i < n; i ++ )
    {
        int x;
        cin >> x;
        b[x] = i;
    }
    
    for(int i = 0; i < n; i ++ ) f[i] = i, s[i] = 1;
    
    for(int i = 0; i < n; i ++ )
    {
        int x = a[i], y = a[b[x]];
        int fx = find(x), fy = find(y);
        
        if(fx != fy)
        {
            s[fy] += s[fx];
            f[fx] = fy;
        }
    }
    
    int res = 0, mx = -1;
    
    for (int i = 0; i < n; i ++ )
        if(f[i] == i && s[i] > 1)
        {
            res ++;
            mx = max(mx, s[i]);
        }
        
    cout << res << ' ' << mx;
    return 0;
}

//by yxc