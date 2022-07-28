#define _CRT_SECURE_NO_WARNINGS 1

/*最少交换次数*/
/* https://www.acwing.com/problem/content/3718/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//const int N = 1007;
//
//int q[N];
//int cnt;
//int n, arr[N];
//
//int main()
//{
//    //输入
//    cin >> n;
//    for (int i = 1; i <= n; i++) cin >> arr[i];
//
//    //逆序对数量
//    //大数据可用归并排序求逆序对
//    for (int i = n; i >= 1; i--)
//        for (int j = 1; j < i; j++)
//            if (arr[j] > arr[i]) q[arr[i]]++;
//
//    //交换次数
//    //冒泡排序每遇到相邻a[i] > a[i+1]则交换，显然每次交换的两个数原本一定是逆序对。
//    //每次交换意味着减少一个逆序对，那么总交换次数就是序列的逆序对总数。
//    bool flag = true;
//    for (int i = 0; i < n - 1; i++)
//    {
//        flag = true;
//        for (int j = 1; j + 1 <= n - i; j++)
//            if (arr[j] > arr[j + 1])
//            {
//                flag = false;
//                swap(arr[j], arr[j + 1]);
//                cnt++;
//            }
//        if (flag) break;
//    }
//
//    //输出
//    for (int i = 1; i <= n; i++) cout << q[i] << ' ';
//    cout << endl;
//    cout << cnt;
//
//    return 0;
//}

/*二叉搜索树*/
/* https://www.acwing.com/problem/content/description/3543/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//const int N = 1007;
//int v[N], l[N], r[N];//数值，左右子树存下标
//int n;
//
////建树--存下标
//void build(int root, int pos)
//{
//    if (pos >= n) return;
//    if (v[pos] > v[root])
//    {
//        if (~r[root]) build(r[root], pos);
//        else r[root] = pos, build(0, pos + 1);
//        return;
//    }
//    if (v[pos] < v[root])
//    {
//        if (~l[root]) build(l[root], pos);
//        else l[root] = pos, build(0, pos + 1);
//        return;
//    }
//    else
//    {
//        build(0, pos + 1);
//        return;
//    }
//}
////前序
//void prePrint(int root)
//{
//    if (root == -1) return;
//
//    cout << v[root] << ' ';
//    prePrint(l[root]);
//    prePrint(r[root]);
//
//    return;
//}
////中序
//void inPrint(int root)
//{
//    if (root == -1) return;
//
//    inPrint(l[root]);
//    cout << v[root] << ' ';
//    inPrint(r[root]);
//
//    return;
//}
////后序
//void lastPrint(int root)
//{
//    if (root == -1) return;
//
//    lastPrint(l[root]);
//    lastPrint(r[root]);
//    cout << v[root] << ' ';
//
//    return;
//}
//
//int main()
//{
//    //输入
//    cin >> n;
//    for (int i = 0; i < n; i++) cin >> v[i];
//    memset(l, -1, sizeof l);
//    memset(r, -1, sizeof r);
//
//    build(0, 1);
//
//    //输出
//    prePrint(0); cout << endl;
//    inPrint(0); cout << endl;
//    lastPrint(0); cout << endl;
//
//
//    return 0;
//}

/*日期*/
/* https://www.acwing.com/problem/content/3622/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//int mon[13] = { 0, 0, 0, 0, 7, 2, 5, 7, 3, 6, 1, 4, 6 };
//char* s[] = { "Sunday", "Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
//int m, d;
//
//
//int main()
//{
//    cin >> m >> d;
//    int w = (mon[m] + d % 7 - 1) % 7;
//    cout << s[w];
//    return 0;
//}

/*最大连续子序列*/
/* https://www.acwing.com/problem/content/3655/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
// /*const int N = 1e5 + 11;
//int arr[N], k;
//
//int main()
//{
//    while (~scanf("%d", &k))
//    {
//        int max_l = 0, max_r = 0, max_sum = -1;
//        int l = 0, r = 0, sum = 0;
//        bool flag = true;
//
//        //输入
//        for (int i = 0; i < k; i++) cin >> arr[i];
//
//        for (r = 0, l = 0; r < k; r++)
//        {
//            sum += arr[r];
//
//            //如果加上arr[r]，区间和小于0，可知 sum[l ~ r-1] < | arr[r] |，且arr[l] >= 0
//            //则后面的区间不能包含 l ~ r，因为其区间和为负， 对最大区间和起副作用
//            if (sum < 0)
//            {
//                l = r + 1;
//                sum = 0;
//                continue;
//            }
//            //更新
//            if (sum > max_sum)
//            {
//                max_l = l;
//                max_r = r;
//                max_sum = sum;
//            }
//        }
//
//        if(max_sum == -1) max_sum = max_l = max_r = 0;
//        printf("%d %d %d\n", max_sum, max_l, max_r);
//    }
//
//    return 0;
//}*/
//
//const int N = 1e5 + 11;
//
//int f[N], k;
//
//int main()
//{
//    while (cin >> k)
//    {
//        //初始化
//        int _max = -1, l = 1, ml = 1, mr = 1, tmp = 0;
//        f[0] = -1;
//
//
//        for (int i = 1; i <= k; i++)
//        {
//            cin >> tmp;
//            f[i] = max(f[i - 1], 0) + tmp;
//            //更新l
//            if (f[i] < 0) l = i + 1;
//            //更新_max
//            if (f[i] > _max)
//            {
//                _max = f[i];
//                ml = l;
//                mr = i;
//            }
//        }
//
//        if (_max == -1) printf("0 0 0\n");
//        else printf("%d %d %d\n", _max, ml - 1, mr - 1);
//    }
//
//    return 0;
//}

/*水仙花数*/
/* https://www.acwing.com/problem/content/description/3647/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <cmath>
//
//using namespace std;
//
////153 370 371 407
//
//int m, n;
//
//int main()
//{
//    while (scanf("%d %d", &m, &n))
//    {
//        if (m == 0) return 0;
//
//        int cnt = 0;
//        for (; m <= n; m++)
//        {
//            int a = m / 100;
//            int b = m % 100 / 10;
//            int c = m % 10;
//            if (m == pow(a, 3) + pow(b, 3) + pow(c, 3))
//            {
//                cnt++;
//                cout << m << ' ';
//            }
//        }
//
//        if (cnt == 0) cout << "no";
//
//        cout << endl;
//    }
//    return 0;
//}

/*最低票价*/
/* https://www.acwing.com/problem/content/description/4521/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <climits>
//
//using namespace std;
//
//const int N = 369;
//int n;
//int costs[3], days[N], f[N];
////f[]存以j结尾的天数需要的最少旅游费用
////则到第days[i] = j 的天时，可以通过其days[i - 1]天，更新 days[i] = j天，j + 6, j + 29的费用
//
//int getPos(int cur, int sub)
//{
//    int i = cur + 1;
//    for (i = cur + 1; i <= n; i++)
//        if (days[i] - days[cur] > sub) break;
//
//    return i - 1;//结束 或 越界
//
//}
//
//int main()
//{
//    //输入
//    scanf("%d", &n);
//    for (int i = 1; i <= n; i++) cin >> days[i];
//    for (int i = 0; i < 3; i++) cin >> costs[i];
//    memset(f, 7, sizeof(f));
//    days[0] = f[0] = 0;
//
//    for (int i = 1; i <= n; i++)
//    {
//        f[days[i]] = min(f[days[i]], f[days[i - 1]] + costs[0]);
//        f[days[getPos(i, 7 - 1)]] = min(f[days[getPos(i, 7 - 1)]], f[days[i - 1]] + costs[1]);
//        f[days[getPos(i, 30 - 1)]] = min(f[days[getPos(i, 30 - 1)]], f[days[i - 1]] + costs[2]);
//    }
//
//    cout << f[days[n]];
//
//    return 0;
//}