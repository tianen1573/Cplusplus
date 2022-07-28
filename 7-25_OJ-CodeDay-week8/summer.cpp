#define _CRT_SECURE_NO_WARNINGS 1

/*成绩排序*/
/* https://www.acwing.com/problem/content/3604/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//#define x first
//#define y second
//
//
//const int N = 1007;
//typedef pair<string, pair<int, int>> PSII;
//
//PSII sii[N];
//int n, age, gra;
//string name;
//
//int main()
//{
//    cin >> n;
//    for (int i = 0; i < n; i++)
//    {
//        cin >> name >> age >> gra;
//        sii[i] = { name, {age, gra} };
//    }
//
//    sort(sii, sii + n, [&](PSII& a, PSII& b)
//        {
//            if (a.y.y < b.y.y) return true;
//            else if (a.y.y == b.y.y)
//            {
//                if (a.x < b.x) return true;
//                else if (a.x == b.x)
//                {
//                    if (a.y.x <= b.y.x) return true;
//                }
//            }
//            return false;
//        });
//
//    for (int i = 0; i < n; i++)
//    {
//        cout << sii[i].x << ' ' << sii[i].y.x << ' ' << sii[i].y.y << ' ' << endl;
//    }
//
//    return 0;
//}

/*倒计数*/
/* https://www.acwing.com/problem/content/description/2076/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//const int N = 2e5 + 7;
//int T = 0, n, k;
//
//int vec[N] = { 0 };
//
//int main()
//{
//    cin >> T;
//    int t = 1;
//    while (t <= T)
//    {
//        //输入
//        cin >> n >> k;
//        int res = 0;
//        for (int i = 0; i < n; i++) //cin >> vec[i];-->cin直接超市, 1300+ms
//            scanf("%d", &vec[i]); //300+ms;
//
//        int j = 0, i = 0;
//        for (i = n - 1; i >= 0; i--)
//        {
//            if (vec[i] != 1)//为1进行判断
//                continue;
//
//            for (j = i - 1; j >= 0; j--)
//            {
//                if (vec[j] - 1 == vec[j + 1])//是否满足从右至左递增
//                    continue;
//                else
//                {
//                    if (i - j >= k) res++;//判断长度是否满足
//                    i = j + 1;
//                    break;
//                }
//            }
//
//            if (j == -1)//是否判断长度时退出, 避免死循环
//            {
//                if (i - j >= k) res++;
//                break;
//            }
//        }
//
//
//        printf("Case #%d: %d\n", t++, res);
//    }
//    return 0;
//}

/*巴士计数--差分*/
/* https://www.acwing.com/problem/content/694/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//int sub[5007];
//int T, n, p;
//
//void insert(int l, int r, int c)
//{
//    sub[l] += c;
//    sub[r + 1] -= c;
//}
//
//int main()
//{
//    cin >> T;
//    int t = 1;
//    while (t <= T)
//    {
//        memset(sub, 0, sizeof(sub));//重置内容
//        scanf("%d", &n);
//
//        //差分
//        int l = 0, r = 0;
//        for (int i = 1; i <= n; i++)
//        {
//            scanf("%d %d", &l, &r);
//            insert(l, r, 1);
//        }
//        for (int i = 1; i <= 5000; i++)
//            sub[i] += sub[i - 1];
//
//        int c = 0;
//        scanf("%d", &p);
//        printf("Case #%d:", t++);
//        while (p--)
//        {
//            cin >> c;
//            printf(" %d", sub[c]);
//        }
//        printf("\n");
//
//    }
//
//    return 0;
//}