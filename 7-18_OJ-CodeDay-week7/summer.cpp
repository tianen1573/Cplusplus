#define _CRT_SECURE_NO_WARNINGS 1

/*����������ĸ���*/
/* https://www.acwing.com/activity/content/problem/content/7234/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <cmath>
//#include <map>
//
//using namespace std;
//
//const int N = 15;
//int n, arr[N], res, unq;
//bool sta[N];
//
//bool IsSqrt(long long x)
//{
//    int s = (int)sqrt(x);
//    return s * s == x;
//}
//
//void dfs(int pre, int step)//pre�����е����һ��Ԫ����ֵ��last������Ԫ�صĸ���
//{
//    if (step == n)
//    {
//        res++;
//        return;
//    }
//
//    for (int i = 1; i <= n; i++)
//        if (sta[i] || (arr[i] == arr[i - 1] && !sta[i - 1]))//δ���� �� ����ǰ����ͬ��ֵ��Ԫ��������
//            continue;
//        else if (IsSqrt(pre + arr[i]))
//        {
//            sta[i] = true;
//            dfs(arr[i], step + 1);
//            sta[i] = false;
//        }
//}
//
//int main()
//{
//    cin >> n;
//    for (int i = 1; i <= n; i++) cin >> arr[i];
//    sort(arr + 1, arr + 1 + n);
//    sta[0] = true;
//
//    for (int i = 1; i <= n; i++)
//    {
//        if (arr[i] == arr[i - 1] && !sta[i - 1])//����ǰ����ͬ��ֵ��Ԫ��������
//            continue;
//        sta[i] = true;
//        dfs(arr[i], 1);
//        sta[i] = false;
//    }
//
//    cout << res;
//
//    return 0;
//}
//
////�ظ�Ԫ��������μ�֦
////����
////1�� �ж�pre�Ƿ��cur��ȣ�����ȣ���pre��Ҫ������
////2�� ˫ָ�룬ͨ����ָ���ҵ���һ����cur����ȵ�Ԫ��
// /*#include <iostream>
//#include <cstring>
//#include <cmath>
//#include <algorithm>
//
//using namespace std;
//typedef long long LL;
//
//const int N = 15;
//int a[N];
//int n;
//int res;
//bool st[N];
//
//void dfs(int index,int u,int d)
//{
//    if(d == n) res += 1;
//
//    for(int i = 1;i <= n;i ++ )
//    {
//        if(st[i]) continue;
//        int k = u + a[i];
//        LL v = int(sqrt(k));
//        if(v * v == k)
//        {
//            st[i] = true;
//            dfs(i,a[i],d + 1);
//            st[i] = false;
//            int j = i + 1;
//            while(j <= n && a[j] == a[i]) j ++ ;
//            i = j - 1;
//        }
//    }
//}
//
//int main()
//{
//    cin >> n;
//    for(int i = 1;i <= n;i ++ ) cin >> a[i];
//
//    sort(a + 1,a + 1 + n);
//
//
//    for(int i = 1;i <= n;i ++ )
//    {
//        if(i > 1 && a[i] == a[i - 1]) continue;
//        st[i] = true;
//        dfs(0,a[i],1);
//        st[i] = false;
//    }
//
//    cout << res;
//    return 0;
//}
//���ߣ�Sufferingcreatinglife*/

/*������--�������ڵ�*/
/* https://www.acwing.com/problem/content/3435/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//int x, y;
//
//int main()
//{
//    cin >> x >> y;
//    //�����ߣ��������
//    while (x != y)
//    {
//        if (x > y) x /= 2;
//        else y /= 2;
//    }
//
//    cout << x;
//    return 0;
//}

/*ΧȦ����*/
/* https://www.acwing.com/problem/content/3562/ */
//#include <iostream>
//#include <stdlib.h>
//#include <string.h>
//using namespace std;
//
//const int N = 55;
//
//typedef struct ListN
//{
//    int val;
//    struct ListN* next;
//}LN;
//
//int T, n;
//
//int main()
//{
//    cin >> T;
//
//    while (T--)
//    {
//        cin >> n;
//        LN l[N];
//
//        for (int i = 1; i <= n; i++)
//        {
//            l[i].val = i;
//            l[i].next = &(l[i + 1]);
//        }
//        l[n].next = &(l[1]);
//
//        LN* p = &(l[1]);
//        int cnt = 0;
//        while (p->next != p)//ֱ�����һ���ڵ�
//        {
//            cnt++;
//            if (cnt == 2)
//            {
//                cout << p->next->val << ' ';
//                p->next = p->next->next;
//                cnt = 0;
//            }
//            p = p->next;
//        }
//        cout << p->val << endl;
//    }
//    return 0;
//}
// /*����ģ��
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//int main()
//{
//    int n;
//    cin >> n;
//
//    while(n -- )
//    {
//        int x;
//        cin >> x;
//        int ne[x + 1];
//        for(int i = 1;i < x;i ++ ) ne[i] = i + 1;
//        ne[x] = 1;
//
//        int cnt = 0;
//        int index = 1;
//
//        while(cnt < x)
//        {
//            int i = index;
//            i = ne[i];����һλ
//            cout << ne[i] << ' ';//������λ
//            cnt ++ ;
//            ne[i] = ne[ne[i]];//����i�ĺ�һ��Ԫ��
//            index = ne[i];
//
//            if(cnt == x) break;
//        }
//        cout << endl;
//    }
//
//    return 0;
//}
//
//���ߣ�Sufferingcreatinglife*/
// /*����ģ��
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <queue>
//
//using namespace std;
//
//int n;
//queue<int> q;
//
//int main()
//{
//    int T;
//    cin >> T;
//    while (T -- )
//    {
//        cin >> n;
//        //��1 - n���������������
//        for (int i = 1; i <= n; i ++) q.push(i);
//
//        //����
//        int cnt = 1;
//        //���в���ʱ
//        while (!q.empty())
//        {
//            if (cnt == 3)  //ÿ�������ͽ����׵������¼���
//            {
//                int t = q.front(); //������˭
//                q.pop();   //��������
//                cnt = 1;  //��ռ���
//                cout << t << ' ';  //�������
//            }
//            else  //��֮���ǻ�û�е���������
//            {
//                int x = q.front(); //��ͷ��˭
//                q.pop();   //������ͷ
//                q.push(x);   //��ͷ�嵽��β
//                cnt ++;  //���� ++
//            }
//        }
//        cout << endl;  //����
//
//    }
//    return 0;
//}
//
//���ߣ�����ing*/

/*�����������*/
/* https://www.acwing.com/problem/content/3591/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
////�ͽ׳���β0��˼·һ���������� = ���� * 2^k
////ÿ��һ��2������һλ����һ��������β0��ͳ��������2�ĸ�������
//
//int n, m;
//
//int main()
//{
//    while (cin >> n >> m)
//    {
//        if (n == m && n == 0) break;
//
//        int cnt = 0;
//        //����С--NlogN
//        for (int i = n - m + 1; i <= n; i++)
//        {
//            int tmp = i;
//            while (true)
//            {
//                if (tmp % 2 == 0) cnt++;
//                else break;
//                tmp /= 2;
//            }
//        }
//        cout << cnt << endl;
//        //���ݴ�--logN
//        // int a = 0, b = 0;
//        // int ta = n, tb = n - m;
//        // while(ta)
//        // {
//        //     a += ta/=2;
//        // }
//        // while(tb)
//        // {
//        //     b += tb/=2;
//        // }
//        // cout << a - b << endl;
//    }
//
//    return 0;
//}

/*������--�ڵ����*/
/* https://www.acwing.com/problem/content/3558/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//const int N = 1011;
//
//int l[N], r[N], p[N], d[N];//���ң�������
//int T, n, m;
//
//void depth(int v, int dep)
//{
//    if (v == -1) return;//�ս��
//    d[v] = dep;
//    depth(l[v], dep + 1);
//    depth(r[v], dep + 1);
//}
//
//int getFat(int x, int y)
//{
//    if (d[y] > d[x]) return getFat(y, x);//Ĭ��x��
//    while (d[x] > d[y]) x = p[x];//�� x ��ߵ� ��y ͬһ���
//    while (x != y) x = p[x], y = p[y];//��ͬ����, �󹫹����ڵ�
//    return x;
//}
//int main()
//{
//    cin >> T;
//    while (T--)
//    {
//        cin >> n >> m;
//        for (int i = 1; i <= n; i++)
//        {
//            cin >> l[i] >> r[i];
//            if (l[i] != -1) p[l[i]] = i;
//            if (r[i] != -1) p[r[i]] = i;
//        }
//        depth(1, 1);//�������
//
//        int x = 0, y = 0;
//        for (int i = 1; i <= m; i++)
//        {
//            cin >> x >> y;
//            int fat = getFat(x, y);
//            cout << d[x] + d[y] - 2 * d[fat] << endl;
//        }
//    }
//    return 0;
//}

/*����*/
/* https://www.acwing.com/problem/content/4523/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <queue>
//#include <cmath>
//
//using namespace std;
//
//bool prime(int p)
//{
//    if (p == 1) return false;
//    if (p == 2 || p == 3) return true;
//    if (p % 6 != 1 && p % 6 != 5) return false;
//
//    for (int i = 5; i <= floor(sqrt(p)); i += 6)
//    {
//        if (p % i == 0 || p % (i + 2) == 0)
//            return 0;
//    }
//
//    return 1;
//}
//
//
//int main()
//{
//    int t, x; cin >> t;
//
//    while (t--)
//    {
//        cin >> x;
//        queue<int> que;
//        bool flag = true;//�Ƿ���ǰ�˳�
//        for (int i = 1; i <= 9 && flag; i++)//��һ������Ϊ0
//        {
//            if (prime(x * 10 + i))
//            {
//                cout << x * 10 + i << endl;
//                flag = false;
//            }
//            que.push(x * 10 + i);
//        }
//        while (!que.empty() && flag)
//        {
//            int t = que.front();
//            for (int i = 0; i <= 9 && flag; i++)
//            {
//                if (prime(t * 10 + i))
//                {
//                    cout << t * 10 + i << endl;
//                    flag = false;
//                }
//                que.push(t * 10 + i);
//            }
//            que.pop();
//        }
//    }
//
//    return 0;
//}

