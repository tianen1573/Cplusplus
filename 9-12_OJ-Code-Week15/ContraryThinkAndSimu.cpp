
/*��̱�*/
/* https://www.acwing.com/problem/content/description/1914/ */

/*
* ����Ϊ10^16, ֱ�ӱ���ģ��ᳬʱ
* ���������ֵĹ���, ��˼άģ��������, �ж��Ƿ��ڴ�����
* by yxc
*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;


int main()
{
    int res = 0;
    LL x, y;
    cin >> x >> y;
    
    //λ��
    for(int i = 3; i <= 17; i++)
        for(int k = 0; k < 10; k++)//��ͬ������Ϊk
            for(int j = 0; j < 10; j++)//��ͬ���Ǹ�Ϊj
                if(k != j)//��������
                {
                    //��һ��λ�÷��ò�ͬ������
                    for(int u = 0; u < i; u++)
                    {
                        string str(i, '0' + k);
                        str[u] = '0' + j;
                        //ȥ��ǰ��0
                        if(str[0] != '0')
                        {
                            LL val = stoll(str);
                            if(val >= x && val <= y) res++;
                        }
                    }
                    
                }
    cout << res;
    return 0;
}