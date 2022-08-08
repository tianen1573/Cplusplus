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