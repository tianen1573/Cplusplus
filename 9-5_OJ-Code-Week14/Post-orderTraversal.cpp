
/*1373. 二叉搜索子树的最大键值和*/
/* https://leetcode.cn/problems/maximum-sum-bst-in-binary-tree/submissions/ */

/*来源: labuladong*/
class Solution {
//全局变量，记录 BST 最大节点之和
    int maxSum = 0;
public:
    int maxSumBST(TreeNode* root) {
        traverse(root);
        return maxSum;
    }
    
    vector<int> traverse(TreeNode* root) {
        if (root == nullptr) 
            return vector<int>{1, INT_MAX, INT_MIN, 0};

        //递归计算左右子树
        vector<int> left = traverse(root->left);
        vector<int> right = traverse(root->right);

        /**
         * res[0] 记录以 root 为根的二叉树是否是 BST，若为1则说明是 BST，若为0则说明不是 BST
         * res[1] 记录以 root 为根的二叉树所有节点中的最小值
         * res[2] 记录以 root 为根的二叉树所有节点中的最大值
         * res[3] 记录以 root 为根的二叉树所有节点值之和
         */
        /************* 后序遍历位置 ****************/
        vector<int> res = vector<int>(4);
        //这个 if 在判断以 root 为根的二叉树是不是 BST
        //BST的根节点是大于左子树的最大值，小于右子树的最小值
        if (left[0] == 1 && right[0] == 1 &&
                root->val > left[2] && root->val < right[1]) {
            //以 root 为根的二叉树是 BST
            res[0] = 1;
            //计算以 root 为根的这棵 BST 的最小值
            res[1] = min(left[1], root->val);
            //计算以 root 为根的这棵 BST 的最大值
            res[2] = max(right[2], root->val);
            //计算以 root 为根的这棵 BST 所有节点之和
            res[3] = left[3] + right[3] + root->val;
            //更新全局变量
            maxSum = max(maxSum, res[3]);
        } else {
            //以 root 为根的二叉树不是 BST, 后续元素无需统计
            res[0] = 0;
        }
        /*****************************************/

        return res;
    }
};