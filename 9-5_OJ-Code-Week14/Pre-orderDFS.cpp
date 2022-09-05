
/*1379. �ҳ���¡�������е���ͬ�ڵ�*/
/* https://leetcode.cn/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/submissions/ */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {

        /*������ֵ��ͬ�ڵ�, ͨ��ͬ���ݹ�, �жϽڵ��ַ��ͬ*/

        //��������
        if(original == nullptr) return nullptr;//�����������
        if(original == target) return cloned;//�ҵ�target

        //����������
        TreeNode* left = getTargetCopy(original->left, cloned->left, target);
        if(left) return left;//��Ϊ��, �ҵ�

        return getTargetCopy(original->right, cloned->right, target);
        
    }
};