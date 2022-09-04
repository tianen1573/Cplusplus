

/*纪录保持*/
/* https://www.acwing.com/problem/content/1946/ */

/*哈希表*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>


using namespace std;

int n, res;

int main()
{
    cin >> n;
    
    map<vector<string>, int> msc;
    
    while (n -- )
    {
        vector<string> str(3);
        cin >> str[0] >> str[1] >> str[2];
        sort(str.begin(), str.end());
        
        msc[str]++;
    }
    
    for(auto &[s, c] : msc)
        res = max(res, c);
        
    cout << res;
    
    return 0;
}