
/*1373. ������������������ֵ��*/
/* https://leetcode.cn/problems/maximum-sum-bst-in-binary-tree/submissions/ */

/*��Դ: labuladong*/
class Solution {
//ȫ�ֱ�������¼ BST ���ڵ�֮��
    int maxSum = 0;
public:
    int maxSumBST(TreeNode* root) {
        traverse(root);
        return maxSum;
    }
    
    vector<int> traverse(TreeNode* root) {
        if (root == nullptr) 
            return vector<int>{1, INT_MAX, INT_MIN, 0};

        //�ݹ������������
        vector<int> left = traverse(root->left);
        vector<int> right = traverse(root->right);

        /**
         * res[0] ��¼�� root Ϊ���Ķ������Ƿ��� BST����Ϊ1��˵���� BST����Ϊ0��˵������ BST
         * res[1] ��¼�� root Ϊ���Ķ��������нڵ��е���Сֵ
         * res[2] ��¼�� root Ϊ���Ķ��������нڵ��е����ֵ
         * res[3] ��¼�� root Ϊ���Ķ��������нڵ�ֵ֮��
         */
        /************* �������λ�� ****************/
        vector<int> res = vector<int>(4);
        //��� if ���ж��� root Ϊ���Ķ������ǲ��� BST
        //BST�ĸ��ڵ��Ǵ��������������ֵ��С������������Сֵ
        if (left[0] == 1 && right[0] == 1 &&
                root->val > left[2] && root->val < right[1]) {
            //�� root Ϊ���Ķ������� BST
            res[0] = 1;
            //������ root Ϊ������� BST ����Сֵ
            res[1] = min(left[1], root->val);
            //������ root Ϊ������� BST �����ֵ
            res[2] = max(right[2], root->val);
            //������ root Ϊ������� BST ���нڵ�֮��
            res[3] = left[3] + right[3] + root->val;
            //����ȫ�ֱ���
            maxSum = max(maxSum, res[3]);
        } else {
            //�� root Ϊ���Ķ��������� BST, ����Ԫ������ͳ��
            res[0] = 0;
        }
        /*****************************************/

        return res;
    }
};