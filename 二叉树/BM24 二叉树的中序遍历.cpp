/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
// -------------------- 递归 ----------------------------- 
class Solution {
public:
    void inorder(vector<int>& res, TreeNode* root) {
        if (!root) return;
        // 中序遍历：左、根、右
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
// 时间复杂度 O(n)，n 为二叉树节点的个数，遍历所有节点 
// 空间复杂度 O(n)，最坏情况下二叉树化为链表，递归栈深度为 n 

// ----------------- 辅助栈 -----------------------------
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        while (root || !st.empty()) {
            while (root) {    // 找到最左节点
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
// 时间复杂度 O(n)，n 为二叉树节点个数，遍历所有节点 
// 空间复杂度 O(n)，辅助栈空间最大为链表所有节点数
