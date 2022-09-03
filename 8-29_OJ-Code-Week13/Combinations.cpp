
/*������*/
/* https://www.acwing.com/problem/content/description/1353/ */

/*
* �ֱ�����λ����ÿ��λ�õ��ظ��ַ��ĸ���, ������˾����ظ�����ĸ���
* 1. hash��, ͳ�Ƹ���λ���ж��ٲ��ظ���, Ȼ���ȥ�õ��ظ���
* 2. ��Բ���ϵ�ľ����ж��Ƿ��ظ�
*/


#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    int y[3], n[3];
    
    cin >> N;
    cin >> y[0] >> y[1] >> y[2];
    cin >> n[0] >> n[1] >> n[2];
    
    if(N <= 5)
    {
        cout << N*N*N;
        return 0;
    }
    
    int res = 1;
    for(int i = 0; i < 3; i++)
    {
        int dis = abs(y[i] - n[i]);
        res *= (max(0, 5 - dis) + max(0, 5 - (N - dis)));
    }
    
    cout << 250 - res;
    
    return 0;
}