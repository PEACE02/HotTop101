// ------------------------- 自顶向下 ----------------------------- 
class Solution {
public:
    unordered_map<TreeNode*, int> hash;
    int depth(TreeNode* root) {
        if (!root) return 0;
        if (hash.find(root) != hash.end()) return hash[root];
        return max(depth(root->left), depth(root->right)) + 1;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if (!pRoot) return true;
        return abs(depth(pRoot->left) - depth(pRoot->right)) <= 1
        && IsBalanced_Solution(pRoot->left) 
        && IsBalanced_Solution(pRoot->right);
    }
};
// 时间复杂度 O(n)，空间复杂度 O(n) 

// ----------------------- 自底向上 ------------------------------- 
class Solution {
public:
    int depth(TreeNode* root) {
        if (!root) return 0;
        int left_depth = depth(root->left);
        if (left_depth == -1) return -1;
        int right_depth = depth(root->right);
        if (right_depth == -1) return -1;
        if (abs(left_depth - right_depth) > 1) return -1;
        return max(left_depth, right_depth) + 1;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        return depth(pRoot) != -1;
    }
};
// 时间复杂度 O(n)，空间复杂度 O(n)
