#define _CRT_SECURE_NO_WARNINGS 1

/* https://leetcode.cn/contest/weekly-contest-302/ */

/*611. �������γɶ�������*/
//class Solution {
//public:
//    vector<int> numberOfPairs(vector<int>& nums) {
//
//        map<int, int> m;
//
//        for (auto x : nums)
//            m[x]++;
//        int tcnt = 0, ocnt = 0;
//        for (auto p : m)
//        {
//            tcnt += p.second / 2;
//            ocnt += p.second % 2;
//        }
//
//        vector<int>res = { tcnt, ocnt };
//
//        return res;
//
//    }
//};

/*6120. ��λ��������Ե�����*/
//class Solution {
//public:
//    int maximumSum(vector<int>& nums) {
//        pair<int, int> pii[100011];
//
//        //��¼{��λ�ͣ� ��ֵ}
//        for (int i = 0; i < nums.size(); i++)
//        {
//            int v = nums[i];
//            int sum = 0;
//            while (v)
//            {
//                sum += v % 10;
//                v /= 10;
//            }
//            pii[i] = { sum, nums[i] };
//        }
//        //���򣬽���ͬ��λ�͵�Ԫ������һ��
//        sort(pii, pii + nums.size());
//
//        int _max = -1;
//        //˫ָ��:i��j ���� ��ͬ��λ������ �� ���ֵ�ʹδ�ֵ
//        for (int i = 0; i < nums.size(); i++)
//        {
//            //��ʼ��
//            int fm = pii[i].second, sm = -pii[i].second - 5;//�����������С��-1��������
//            for (int j = i + 1; j < nums.size(); j++)
//            {
//
//                //������� �ʹδ�
//                if (pii[j].first == pii[i].first)
//                {
//                    if (pii[j].second >= fm)
//                    {
//                        sm = fm;
//                        fm = pii[j].second;
//                    }
//                    else if (pii[j].second > sm) sm = pii[j].second;
//                }
//                //����_max �� i
//                else
//                {
//                    _max = max(_max, fm + sm);
//                    i = j - 1;
//                    break;
//                }
//            }
//            _max = max(_max, fm + sm);
//        }
//        return _max;
//    }
//};

/*6121. �ü����ֺ��ѯ�� K С������*/
//class Solution
//{
//public:
//    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
//        int n = nums.size(), m = queries.size();
//        typedef pair<string, int> PSI;
//        vector<PSI> strs(n);
//        vector<int>res;
//
//        for (int i = 0; i < n; i++) strs[i] = { nums[i], i };
//
//        for (auto& q : queries)
//        {
//            int k = q[0], t = q[1];
//            sort(strs.begin(), strs.end(), [&](PSI& a, PSI& b)//�Զ�������
//                {
//                    for (int i = a.first.size() - t; i < a.first.size(); i++)//���ֵ���
//                    {
//                        if (a.first[i] < b.first[i]) return true;
//                        else if (a.first[i] > b.first[i]) return false;
//                    }
//                    return a.second < b.second;//���±�
//                });
//
//            res.push_back(strs[k - 1].second);
//        }
//
//        return res;
//
//    }
//};

/*6122. ʹ������Ա�����������ɾ������*/
//class Solution {
//    //res ��numsD�������С�����ӣ���С��������������֪���������
//    //��nums����������С���������֮ǰ����һ�������ľ��Ǵ�
//public:
//
//    int gcd(int a, int b)
//    {
//        if (b > a) return gcd(b, a);
//
//        if (a % b == 0) return b;
//        else return gcd(b, a % b);
//    }
//
//    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
//
//        int _minrem = numsDivide[0];
//        for (int i = 0; i < numsDivide.size(); i++)
//            _minrem = gcd(_minrem, numsDivide[i]);
//
//        //cout << _minrem;
//
//        map<int, int> m;
//        int res = 0;
//
//        for (auto x : nums)
//            m[x]++;
//        for (auto x : m)
//            if (_minrem % x.first == 0) return res;
//            else res += x.second;
//
//        return -1;
//
//    }
//};