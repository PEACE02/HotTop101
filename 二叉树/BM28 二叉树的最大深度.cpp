/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */
 
// ----------------------------- 递归 ------------------------------- 
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
// 时间复杂度 O(n)，其中 n 为二叉树的节点数，遍历整棵二叉树 
// 空间复杂度 O(n)，最坏情况下，二叉树化为链表，递归栈深度最大为 n

// -------------------------- 层次遍历 ----------------------------
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q; // 队列先进先出
        q.push(root);
        int depth = 0;
        while (!q.empty()) {
            int count = q.size();   // 该层节点数
            // 遍历该层所有节点
            for (int i = 0; i < count; i++) {
                TreeNode* node = q.front();
                q.pop();
                // 将下一层所有节点入队
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            depth++;
        }
        return depth;
    }
}; 
// 时间复杂度 O(n)，其中 n 为二叉树的节点数，遍历整个二叉树
// 空间复杂度 O(n)，辅助队列的最坏情况为 n 
