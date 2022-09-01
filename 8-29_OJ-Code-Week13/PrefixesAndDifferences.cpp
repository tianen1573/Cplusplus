
/*��ʯ�ղؼ�*/
/* https://www.acwing.com/problem/content/1826/ */

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 10011;

int sum[N] = {0};
int n, k;


/*
*ǰ׺�Ͳ��, ʱ��ռ�:O(�ߴ�);
*˫ָ��, ʱ��ռ�: O(N);
*/
int main()
{
    cin >> n >> k;
    
    int val = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> val;
        sum[val]++;
    }
    
    int res = 0;
    for(int i = 1; i <= 10000; i++)
    {
        sum[i] += sum[i - 1];
        int left = i - k - 1 > 0 ? i - k - 1 : 0;
        res = max(res, sum[i] - sum[left]);
    }
    
    cout << res;
    return 0;
}

