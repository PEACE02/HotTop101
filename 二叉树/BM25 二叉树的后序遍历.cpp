/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
// ------------------ 递归 ---------------------------- 
class Solution {
public:
    void postorder(vector<int>& res, TreeNode* root) {
        if (!root) return;
        // 后序遍历：左右根
        postorder(res, root->left);
        postorder(res, root->right);
        res.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
       vector<int> res;
       postorder(res, root);
       return res; 
    }
};
// 时间复杂度 O(n)，n 为二叉树节点的个数，遍历所有节点 
// 空间复杂度 O(n)，最坏情况下二叉树化为链表，递归栈深度为 n 

// ------------------ 辅助栈 -----------------------
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* pre = nullptr;
        while (root || !st.empty()) {
            while (root) {  // 找到最左节点
                st.push(root);
                root = root->left;
            }
            TreeNode* node = st.top();
            st.pop();
            // 如果该节点没有右节点，或其右节点已经访问过
            if (!node->right || node->right == pre) {
                res.push_back(node->val);
                pre = node;     // 记录为已访问
            } else {
                st.push(node);  // 再压回去
                root = node->right; // 去访问右
            }
        }
        return res;
    }
};
// 时间复杂度 O(n)，n 为二叉树节点个数，遍历所有节点 
// 空间复杂度 O(n)，辅助栈空间最大为链表所有节点数 
