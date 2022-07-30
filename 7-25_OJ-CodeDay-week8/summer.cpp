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

/*范围区分*/
/* https://www.acwing.com/problem/content/description/4464/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <set>
//
//using namespace std;
//
//int T, N, X, Y, t;
//void priAndCnt(int N, int sum)
//{
//    int tmp = 0, cnt = 0, un = 0;;
//    for (cnt = 1; cnt <= N; cnt++)
//    {
//        tmp += cnt;
//        if (tmp >= sum)
//        {
//            un = tmp - sum;
//            break;
//        }
//    }
//    printf("%d\n", cnt - !!un);
//    for (int i = 1; i <= cnt; i++)
//        if (i != un) cout << i << ' ';
//    cout << endl;
//}
//
//int main()
//{
//    scanf("%d", &T);
//    while (t < T)
//    {
//        scanf("%d %d %d", &N, &X, &Y);
//
//        int sum = (N * (N + 1) >> 1);
//        if (sum % (X + Y))
//        {
//            printf("Case #%d: IMPOSSIBLE\n", ++t);
//            continue;
//        }
//        printf("Case #%d: POSSIBLE\n", ++t);
//        priAndCnt(N, X * (sum / (X + Y)));
//
//    }
//
//    return 0;
//}
////把1~N分成X+Y份, 若sum(1~N) % (X+Y) != 0, 则其一定无法平分
////之后遍历1~N, 当遍历到cnt时, tmpSum >= sum, 此时 tmpSum - sum < cnt, 在[1, cnt-1]
////又, 小于cnt的数我们都有,则只需减去这个sub即可
////若tmpSum == sum, 个数即为cnt, 否则减1
////数据N过大时, 可以用二分+(n*(1+n)/2), 求第一次大于sum的cnt值

/*坠落的蚂蚁*/
/* https://www.acwing.com/problem/content/description/3477/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//#define x first
//#define y second
//
//
//vector<int> l, r;
//vector<pair<int, int> > pd;
//int A, N;
//
//int main()
//{
//    cin >> N;
//    int a = 0, b = 0;
//    while (N--)
//    {
//        cin >> a >> b;
//        if (b == 0) A = a;
//        else pd.push_back({ a, b });
//    }
//
//    sort(pd.begin(), pd.end());//先排序, l,r就不需要排序了
//    for (auto v : pd)
//    {
//        //交换速度,看作交换位置(多走一步)
//        if (v.x < A && v.y == 1) l.push_back(v.x);//左边往左走的, 对A的速度不起作用
//        else if (v.x > A && v.y == -1) r.push_back(v.x);//右边往右走的,同理
//    }
//
//    if (l.size() == r.size()) cout << "Cannot fall!\n";//速度对冲之后为0, 静止
//    //离得近的对冲后, A静止,则对冲后最近的蚂蚁走到端点的时间, 就是A一共经过的时间
//    else if (l.size() > r.size()) cout << 100 - l[l.size() - r.size() - 1] << endl;
//    else if (r.size() > l.size()) cout << r[l.size()] << endl;
//
//    return 0;
//}
////思路--作者：trudbot / https://www.acwing.com/solution/content/128478/

/*破记录者*/
/* https://www.acwing.com/problem/content/description/3310/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//const int N = 2e5 + 10;
//
//int arr[N];
//int n, T, t = 1;
//
//int main()
//{
//    scanf("%d", &T);
//    while (t <= T)
//    {
//        int cnt = 0, Max = 0;
//        cin >> n;
//
//        for (int i = 1; i <= n; i++)
//            scanf("%d", &arr[i]);
//        arr[n + 1] = 0;
//        for (int i = 1; i <= n; i++)
//        {
//            if (arr[i] > Max)
//            {
//                Max = arr[i];
//                if (arr[i] > arr[i + 1])
//                    cnt++;
//            }
//        }
//        printf("Case #%d: %d\n", t++, cnt);
//    }
//
//    return 0;
//}