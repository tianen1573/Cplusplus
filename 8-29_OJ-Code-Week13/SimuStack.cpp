
/*ɾ��*/
/* https://www.acwing.com/problem/content/description/1885/ */

/*
* ֱ���� string::find() ����, s.size() = 1e6, �ᳬʱ
* ����ջ��˼��, ÿ��β��һ���ַ�, �ж� s��ĩβ �Ƿ����ַ���t
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