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