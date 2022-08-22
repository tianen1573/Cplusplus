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