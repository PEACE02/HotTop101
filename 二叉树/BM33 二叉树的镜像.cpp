/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
// ----------------------------- 递归 ----------------------------- 
class Solution {
public:
    TreeNode* Mirror(TreeNode* pRoot) {
        if (!pRoot) return nullptr;
        TreeNode* left = pRoot->left;
        pRoot->left = Mirror(pRoot->right);
        pRoot->right = Mirror(left);
        return pRoot;
    }
}; 
// 时间复杂度 O(n)，n为二叉树的节点数，遍历所有节点
// 空间复杂度 O(n)，最坏情况下，二叉树为链表，递归栈最大值为 n 

// ----------------------------- 栈 ------------------------------
class Solution {
  public:
    TreeNode* Mirror(TreeNode* pRoot) {
        if (!pRoot) return nullptr;
        stack<TreeNode*> st;
        st.push(pRoot);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            // 入栈左右节点
            if (node->left) st.push(node->left);
            if (node->right) st.push(node->right);
            // 交换左右节点
            TreeNode* left = node->left;
            node->left = node->right;
            node->right = left;
            // 也可以先交换再入栈
        }
        return pRoot;
    }
};
// 时间复杂度 O(n)，空间复杂度 O(n)
