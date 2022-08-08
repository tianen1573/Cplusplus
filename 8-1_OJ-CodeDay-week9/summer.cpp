#define _CRT_SECURE_NO_WARNINGS 1

/*今天是第几天*/
/* https://www.acwing.com/problem/content/description/3394/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//    int year = 0;
//    int month = 0;
//    int day = 0;
//    int sum_day = 0;
//    int days[] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
//    while (~scanf("%d%d%d", &year, &month, &day))
//    {
//        sum_day = month == 1 ? day : days[month - 2] + day;
//        if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && month > 2)
//        {
//            sum_day += 1;
//        }
//        printf("%d\n", sum_day);
//    }
//    return 0;
//}

/*统计单词*/
/* https://www.acwing.com/activity/content/problem/content/7324/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//int cnt, i = 0, j = 0;
//
//int main()
//{
//    string str;
//    getline(cin, str);
//    while (i < str.size())
//    {
//        while (i < str.size() && str[i] == ' ') i++;//找单词开头
//        j = i + 1;
//        while (j < str.size() && str[j] != ' ' && str[j] != '.') j++;//找单词结尾后一个
//
//        if (str[i] == '.') cout << endl;
//        else cout << j - i << ' ';
//
//        i = j;
//    }
//    return 0;
//}

/*进制转换*/
/* https://www.acwing.com/problem/content/description/3455/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//int sum = 0;
//string num;
//
//int main()
//{
//    while (cin >> num)
//    {
//
//        int pos = 2, val = 0, flag = 1;
//        if (num[0] == '-')
//        {
//            flag = -1;
//            pos = 3;
//        }
//        sum = 0;
//        for (; pos < num.size(); pos++)
//        {
//            if (num[pos] >= 'a') val = num[pos] - 'a' + 10;
//            else val = num[pos] - '0';
//            sum = sum * 16 + val;
//        }
//        cout << sum * flag << endl;
//    }
//    return 0;
//}

/*a+b*/
/* https://www.acwing.com/problem/content/3599/ */
//#include<string>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//string strA, strB;
//
//void sum()
//{
//    int carry = 0;
//    int i = 0;
//
//    for (; i < strA.size() && i < strB.size(); i++)
//    {
//        int a = strA[i] - '0', b = strB[i] - '0';
//        strA[i] = (a + b + carry) % 10 + '0';
//        carry = (a + b + carry) / 10;
//    }
//
//    while (i < strA.size())
//    {
//        int a = strA[i] - '0';
//        strA[i] = (a + carry) % 10 + '0';
//        carry = (a + carry) / 10;
//        i++;
//    }
//    while (i < strB.size())
//    {
//        int b = strB[i] - '0';
//        strA.push_back('0' + (b + carry) % 10);
//        carry = (b + carry) / 10;
//        i++;
//    }
//    if (carry == 1) strA.push_back('1');
//
//    return;
//}
//
//int main()
//{
//    while (cin >> strA >> strB)
//    {
//        reverse(strA.begin(), strA.end());
//        reverse(strB.begin(), strB.end());
//        sum();
//        reverse(strA.begin(), strA.end());
//        cout << strA << endl;
//    }
//
//    return 0;
//}

/*切木棍*/
/* https://www.acwing.com/problem/content/description/3670/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//int n, cnt;
//
//int main()
//{
//    while (~scanf("%d", &n))
//    {
//        if (n % 2 == 1)
//            cnt = 0;
//        else
//        {
//            cnt = n / 2 - 1;
//            if (n % 4 == 0)
//                cnt--;
//            cnt /= 2;
//        }
//
//        printf("%d\n", cnt);
//    }
//
//
//    return 0;
//}
////1. n必须为偶数
////2. 其中一对直角边长度和为 n / 2, 则分配给两个边有[1, n/2), 即 n / 2 - 1 中分法
////3. 不能为正方形, 一个数对为一种, 和顺序无关.

/*根能抵达的点*/
/* https://www.acwing.com/problem/content/description/3715/ */
////--二分
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <queue>
//
//using namespace std;
//
//const int N = 20007;
//
//int T, n, y;
//
//bool check(int X, vector<vector< pair<int, int> >>& arr)
//{
//    //初始化
//    int res = 1;
//    bool sta[N] = { 0 };
//    queue<int> que;
//    que.push(0), res = 1, sta[0] = true;
//
//    //BFS
//    while (que.size())
//    {
//        int top = que.front();
//        que.pop();
//        for (int i = 0; i < arr[top].size(); i++)
//            if (sta[arr[top][i].first] || arr[top][i].second < X) continue;//遍历过 或 权值小
//            else
//            {
//                sta[arr[top][i].first] = true;
//                que.push(arr[top][i].first);
//                res++;
//            }
//        if (res > y) return false;
//    }
//
//    return true;
//}
//
//int main()
//{
//    scanf("%d", &T);
//    while (T--)
//    {
//        scanf("%d%d", &n, &y);
//
//        int Max = 0;
//        vector<vector< pair<int, int> >> arr(n);
//
//        //存图
//        int u = 0, v = 0, w = 0;
//        for (int i = 0; i < n - 1; i++)
//        {
//            scanf("%d %d %d", &u, &v, &w);
//            Max = max(Max, w);
//            arr[u].push_back({ v, w });
//            arr[v].push_back({ u, w });
//        }
//
//        //二分找Min
//        int l = 0, r = Max + 1;
//        while (l < r)
//        {
//            int mid = l + r >> 1;
//
//            if (check(mid, arr)) r = mid;
//            else l = mid + 1;
//        }
//        cout << l << endl;
//    }
//
//    return 0;
//}
//
//
//// //其他-- 作者: trudbot 
//// #include <bits/stdc++.h>
//// using namespace std;
//// vector<vector<pair<int, int>>> g;//邻接表存图, pair{顶点编号, 权值}, 用着方便一点
//// int n, y;
//// vector<int> minCost;
//
//// //遍历图以获取每个结点的路径最小权
//// //dp思想 : 结点v的minCost 等于 min (v的父结点的minCost, v的父结点到v这条边的权值)
//// //v为当前结点编号, last为上一个结点(用于避免重复遍历, 可以用visit数组替代), m为v的路径最小权值
//// int dfs(int v, int last, int m)
//// {
////     minCost[v] = m;
////     for(auto &i : g[v])
////     {
////         if(i.first == last) continue;
////         dfs(i.first, v, min(m, i.second));//i.first结点的最小权值为min(m, weight(v --> i.first) )
////     }
//// }
//
//// int main() {
////     int T; cin >> T;
////     while( T-- )
////     {
////         cin >> n >> y;
////         g.resize(n);
////         minCost.resize(n);
//
////         for(int i=1; i<n; i++)
////         {
////             int a, b, c;
////             cin >> a >> b >> c;
////             g[a].push_back({b, c});
////             g[b].push_back({a, c});//题中没有明确这条边是a->b还是b->a, 所以为了保险视为无向边
////         }
////         dfs(0, -1, 1e9);//由于根结点没有父结点, 所以最小权手动给一个极大值
////         sort(minCost.begin(), minCost.end());
//
////         if(n == y) cout << 0 << endl;//当n==y时不需要删除任何结点
////         else cout << minCost[n-y-1] + 1 << endl;//+1的原因是X要严格大于权值才能删
//
////         g.clear();
////     }
//
////     return 0;
//// }
