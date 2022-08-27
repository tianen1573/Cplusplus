#define _CRT_SECURE_NO_WARNINGS 1

/*�����󰴶Խ�������*/
/* https://leetcode.cn/problems/sort-the-matrix-diagonally/ */
//class Solution {
//public:
//
//    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
//        int n = mat.size(), m = mat[0].size();
//
//        for (int j = 0; j < m; j++)//������
//        {
//            vector<int> vec;
//            int r = 0, c = j;
//            while (r < n && c < m)
//                vec.push_back(mat[r++][c++]);
//            sort(vec.begin(), vec.end());
//            r = 0, c = j;
//            int sz = 0;
//            while (sz < vec.size())
//                mat[r++][c++] = vec[sz++];
//        }
//        for (int i = 0; i < n; i++)//������
//        {
//            vector<int> vec;
//            int r = i, c = 0;
//            while (r < n && c < m)
//                vec.push_back(mat[r++][c++]);
//            sort(vec.begin(), vec.end());
//            r = i, c = 0;
//            int sz = 0;
//            while (sz < vec.size())
//                mat[r++][c++] = vec[sz++];
//        }
//
//        return mat;
//    }
//};

/*�����Թ�*/
/* https://www.acwing.com/problem/content/description/3678/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//const int N = 107, M = 107;
//bool isPass = false;
//int st[N][M];
//char mp[N][M];
//int ddec[4][2] = { {0, -1}, {0, 1}, {1, 0}, {-1, 0} };
//
//int n, m, k, x1, x2, y1, y2, T;
//
//bool isLegal(int x, int y, int count)
//{
//    return (x > 0 && x <= n && y > 0 && y <= m) &&//����Ϸ�
//        mp[x][y] != '*' &&//��ǽ
//        count >= st[x][y];//����ת��������˵�
//}
//
//void dfs(int x, int y, int Dec, int count)
//{
//
//    if (!isLegal(x, y, count) || isPass)//�Ƿ�Ϸ� + ����·�����˳�
//        return;
//
//    if (x == x2 && y == y2)
//    {
//        isPass = true;
//        return;
//    }
//
//    st[x][y] = count;//��������ת��
//
//    for (int i = 0; i < 4; i++)
//        if (i != Dec) dfs(x + ddec[i][0], y + ddec[i][1], i, count - 1);
//        else dfs(x + ddec[Dec][0], y + ddec[Dec][1], Dec, count);
//
//
//}
//
//int main()
//{
//    scanf("%d", &T);
//    while (T--)
//    {
//        memset(st, 0, sizeof st);
//        isPass = false;
//
//        scanf("%d%d", &n, &m); //getchar();
//        for (int i = 1; i <= n; i++)
//        {
//            getchar();//����
//            for (int j = 1; j <= m; j++)
//                scanf("%c", &mp[i][j]);
//        }
//        getchar();
//        scanf("%d%d%d%d%d", &k, &y1, &x1, &y2, &x2);
//
//        st[x1][y1] = k;
//        for (int i = 0; i < 4; i++)
//            dfs(x1 + ddec[i][0], y1 + ddec[i][1], i, k);
//
//        if (isPass) printf("yes\n");
//        else printf("no\n");
//    }
//}
// /*�ܽ�:
// * ��Ҫ��֦, ����Ϊ��ת���������, ������bool����ʾ�õ��Ƿ���Ҫ���ν���, ��Ϊ�޷��ֱ����ν�����һ��Ϊ���ŵ�
// * �����һ�ν����ʱ��, ʣ��ת�����Ϊ0, �޷�����ת��󵽴�, ���ڶ���ȴ����
// * ����Ҫ��¼����ĳ�������ת�����
// * by:İ���໨_4
// */

/*�����ֱ��0�Ĳ�����*/
/* https://leetcode.cn/problems/number-of-steps-to-reduce-a-number-to-zero/ */
//class Solution {
//public:
//    int numberOfSteps(int num) {
//
//        int res = 0;
//
//        while (num)
//        {
//            if (num & 1) res += 2;
//            else res += 1;
//
//            num >>= 1;
//        }
//
//        if (res) res--;
//
//        return res;
//    }
//};

/*��СΪ K ��ƽ��ֵ���ڵ�����ֵ����������Ŀ*/
/* https://leetcode.cn/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/ */
//class Solution {
//public:
//    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
//
//        vector<int> sum(arr.size() + 1);
//        int res = 0, Sum = k * threshold;
//
//        for (int i = 1; i < sum.size(); i++)
//            sum[i] = sum[i - 1] + arr[i - 1];
//
//        for (int i = k; i < sum.size(); i++)
//            if (sum[i] - sum[i - k] >= Sum)
//                res++;
//
//        return res;
//    }
//};

/*ʱ��ָ��ļн�*/
/* https://leetcode.cn/problems/angle-between-hands-of-a-clock/submissions/ */
//class Solution {
//public:
//    double angleClock(int hour, int minutes) {
//
//        double md = minutes * 6;
//        double hd = (hour % 12) * 30 + ((double)minutes / 60) * 30;
//
//        double res = abs(md - hd);
//
//        return res > 180 ? 360 - res : res;
//
//    }
//};

/*��Ծ��Ϸ��*/
/* https://leetcode.cn/problems/jump-game-iv/ */
//    /*BFS + STL
//    * BFS�����·��, ʹ�����ǵ���ĳ��ʱһ������С����
//    * map: ���ٲ���ֵ��ͬ��Ԫ�ص��±�
//    * set: ��֦, ���⵱ֵ��ͬʱ, ���������ת
//    * bool: ��¼�Ƿ��Ѿ����������
//    */
//class Solution {
//public:
//
//    queue<int> pos;
//    unordered_map<int, vector<int>> mvp;
//    unordered_set<int> isTrue;
//    bool st[50011] = { false };
//
//    int minJumps(vector<int>& arr) {
//
//        if (arr.size() == 1) return 0;
//
//        int step = 0;
//        //ͳ����ֵͬ��Ԫ���±�
//        for (int i = 0; i < arr.size(); i++)
//            mvp[arr[i]].push_back(i);
//
//        int res = arr.size() - 1;
//        pos.push(0); st[0] = true;
//
//        while (true)
//        {
//            int sz = pos.size();
//            step++;
//            for (int i = 0; i < sz; i++)
//            {
//                int p = pos.front();
//                pos.pop();
//                //�±� + 1
//                if (!st[p + 1] && p + 1 < arr.size())
//                {
//                    pos.push(p + 1);
//                    st[p + 1] = true;
//                }
//                if (p + 1 == res) return step;
//
//                //�±� - 1
//                if (p - 1 >= 0 && !st[p - 1])
//                {
//                    pos.push(p - 1);
//                    st[p - 1] = true;
//                }
//
//                //ֵͬԪ��
//                if (isTrue.count(arr[p]) == 1)
//                    continue;
//                else
//                {
//                    for (auto x : mvp[arr[p]])
//                    {
//                        if (x == res) return step;
//
//                        if (x != p && !st[x]) pos.push(x);
//                        st[x] = true;
//                    }
//                    isTrue.insert(arr[p]);
//                }
//
//            }
//        }
//
//        return 0;
//    }
//};