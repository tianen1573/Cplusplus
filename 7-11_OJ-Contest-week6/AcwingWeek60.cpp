#define _CRT_SECURE_NO_WARNINGS 1

/*Week60*/
/* https://www.acwing.com/activity/content/competition/problem_list/2048/ */

/*�Է�*/
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//int x, y, z;
//
//int main()
//{
//    cin >> x >> y >> z;
//
//    if (y >= x && z >= x) cout << "Yes";
//    else cout << "No";
//
//    return 0;
//}

/*�������*/
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <set>
//using namespace std;
//
//const int N = 1e5 + 11;
//
//int arr[N] = { 0 };
//
//int n, k;
//set<int> s;
//
//int main()
//{
//    cin >> n >> k;
//    int tmp;
//
//    //���з�0Ԫ�ض���ȡminval��ֵͬԪ�ظ���������
//    //��setȥһ����
//    while (n--)
//    {
//        cin >> tmp;
//        s.insert(tmp);
//    }
//    //������������ڲ���
//    int arr_len = 0, cur = 0, sub = 0;
//    for (auto x : s)
//        arr[arr_len++] = x;
//    //ÿ�μ�ȥ��Сֵ���Ƶ���֪�����ü��� x ����Сֵʱ��  arr[x] �Ѿ���ȥ��ֵ Ϊ arr[x - 1];
//    //����Сֵ���� arr[x] - arr[x - 1]
//    //�ж�һ���Ƿ��з�0Ԫ��
//    while (k--)
//    {
//        if (cur == arr_len) cout << '0' << endl;
//        else
//        {
//            cout << arr[cur] - sub << endl;
//            sub = arr[cur++];
//        }
//    }
//    return 0;
//}

/*��ˮ��*/
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//const int K = 2009;
//typedef long long LL;
//
//int n, m, k;
//
//int f[K][K] = { 0 };//�ֵ��� i ���ˣ� ʣ�� j ���˲���������
////f[i][j]��
////1��ˮ�����಻�� + f[i - 1][j] 
////2��ˮ������䣬��j��С�ˣ� + f[i - 1][j + 1] * (m - 1)//m-1�в�ͬˮ��
//
//int main()
//{
//    cin >> n >> m >> k;
//    f[1][k] = m;
//
//    for (int i = 2; i <= n; i++)
//    {
//        for (int j = 0; j < k; j++)
//        {
//            LL r0 = f[i - 1][j] % 998244353;
//            LL r1 = (((LL)f[i - 1][j + 1] % 998244353) * ((m - 1) % 998244353)) % 998244353;
//            f[i][j] = (r0 + r1) % 998244353;
//        }
//        f[i][k] = m;
//    }
//    cout << f[n][0];
//    return 0;
//}