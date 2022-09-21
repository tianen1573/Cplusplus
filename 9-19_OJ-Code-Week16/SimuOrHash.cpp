
/*找出字符串中第一个只出现一次的字符*/
/* https://www.nowcoder.com/practice/e896d0f82f1246a3aa7b232ce38029d4?tpId=37&&tqId=21282&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking */


#include <iostream>
using namespace std;

int main() 
{
    int cnt[26] = {0};
    string str;
    char res = '\0';

    cin >> str;

    for(char& ch : str)
    {
        cnt[ch - 'a']++;
    }

    for(auto& ch : str)
    {
        //cout << cnt[ch - 'a'] << ' ';
        if(cnt[ch - 'a'] == 1)
        {
            res = ch;
            break;
        }
    }

    if(res) cout << res;
    else cout << "-1";

    return 0;
}