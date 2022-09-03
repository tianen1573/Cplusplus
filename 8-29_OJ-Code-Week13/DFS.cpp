
/*�������е������·��*/
/* https://leetcode.cn/problems/longest-zigzag-path-in-a-binary-tree/submissions/ */


 //��������
class Solution {
public:
    int res = 0;

    void dfs(TreeNode* root, int len ,bool dir)
    {
        if(root == nullptr) return ;
        
        res = max(res, len);
        if(dir)
        {
            dfs(root->left, len + 1, 0);//����, �̳г���
            dfs(root->right, 2, 1);//������, ��ǰ�ڵ���Ϊ���ڵ㽨��
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
//��������
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

        //��Ϊ�Һ���, ��������Ϊ����·��, ����, ��֮
        if(dir) return r + 1;
        else return l + 1;

    }

    int longestZigZag(TreeNode* root) {

        //��ΪΪ�����������һ, root�ĵڶ������޹�
        dfs(root, 1);

        return res;

    }
};