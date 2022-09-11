#define _CRT_SECURE_NO_WARNINGS 1

/*设计循环双端队列*/
/* https://leetcode.cn/problems/design-circular-deque/submissions/ */
//class MyCircularDeque {
//
//    /*
//    * l, r 指向的空间存在内容
//    * 当Size == 0 时, l, r 不动
//    * 当Size != 0 时, 需要移动
//    * 同理删除时, 若Size == 1, l , r 也不需要移动
//    */
//private:
//    int l = 0, r = 0, Size = 0;//头, 尾, 长度
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
//        if (!isEmpty())//不空
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
//        if (!isEmpty())//不空
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

/*1450. 在既定时间做作业的学生人数*/
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

/*1302. 层数最深叶子节点的和*/
/* https://leetcode.cn/problems/deepest-leaves-sum/ */
////  /*数据小, dfs+模拟深度*/
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
// /*BFS + 找最后一层*/
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
//            //遍历一层, 记录是否全为叶子节点
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
//            //全是叶子节点, 即最后一层, 返回sum
//            if (st) sum = 0;
//            else return sum;
//        }
//
//    }
//};

/*设计有序流*/
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

/*最大二叉树*/
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
// /*笛卡尔树-单调栈*/
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
//        while (stk.size() > 1) stk.pop();//栈底元素为最大值
//        return stk.top();
//
//    }
//};

/*1224. 最大相等频率*/
/* https://leetcode.cn/problems/maximum-equal-frequency/ */

#include<stdio.h>
#include<unordered_map>
using namespace std;


//作者：yxc
//链接：https ://www.acwing.com/activity/content/code/content/4125316/
class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int, int> cnt, hash;
        int res = 0, len = 0;
        for (auto x : nums) {
            //如果该元素已存在
            if (cnt.count(x)) {
                //该元素出现次数+1, 则在 hash中 将出现次数为 cnt[x] 的元素的 次数 减1
                //因为x的个数 不为cnt[x]了
                hash[cnt[x]] --;
                //如果, 减去之后, 出现次数为cnt[x]的个数为0, 则将其删除, 因为后面需要统计有多少中出现次数
                if (!hash[cnt[x]]) hash.erase(cnt[x]);
            }
            //不存在则正常记录
            cnt[x] ++;
            hash[cnt[x]] ++;
            len++;

            //如果 出现次数 只有一种
            if (hash.size() == 1) {
                auto it = hash.begin();
                //若出现次数为1, 则 出现次数相同的 个数 为所谓, 因为删去之后, 剩下的不变
                //若 出现次数 不为1, 则必须只有一种元素值, 则只能有一种元素
                if (it->first == 1 || it->second == 1) res = len;
            }
            //如果出现次数有 两种
            else if (hash.size() == 2) {
                vector<pair<int, int>> tmp(hash.begin(), hash.end());
                //强制 第一个出现的少  后一个出现的多
                if (tmp[0].first > tmp[1].first) swap(tmp[0], tmp[1]);
                //出现次数少的只有一次, 并且只有一种元素的出现次数为当前值
                //出现次数少的为出现一次, 且只有一种, 则减去它直接没有, 剩下的不变
                if (tmp[0].first == 1 && tmp[0].second == 1) res = len;
                //出现次数多的比出现次数少的多一次, 并且出现次数多的只有一种
                //出现次数多的只有一种, 则其减去一个为少的值, 全部都为 出现次数次数少的
                if (tmp[1].first == tmp[0].first + 1 && tmp[1].second == 1) res = len;
            }
            //三种, 删除任何一个都不满足
        }

        return res;
    }
};

