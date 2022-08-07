#define _CRT_SECURE_NO_WARNINGS 1

/* https://www.acwing.com/activity/content/2128/ */

/*数对数量*/
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

/*字符串消除*/
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
//    //可以用栈列
//    for (int i = 0, j = 0; i < n && j < n; )
//    {
//        if (i == 0 && arr[i] == 0)//arr无元素
//        {
//            arr[i] = str[j++];
//        }
//        if (arr[i] != str[j])
//        {
//            arr[++i] = str[j++];
//        }
//        else
//        {
//            if (i != 0)//不止一个元素
//                i--;
//            else arr[i] = 0;//只有一个元素
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

/*最大子集*/
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
//    while (h[t] != INF && h[t] != x)//映射是否存在 / 映射是否需要后移
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
//        for (int j = 0; j <= 30; j++)//差值为2的正数幂, 并假设q[i]为序列最大值
//        {
//            int d = 1 << j;
//            tmp[0] = q[i], tt = 1;
//            for (int k = 1; k <= 2; k++)//第二个, 第三个
//            {
//                int x = q[i] - d * k;
//                if (h[find(x)] == INF) break;//不存在
//                tmp[tt++] = x;
//            }
//            if (tt > rt)
//            {
//                rt = tt;
//                memcpy(res, tmp, sizeof res);
//            }
//
//            if (rt == 3)//提前返回
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
