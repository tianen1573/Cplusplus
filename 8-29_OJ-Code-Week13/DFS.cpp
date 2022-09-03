
/*二叉树中的最长交错路径*/
/* https://leetcode.cn/problems/longest-zigzag-path-in-a-binary-tree/submissions/ */


 //从上往下
class Solution {
public:
    int res = 0;

    void dfs(TreeNode* root, int len ,bool dir)
    {
        if(root == nullptr) return ;
        
        res = max(res, len);
        if(dir)
        {
            dfs(root->left, len + 1, 0);//交错, 继承长度
            dfs(root->right, 2, 1);//不交错, 当前节点作为根节点建树
        }
        else
        {
            dfs(root->right, len + 1, 1);
            dfs(root->left, 2, 0);
        }
        
    }

    int longestZigZag(TreeNode* root) {

        dfs(root, 1, 1);
        dfs(root, 1, 0);

        return res - 1;

    }
};
//从下往上
class Solution {
public:
    int res = 0;

    int dfs(TreeNode* root,bool dir)
    {
        if(root == nullptr) return 0;

        int l = dfs(root->left, 1);
        int r = dfs(root->right, 0);

        int Max = l > r ? l : r;
        res = max(res, Max);

        //作为右孩子, 其左子树为交错路径, 否则, 反之
        if(dir) return r + 1;
        else return l + 1;

    }

    int longestZigZag(TreeNode* root) {

        //因为为遍历点个数减一, root的第二属性无关
        dfs(root, 1);

        return res;

    }
};