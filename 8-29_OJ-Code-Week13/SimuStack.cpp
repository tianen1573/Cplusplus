
/*删减*/
/* https://www.acwing.com/problem/content/description/1885/ */

/*
* 直接用 string::find() 查找, s.size() = 1e6, 会超时
* 运用栈的思想, 每次尾插一个字符, 判断 s的末尾 是否是字符串t
*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

string s, t;

int main()
{
    cin >> s >> t;
    
    string stk;
    
    for(auto c : s)
    {
        stk += c;
        
        while(stk.size() >= t.size() && stk.substr(stk.size() - t.size(), -1) == t)
            stk.erase(stk.size() - t.size(), -1);
    }
    
    cout << stk;
    
    return 0;
    
}