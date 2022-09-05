
/*��ѩ�����*/
/* https://www.acwing.com/problem/content/description/1355/ */

/*
* ö������������ɽ��ĸ߶�, �õ�һ���Ϸ��߶ȷ�Χ
*/


#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1007;

int arr[N];
int res = 1e6 + 11, n;

int main()
{
    cin >> n;
    
    for (int i = 0; i < n; i ++ ) cin >> arr[i];
    
    for(int i = 0; i <= 83; i++)
    {
        int sum = 0;
        for(int j = 0; j < n; j++)
            if(arr[j] < i)
                sum += (i - arr[j]) * (i - arr[j]);
            else if(arr[j] > i + 17)
                sum += (arr[j] - i - 17) * (arr[j] - i - 17);
        
        res = min(res, sum);
    }
    
    cout << res;
    
    return 0;
}