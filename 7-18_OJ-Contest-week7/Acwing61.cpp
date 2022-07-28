#define _CRT_SECURE_NO_WARNINGS 1


/* https://www.acwing.com/activity/content/2079/ */

/*分糖果*/
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//typedef unsigned long long ULL;
//
//
//ULL a, b, c;
//int main()
//{
//    int T = 0; cin >> T;
//    while (T--)
//    {
//
//        cin >> a >> b >> c;
//        cout << (a + b + c) / 2 << endl;
//    }
//
//    return 0;
//}

/*指针*/
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
////f[i][j], 在第i次拨动后, 读数为j是否存在
//bool f[16][365];
//int n, a;
//
////dfs
//
//int main()
//{
//
//    cin >> n;
//    f[0][0] = true;
//    for (int i = 1; i <= n; i++)
//    {
//        cin >> a;
//        for (int j = 0; j < 360; j++)
//        {
//            if (!f[i - 1][j]) continue;//前一个角度为假
//
//            f[i][(j + a) % 360] = f[i - 1][j];
//            f[i][(j - a + 360) % 360] = f[i - 1][j];
//        }
//
//    }
//
//
//    if (f[n][0]) cout << "YES";
//    else cout << "NO";
//
//    return 0;
//}

/*画画*/
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <cmath>
//
//using namespace std;
//typedef long long LL;
//
//
//int main()
//{
//    int x1, y1, x2, y2, R;
//    cin >> R >> x1 >> y1 >> x2 >> y2;
//    double X = 0.0, Y = 0.0, RR = 0.0;
//
//    if ((LL)(y2 - y1) * (y2 - y1) + (LL)(x2 - x1) * (x2 - x1) >= (LL)R * R)
//    {
//        X = 1.0 * x1;
//        Y = 1.0 * y1;
//        RR = 1.0 * R;
//    }
//    else
//    {
//        LL d = (LL)(y2 - y1) * (y2 - y1) + (LL)(x2 - x1) * (x2 - x1);
//        if (d == 0)
//        {
//            RR = R / 2;
//            X = x1 + RR;
//            Y = y1;
//        }
//        else
//        {
//            double dd = sqrt(d);
//            RR = (dd + R) / 2;
//            X = x2 + (x1 - x2) * 1.0 / dd * RR;
//            Y = y2 + (y1 - y2) * 1.0 / dd * RR;
//        }
//
//    }
//    printf("%f %f %f", X, Y, RR);
//
//    return 0;
//}