#define _CRT_SECURE_NO_WARNINGS 1

/* https://www.acwing.com/activity/content/2128/ */

/*��������*/
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//int a, b, n;
//int ans;
//
//int main()
//{
//    scanf("%d, %d, %d", &a, &b, &n);
//    for (int i = 0; i <= a && i <= n; i++)
//        if (n - i <= b) ans++;
//
//    cout << ans;
//
//    return 0;
//}

/*�ַ�������*/
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//const int N = 1e5 + 11;
//string str;
//char arr[N];
//int cnt, n;
//
//
//int main()
//{
//    cin >> str;
//    int n = str.size();
//    arr[0] = 0;
//
//    //������ջ��
//    for (int i = 0, j = 0; i < n && j < n; )
//    {
//        if (i == 0 && arr[i] == 0)//arr��Ԫ��
//        {
//            arr[i] = str[j++];
//        }
//        if (arr[i] != str[j])
//        {
//            arr[++i] = str[j++];
//        }
//        else
//        {
//            if (i != 0)//��ֹһ��Ԫ��
//                i--;
//            else arr[i] = 0;//ֻ��һ��Ԫ��
//            j++;
//            cnt++;
//        }
//    }
//
//    if (cnt % 2) printf("Yes\n");
//    else printf("No");
//
//    return 0;
//}

/*����Ӽ�*/
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//const int N = 2e5 + 11, M = 1999997, INF = 0x3f3f3f3f;
//
//int q[N], h[M], n;
//
//int find(int x)
//{
//    int t = (x % M + M) % M;
//    while (h[t] != INF && h[t] != x)//ӳ���Ƿ���� / ӳ���Ƿ���Ҫ����
//        if (++t == M)
//            t = 0;
//
//    return t;
//}
//
//int main()
//{
//    scanf("%d", &n);
//
//    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
//    sort(q, q + n);
//
//    memset(h, 0x3f, sizeof h);
//
//    int res[3], rt = 0, tmp[3], tt = 0;
//
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j <= 30; j++)//��ֵΪ2��������, ������q[i]Ϊ�������ֵ
//        {
//            int d = 1 << j;
//            tmp[0] = q[i], tt = 1;
//            for (int k = 1; k <= 2; k++)//�ڶ���, ������
//            {
//                int x = q[i] - d * k;
//                if (h[find(x)] == INF) break;//������
//                tmp[tt++] = x;
//            }
//            if (tt > rt)
//            {
//                rt = tt;
//                memcpy(res, tmp, sizeof res);
//            }
//
//            if (rt == 3)//��ǰ����
//                break;
//        }
//        if (rt == 3)
//            break;
//        h[find(q[i])] = q[i];
//    }
//
//    printf("%d\n", rt);
//    for (int i = 0; i < rt; i++)
//        printf("%d ", res[i]);
//
//
//    return 0;
//}
