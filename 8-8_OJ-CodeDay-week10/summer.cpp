#define _CRT_SECURE_NO_WARNINGS 1

/*ƽ������*/
/* https://www.acwing.com/problem/content/3592/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <map>
//
//using namespace std;
//
//int T, val;
//
//int main()
//{
//
//    while (~scanf("%d", &val))
//    {
//        //�ֽ�������
//        map<int, int> myc;
//        for (int i = 2; i * i <= val; i++)
//        {
//            while (val % i == 0)
//            {
//                myc[i]++;
//                val /= i;
//            }
//        }
//        myc[val]++;
//
//        bool flag = false;
//        for (auto [x, y] : myc)
//            if (y >= 2)//�����ڸ�������2������, ������ȡ��������Ϊƽ������
//            {
//                flag = true;
//                break;
//            }
//
//        if (flag) printf("Yes\n");
//        else printf("No\n");
//    }
//    return 0;
//}

/*���ָ�*/
/* https://www.acwing.com/problem/content/3452/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//    //���������ָ��Ÿ�һѭ��
//    int arr[] = { 9, 1, 2, 3, 4, 5, 6, 7, 8 };
//    string str;
//
//    while (cin >> str)
//    {
//        if (str == "0") break;
//        int res = 0;
//        for (int i = 0; i < str.size(); i++)
//            res += str[i] - '0';
//        res %= 9;
//        cout << arr[res] << endl;
//    }
//
//    return 0;
//}

/*����*/
/* https://www.acwing.com/problem/content/description/3529/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <cmath>
//
//using namespace std;
//
//int n;
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
//            return false;
//    }
//
//    return true;
//}
//int main()
//{
//    while (~scanf("%d", &n))
//    {
//        bool flag = true;
//        for (int i = 11; i < n; i += 10)//Ҫ���λΪ1, +10
//            if (prime(i))
//            {
//                flag = false;
//                printf("%d ", i);
//            }
//        if (flag) printf("-1\n");
//        else printf("\n");
//    }
//
//    return 0;
//}

/*���г�֮��*/
/*https://www.acwing.com/problem/content/2072/*/
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//int T, n, t;
//int arr[107];
//
//int main()
//{
//    scanf("%d", &T);
//    t = 1;
//
//    while (t <= T)
//    {
//        int res = 0;
//        scanf("%d", &n);
//        for (int i = 0; i < n; i++)
//            scanf("%d", &arr[i]);
//        for (int i = 1; i < n - 1; i++)
//            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
//                res++;
//
//        printf("Case #%d: %d\n", t++, res);
//    }
//    return 0;
//}

