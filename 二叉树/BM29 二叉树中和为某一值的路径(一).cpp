/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */
// -------------------------- 递归 --------------------------
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        if (!root->left && !root->right && root->val == sum)
            return true;
        int _sum = sum - root->val;
        return hasPathSum(root->left, _sum) || 
		       hasPathSum(root->right, _sum);
    }
};
// 时间复杂度 O(n)，遍历整个二叉树 
// 空间复杂度 O(n)，最坏情况，二叉树为链表，递归栈深度为 n

// --------------------- 辅助栈深度优先遍历 ---------------------------------------
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        // 辅助栈深度优先遍历，记录到相应节点的路径和
        stack<pair<TreeNode*, int> > st;
        st.push({root, root->val});
        while (!st.empty()) {
            pair<TreeNode*, int> temp = st.top();
            st.pop();
            if (!temp.first->left && !temp.first->right && temp.second == sum)
                return true;
            if (temp.first->left)
                st.push({temp.first->left, temp.second + temp.first->left->val});
            if (temp.first->right)
                st.push({temp.first->right, temp.second + temp.first->right->val});
        }
        return false;
    }
}; 
// 时间复杂度 O(n)，遍历整个二叉树
// 空间复杂度 O(n) 或 O(tree_height)，最坏情况下二叉树为链表，辅助栈空间大小为 n 
