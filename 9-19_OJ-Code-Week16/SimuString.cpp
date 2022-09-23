
/*验证回文串*/
/* https://leetcode.cn/problems/valid-palindrome/ */

/*
* 相关: 
* https://www.nowcoder.com/practice/8c949ea5f36f422594b306a2300315da?tpId=37&&tqId=21224&rp=5&ru=/activity/oj&qru=/ta/huawei/question-ranking
* https://leetcode-cn.com/problems/reverse-string-ii/
* https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/
*/

bool isEngAlphabet(char c)
{
   if ((c >= 'a' && c <= 'z')
    || (c >= '0' && c <= '9'))
       return true;

   return false;
}
class Solution {
public:
    bool isPalindrome(string s) {

    for(char& c : s)
    {
        if(c >= 'A' && c <= 'Z')
            c += 32;
    }
    int begin = 0, end = s.size() - 1;

    while (begin < end)
       {
           while (begin < end && !isEngAlphabet(s[begin]))
               begin++;
           while (begin < end && !isEngAlphabet(s[end]))
               end--;

           if(s[begin] == s[end])
           {
               begin++;
               end--;
           }
           else
                return false;
           
       }
    
    return true;
    }
};