#define _CRT_SECURE_NO_WARNINGS 1

/*���ѭ��˫�˶���*/
/* https://leetcode.cn/problems/design-circular-deque/submissions/ */
//class MyCircularDeque {
//
//    /*
//    * l, r ָ��Ŀռ��������
//    * ��Size == 0 ʱ, l, r ����
//    * ��Size != 0 ʱ, ��Ҫ�ƶ�
//    * ͬ��ɾ��ʱ, ��Size == 1, l , r Ҳ����Ҫ�ƶ�
//    */
//private:
//    int l = 0, r = 0, Size = 0;//ͷ, β, ����
//    int* arr = nullptr;
//    int k = 0;
//public:
//    MyCircularDeque(int k) {
//        Size = l = r = 0;
//        this->k = k;
//        arr = new int[k];
//        memset(arr, 0, sizeof(int) * k);
//    }
//
//    bool insertFront(int value) {
//        if (isFull()) return false;
//
//
//        if (!isEmpty())//����
//            l = (l - 1 + k) % k;
//        arr[l] = value;
//
//        Size++;
//        return true;
//    }
//
//    bool insertLast(int value) {
//        if (isFull()) return false;
//
//
//        if (!isEmpty())//����
//            r = (r + 1) % k;
//        arr[r] = value;
//
//        Size++;
//        return true;
//    }
//
//    bool deleteFront() {
//        if (isEmpty()) return false;
//
//        if (Size > 1)
//            l = (l + 1) % k;
//        Size--;
//
//        return true;
//
//    }
//
//    bool deleteLast() {
//        if (isEmpty()) return false;
//
//        if (Size > 1)
//            r = (r - 1 + k) % k;
//        Size--;
//
//        return true;
//    }
//
//    int getFront() {
//        if (isEmpty()) return -1;
//
//        return arr[l];
//    }
//
//    int getRear() {
//        if (isEmpty()) return -1;
//
//        return arr[r];
//    }
//
//    bool isEmpty() {
//        if (Size == 0) return true;
//
//        return false;
//    }
//
//    bool isFull() {
//
//        //if((l - 1 + k) % k == r) return true;
//        //if((r + 1) % k == l) return true;
//        if (Size == k) return true;
//
//        return false;
//    }
//};

/*1450. �ڼȶ�ʱ������ҵ��ѧ������*/
/* https://leetcode.cn/problems/number-of-students-doing-homework-at-a-given-time/ */
//class Solution {
//public:
//    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
//        const int N = 1011;
//        int sum[N] = { 0 };
//
//        for (auto x : startTime)
//            sum[x]++;
//        for (auto x : endTime)
//            sum[x + 1]--;
//
//        for (int i = 1; i < N; i++)
//            sum[i] += sum[i - 1];
//        return sum[queryTime];
//    }
//};

/*1302. ��������Ҷ�ӽڵ�ĺ�*/
/* https://leetcode.cn/problems/deepest-leaves-sum/ */
////  /*����С, dfs+ģ�����*/
//// class Solution {
//// public:
////     static const int N = 1007;
////     int sum[N] = {0};
//
////     void dfs(TreeNode* root, int deep)
////     {
////         if(root->left == nullptr && root->left == root->right)
////         {
////             sum[deep] += root->val;
////             return ;
////         }
//
////         if(root->left) dfs(root->left, deep + 1);
////         if(root->right) dfs(root->right, deep + 1);
//
////     }
//
////     int deepestLeavesSum(TreeNode* root) {
//
////         dfs(root, 0);
//
////         for(int i = N - 1; i >= 0; i--)
////             if(sum[i])
////                 return sum[i];
//
////         return 0;
////     }
//// };
// /*BFS + �����һ��*/
//class Solution {
//public:
//
//    queue<TreeNode*> que;
//    int sum = 0;
//    bool st = false;
//
//    int deepestLeavesSum(TreeNode* root) {
//
//        if (root->left == root->right)
//            return root->val;
//
//        que.push(root); st = true;
//        while (true)
//        {
//            //����һ��, ��¼�Ƿ�ȫΪҶ�ӽڵ�
//            int sz = que.size();
//            TreeNode* cur = nullptr;
//            st = false;
//            for (int i = 0; i < sz; i++)
//            {
//                cur = que.front();
//                que.pop();
//                sum += cur->val;
//
//                if (cur->left)  que.push(cur->left), st = true;
//                if (cur->right) que.push(cur->right), st = true;
//
//            }
//            //ȫ��Ҷ�ӽڵ�, �����һ��, ����sum
//            if (st) sum = 0;
//            else return sum;
//        }
//
//    }
//};

/*���������*/
/* https://leetcode.cn/problems/design-an-ordered-stream/submissions/ */
//class OrderedStream {
//public:
//
//    int ptr;
//    vector<string> vec;
//    int n;
//
//    OrderedStream(int n) {
//        ptr = 1;
//        this->n = n;
//        vec.resize(n + 1);
//
//    }
//
//    vector<string> insert(int idKey, string value) {
//        vector<string> res;
//        vec[idKey] = value;
//
//        while (ptr <= n && !vec[ptr].empty())
//        {
//            res.push_back(vec[ptr]);
//            ptr++;
//        }
//        return res;
//    }
//};

/*��������*/
/* https://leetcode.cn/problems/maximum-binary-tree/ */
//  /*DFS*/
//// class Solution {
//// public:
//
////     vector<int> nums;
//
////     TreeNode* bulid(int l, int r)
////     {
////         if(l > r) return nullptr;
//
////         int Max = l;
////         for(int i = l; i <= r; i++)
////             if(nums[i] > nums[Max]) Max = i;
//
////         TreeNode* root = new TreeNode(nums[Max]);
////         root->left = bulid(l, Max - 1);
////         root->right = bulid(Max + 1, r);
////         return root;
////     }
//
////     TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
//
////         this->nums = nums;
//
////         return bulid(0, nums.size() - 1);
//
////     }
//// };
// /*�ѿ�����-����ջ*/
// /* https://www.acwing.com/activity/content/problem/content/7426/ */
//class Solution {
//public:
//    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
//
//        stack<TreeNode*> stk;
//
//        for (auto val : nums)
//        {
//            auto node = new TreeNode(val);
//
//            while (stk.size() && stk.top()->val < val)
//            {
//                node->left = stk.top();
//                stk.pop();
//            }
//
//            if (stk.size()) stk.top()->right = node;
//            stk.push(node);
//        }
//
//        while (stk.size() > 1) stk.pop();//ջ��Ԫ��Ϊ���ֵ
//        return stk.top();
//
//    }
//};

/*1224. ������Ƶ��*/
/* https://leetcode.cn/problems/maximum-equal-frequency/ */

#include<stdio.h>
#include<unordered_map>
using namespace std;


//���ߣ�yxc
//���ӣ�https ://www.acwing.com/activity/content/code/content/4125316/
class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int, int> cnt, hash;
        int res = 0, len = 0;
        for (auto x : nums) {
            //�����Ԫ���Ѵ���
            if (cnt.count(x)) {
                //��Ԫ�س��ִ���+1, ���� hash�� �����ִ���Ϊ cnt[x] ��Ԫ�ص� ���� ��1
                //��Ϊx�ĸ��� ��Ϊcnt[x]��
                hash[cnt[x]] --;
                //���, ��ȥ֮��, ���ִ���Ϊcnt[x]�ĸ���Ϊ0, ����ɾ��, ��Ϊ������Ҫͳ���ж����г��ִ���
                if (!hash[cnt[x]]) hash.erase(cnt[x]);
            }
            //��������������¼
            cnt[x] ++;
            hash[cnt[x]] ++;
            len++;

            //��� ���ִ��� ֻ��һ��
            if (hash.size() == 1) {
                auto it = hash.begin();
                //�����ִ���Ϊ1, �� ���ִ�����ͬ�� ���� Ϊ��ν, ��Ϊɾȥ֮��, ʣ�µĲ���
                //�� ���ִ��� ��Ϊ1, �����ֻ��һ��Ԫ��ֵ, ��ֻ����һ��Ԫ��
                if (it->first == 1 || it->second == 1) res = len;
            }
            //������ִ����� ����
            else if (hash.size() == 2) {
                vector<pair<int, int>> tmp(hash.begin(), hash.end());
                //ǿ�� ��һ�����ֵ���  ��һ�����ֵĶ�
                if (tmp[0].first > tmp[1].first) swap(tmp[0], tmp[1]);
                //���ִ����ٵ�ֻ��һ��, ����ֻ��һ��Ԫ�صĳ��ִ���Ϊ��ǰֵ
                //���ִ����ٵ�Ϊ����һ��, ��ֻ��һ��, ���ȥ��ֱ��û��, ʣ�µĲ���
                if (tmp[0].first == 1 && tmp[0].second == 1) res = len;
                //���ִ�����ıȳ��ִ����ٵĶ�һ��, ���ҳ��ִ������ֻ��һ��
                //���ִ������ֻ��һ��, �����ȥһ��Ϊ�ٵ�ֵ, ȫ����Ϊ ���ִ��������ٵ�
                if (tmp[1].first == tmp[0].first + 1 && tmp[1].second == 1) res = len;
            }
            //����, ɾ���κ�һ����������
        }

        return res;
    }
};

