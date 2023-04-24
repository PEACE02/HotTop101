/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
// ---------------------- �ݹ� --------------------------- 
class Solution {
public:
    void preorder(vector<int>& res, TreeNode* root) {
        if (!root) return;
        // ǰ���������������
        res.push_back(root->val);
        preorder(res, root->left);
        preorder(res, root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(res, root);
        return res;
    }
};
// ʱ�临�Ӷ� O(n)��n Ϊ�������ڵ�ĸ������������нڵ� 
// �ռ临�Ӷ� O(n)�������¶�������Ϊ�����ݹ�ջ���Ϊ n 

// -------------------- ����ջ ---------------------------
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            res.push_back(node->val);
            // ǰ��������������ң�Ҫ�ȳ���������ѹ��
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
        }
        return res;
    }
};
// ʱ�临�Ӷ� O(n)��n Ϊ�������ڵ�������������нڵ� 
// �ռ临�Ӷ� O(n)�����ջ�ռ����Ϊ�������нڵ���
