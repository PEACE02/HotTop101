/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
// -------------------- �ݹ� ----------------------------- 
class Solution {
public:
    void inorder(vector<int>& res, TreeNode* root) {
        if (!root) return;
        // ����������󡢸�����
        inorder(res, root->left);
        res.push_back(root->val);
        inorder(res, root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(res, root);
        return res;
    }
};
// ʱ�临�Ӷ� O(n)��n Ϊ�������ڵ�ĸ������������нڵ� 
// �ռ临�Ӷ� O(n)�������¶�������Ϊ�����ݹ�ջ���Ϊ n 

// ----------------- ����ջ -----------------------------
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        while (root || !st.empty()) {
            while (root) {    // �ҵ�����ڵ�
                st.push(root);
                root = root->left;
            }
            TreeNode* node = st.top();
            st.pop();
            res.push_back(node->val);
            root = node->right;
        }
        return res;
    }
};
// ʱ�临�Ӷ� O(n)��n Ϊ�������ڵ�������������нڵ� 
// �ռ临�Ӷ� O(n)������ջ�ռ����Ϊ�������нڵ���
