#define _CRT_SECURE_NO_WARNINGS 1

/* https://www.acwing.com/activity/content/2128/ */

/*数对数量*/
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//int a, b, n;
//int ans;
//
//int main()
//{
//    scanf("%d, %d, %d", &a, &b, &n);
//    for (int i = 0; i <= a && i <= n; i++)
//        if (n - i <= b) ans++;
//
//    cout << ans;
//
//    return 0;
//}

/*字符串消除*/
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//const int N = 1e5 + 11;
//string str;
//char arr[N];
//int cnt, n;
//
//
//int main()
//{
//    cin >> str;
//    int n = str.size();
//    arr[0] = 0;
//
//    //可以用栈列
//    for (int i = 0, j = 0; i < n && j < n; )
//    {
//        if (i == 0 && arr[i] == 0)//arr无元素
//        {
//            arr[i] = str[j++];
//        }
//        if (arr[i] != str[j])
//        {
//            arr[++i] = str[j++];
//        }
//        else
//        {
//            if (i != 0)//不止一个元素
//                i--;
//            else arr[i] = 0;//只有一个元素
//            j++;
//            cnt++;
//        }
//    }
//
//    if (cnt % 2) printf("Yes\n");
//    else printf("No");
//
//    return 0;
//}

/*最大子集*/