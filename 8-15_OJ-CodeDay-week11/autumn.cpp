#define _CRT_SECURE_NO_WARNINGS 1

class MyCircularDeque {
public:
    vector<int> q;
    int hh = 0, tt = 0;

    MyCircularDeque(int k) {
        q.resize(k + 1);
    }

    int get(int x) {
        return (x + q.size()) % q.size();
    }

    bool insertFront(int value) {
        if (isFull()) return false;
        hh = get(hh - 1);
        q[hh] = value;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        q[tt] = value;
        tt = get(tt + 1);
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        hh = get(hh + 1);
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        tt = get(tt - 1);
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return q[hh];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return q[get(tt - 1)];
    }

    bool isEmpty() {
        return hh == tt;
    }

    bool isFull() {
        return tt == get(hh - 1);
    }
};

class Solution {
public:

    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*>q;

        q.push(root);
        int ans = 0;
        while (!q.empty())
        {
            int len = q.size();
            ans = 0;
            while (len--)
            {
                TreeNode* t = q.front();
                q.pop();
                ans += t->val;
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);


            }

        }
        return ans;
    }
};



class Solution {
public:
    int busyStudent(vector<int>& st, vector<int>& et, int q) {
        int res = 0;
        for (int i = 0; i < st.size(); i++) {
            if (st[i] <= q && et[i] >= q)res++;
        }
        return res;
    }
};