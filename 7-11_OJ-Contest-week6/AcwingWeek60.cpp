#define _CRT_SECURE_NO_WARNINGS 1

/*Week60*/
/* https://www.acwing.com/activity/content/competition/problem_list/2048/ */

/*吃饭*/
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

/*数组操作*/
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
//    //所有非0元素都减取minval，同值元素个数无意义
//    //用set去一下重
//    while (n--)
//    {
//        cin >> tmp;
//        s.insert(tmp);
//    }
//    //存在数组里便于操作
//    int arr_len = 0, cur = 0, sub = 0;
//    for (auto x : s)
//        arr[arr_len++] = x;
//    //每次减去最小值，推导可知，当该减第 x 个最小值时，  arr[x] 已经减去的值 为 arr[x - 1];
//    //即最小值等于 arr[x] - arr[x - 1]
//    //判断一下是否还有非0元素
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

/*吃水果*/
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
//int f[K][K] = { 0 };//分到第 i 个人， 剩下 j 个人不满足条件
////f[i][j]：
////1，水果种类不变 + f[i - 1][j] 
////2，水果种类变，则j减小了， + f[i - 1][j + 1] * (m - 1)//m-1中不同水果
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