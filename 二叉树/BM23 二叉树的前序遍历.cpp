/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
// ---------------------- 递归 --------------------------- 
class Solution {
public:
    void preorder(vector<int>& res, TreeNode* root) {
        if (!root) return;
        // 前序遍历：根、左、右
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
// 时间复杂度 O(n)，n 为二叉树节点的个数，遍历所有节点 
// 空间复杂度 O(n)，最坏情况下二叉树化为链表，递归栈深度为 n 

// -------------------- 辅助栈 ---------------------------
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
            // 前序遍历：根、左、右，要先出左，所以先压右
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
        }
        return res;
    }
};
// 时间复杂度 O(n)，n 为二叉树节点个数，遍历所有节点 
// 空间复杂度 O(n)，最辅助栈空间最大为链表所有节点数
