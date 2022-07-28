#define _CRT_SECURE_NO_WARNINGS 1

/*���ٽ�������*/
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
//    //����
//    cin >> n;
//    for (int i = 1; i <= n; i++) cin >> arr[i];
//
//    //���������
//    //�����ݿ��ù鲢�����������
//    for (int i = n; i >= 1; i--)
//        for (int j = 1; j < i; j++)
//            if (arr[j] > arr[i]) q[arr[i]]++;
//
//    //��������
//    //ð������ÿ��������a[i] > a[i+1]�򽻻�����Ȼÿ�ν�����������ԭ��һ��������ԡ�
//    //ÿ�ν�����ζ�ż���һ������ԣ���ô�ܽ��������������е������������
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
//    //���
//    for (int i = 1; i <= n; i++) cout << q[i] << ' ';
//    cout << endl;
//    cout << cnt;
//
//    return 0;
//}

/*����������*/
/* https://www.acwing.com/problem/content/description/3543/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//const int N = 1007;
//int v[N], l[N], r[N];//��ֵ�������������±�
//int n;
//
////����--���±�
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
////ǰ��
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
////����
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
////����
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
//    //����
//    cin >> n;
//    for (int i = 0; i < n; i++) cin >> v[i];
//    memset(l, -1, sizeof l);
//    memset(r, -1, sizeof r);
//
//    build(0, 1);
//
//    //���
//    prePrint(0); cout << endl;
//    inPrint(0); cout << endl;
//    lastPrint(0); cout << endl;
//
//
//    return 0;
//}

/*����*/
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

/*�������������*/
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
//        //����
//        for (int i = 0; i < k; i++) cin >> arr[i];
//
//        for (r = 0, l = 0; r < k; r++)
//        {
//            sum += arr[r];
//
//            //�������arr[r]�������С��0����֪ sum[l ~ r-1] < | arr[r] |����arr[l] >= 0
//            //���������䲻�ܰ��� l ~ r����Ϊ�������Ϊ���� ����������������
//            if (sum < 0)
//            {
//                l = r + 1;
//                sum = 0;
//                continue;
//            }
//            //����
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
//        //��ʼ��
//        int _max = -1, l = 1, ml = 1, mr = 1, tmp = 0;
//        f[0] = -1;
//
//
//        for (int i = 1; i <= k; i++)
//        {
//            cin >> tmp;
//            f[i] = max(f[i - 1], 0) + tmp;
//            //����l
//            if (f[i] < 0) l = i + 1;
//            //����_max
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

/*ˮ�ɻ���*/
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

/*���Ʊ��*/
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
////f[]����j��β��������Ҫ���������η���
////�򵽵�days[i] = j ����ʱ������ͨ����days[i - 1]�죬���� days[i] = j�죬j + 6, j + 29�ķ���
//
//int getPos(int cur, int sub)
//{
//    int i = cur + 1;
//    for (i = cur + 1; i <= n; i++)
//        if (days[i] - days[cur] > sub) break;
//
//    return i - 1;//���� �� Խ��
//
//}
//
//int main()
//{
//    //����
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