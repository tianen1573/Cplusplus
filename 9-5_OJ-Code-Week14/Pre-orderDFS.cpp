
/*1379. 找出克隆二叉树中的相同节点*/
/* https://leetcode.cn/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/submissions/ */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {

        /*若存在值相同节点, 通过同步递归, 判断节点地址相同*/

        //结束条件
        if(original == nullptr) return nullptr;//遍历完二叉树
        if(original == target) return cloned;//找到target

        //查找左子树
        TreeNode* left = getTargetCopy(original->left, cloned->left, target);
        if(left) return left;//不为空, 找到

        return getTargetCopy(original->right, cloned->right, target);
        
    }
};