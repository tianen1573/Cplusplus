#define _CRT_SECURE_NO_WARNINGS 1

/* https://www.acwing.com/activity/content/2105/ */

/*����Ԫ��*/
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <map>
//using namespace std;
//
//// map<int, int> mvp;
//
//// int main()
//// {
////     int n = 0, v = 0, p = 0; cin >> n;
////     for(int i = 0; i < n; i++)
////     {
////         scanf("%d", &v);
////         mvp[v] = i;
////     }
//
////     if(mvp.size() < 3)
////     {
////         cout <<"-1 -1 -1";
////         return 0;
////     }
//
////     int a, b, c;
////     auto it = mvp.begin();
////     a = it->second; it++;
////     b = it->second; it++;
////     c = it->second; it++;
//
////     cout << a + 1 << ' '<< b + 1 << ' ' << c + 1;
//
////     return 0;
//
//// }
//
//int a, b, c, v, n;
//int pa, pb, pc;
//
//int main()
//{
//    cin >> n;
//    for (int i = 0; i < n; i++)
//    {
//        cin >> v;
//        if (a != 0) continue;
//
//        if (v > c)
//        {
//            a = b; pa = pb;
//            b = c; pb = pc;
//            c = v; pc = i + 1;
//        }
//        else if (v != c && v > b)
//        {
//            a = b; pa = pb;
//            b = v; pb = i + 1;
//        }
//        else if (v != c && v != b && v > a)
//        {
//            a = v; pa = i + 1;
//        }
//    }
//    if (a == 0) cout << "-1 -1 -1";
//    else cout << pa << ' ' << pb << ' ' << pc;
//
//    return 0;
//}

/*�ռ�����*/
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <map>
//
//using namespace std;
//
//unordered_map<int, int> mpc;
//int n, m;
//string res;
//
//int main()
//{
//    cin >> n >> m;
//    int v = 0;
//    for (int i = 0; i < m; i++)
//    {
//        cin >> v;
//        mpc[v]++;
//
//        if (mpc.size() == n)
//        {
//            res += '1';
//            for (int i = 1; i <= n; i++)
//            {
//                if (mpc[i] == 1) mpc.erase(i);
//                else mpc[i]--;
//            }
//        }
//        else
//        {
//            res += '0';
//        }
//    }
//
//    cout << res;
//
//    return 0;
//}

/*���ϲ���*/
/*ģ��--75 -- ��Ŀ��Ϣû��ȫ*/
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <map>
//
//using namespace std;
//typedef long long LL;
//
//LL maxVal, curVal, cntVal;
//LL maxn, Sum, Cnt = 1, Max;
//map<int, int> mvc;
//
//void aver()
//{
//    maxn = Max * (Cnt - 1);
//
//    for (auto it = mvc.begin(); it != mvc.end(); it++)
//    {
//        if (it->second > 0)
//        {
//            if (((maxn + Max) - (Sum + it->first)) / (Cnt + 1)
//            > (maxn - Sum) / Cnt)
//            {
//                Sum += it->first;
//                Cnt++;
//                maxn += Max;
//                it->second--;
//            }
//            else
//            {
//                break;
//            }
//        }
//        if (it->second == 0)
//        {
//            mvc.erase(it->first);
//        }
//    }
//    double Aver = (double)(maxn - Sum) / Cnt;
//
//    cout << Aver << endl;
//
//}
//
//int main()
//{
//    int q = 0; cin >> q;
//    int m = 0, v = 0;;
//
//    for (int i = 1; i < q; i++)
//    {
//        cin >> m;
//        if (m == 1)
//        {
//            cin >> v;
//            if (v > Max) Max = v;
//            mvc[v]++;
//        }
//        else
//        {
//            aver();
//        }
//    }
//
//    return 0;
//}

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 5e5 + 10;

int n, m;
int w[N];

int main()
{
    scanf("%d", &m);
    double sum = 0, res = 0;
    int inp, k = 0;
    while (m--)
    {
        scanf("%d", &inp);
        if (inp == 1)
        {
            scanf("%d", &w[++n]);
            while (k + 1 <= n && w[k + 1] <= (sum + w[n]) / (k + 1))
                sum += w[++k];
            res = w[n] - (sum + w[n]) / (k + 1);
        }
        else
        {
            printf("%lf\n", res);
        }
    }

    return 0;
}
//1. �����ֵһ��ʱ, ����С��ƽ��ֵ��Ԫ��, ����Ӹ�Ԫ��, ƽ��ֵ��С, �������; ����ƽ��ֵ���, �������.
//2. ������Ϊ����������, ����k+1��Ԫ�ؿ����, ���k��Ҳһ������, ����sum��������
//3. ��ǰ׺��sum����ʱ, ���ֵԽ��, resԽ��, �����ֵһ�����������Ԫ��ֵ
// ��Դ yxc