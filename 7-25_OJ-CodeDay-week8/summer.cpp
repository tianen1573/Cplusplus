#define _CRT_SECURE_NO_WARNINGS 1

/*�ɼ�����*/
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

/*������*/
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
//        //����
//        cin >> n >> k;
//        int res = 0;
//        for (int i = 0; i < n; i++) //cin >> vec[i];-->cinֱ�ӳ���, 1300+ms
//            scanf("%d", &vec[i]); //300+ms;
//
//        int j = 0, i = 0;
//        for (i = n - 1; i >= 0; i--)
//        {
//            if (vec[i] != 1)//Ϊ1�����ж�
//                continue;
//
//            for (j = i - 1; j >= 0; j--)
//            {
//                if (vec[j] - 1 == vec[j + 1])//�Ƿ���������������
//                    continue;
//                else
//                {
//                    if (i - j >= k) res++;//�жϳ����Ƿ�����
//                    i = j + 1;
//                    break;
//                }
//            }
//
//            if (j == -1)//�Ƿ��жϳ���ʱ�˳�, ������ѭ��
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

/*��ʿ����--���*/
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
//        memset(sub, 0, sizeof(sub));//��������
//        scanf("%d", &n);
//
//        //���
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

/*��Χ����*/
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
////��1~N�ֳ�X+Y��, ��sum(1~N) % (X+Y) != 0, ����һ���޷�ƽ��
////֮�����1~N, ��������cntʱ, tmpSum >= sum, ��ʱ tmpSum - sum < cnt, ��[1, cnt-1]
////��, С��cnt�������Ƕ���,��ֻ���ȥ���sub����
////��tmpSum == sum, ������Ϊcnt, �����1
////����N����ʱ, �����ö���+(n*(1+n)/2), ���һ�δ���sum��cntֵ