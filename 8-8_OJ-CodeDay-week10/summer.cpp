#define _CRT_SECURE_NO_WARNINGS 1

/*平方因子*/
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
//        //分解质因数
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
//            if (y >= 2)//若存在个数大于2的因数, 就能提取出两个合为平方因子
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

/*数字根*/
/* https://www.acwing.com/problem/content/3452/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//    //正整数数字根九个一循环
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

/*素数*/
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
//        for (int i = 11; i < n; i += 10)//要求个位为1, +10
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
