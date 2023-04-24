/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
// -------------------------- 搜索路径比较 ------------------------------ 
class Solution {
public:
    vector<int> getPath(TreeNode* const root, int target) {
        vector<int> path;
        TreeNode* node = root;
        while (node->val != target) {
            path.push_back(node->val);
            if (target < node->val) node = node->left;
            else node = node->right;
        }
        path.push_back(node->val);
        return path;
    }
    int lowestCommonAncestor(TreeNode* root, int p, int q) {
        vector<int> path_p = getPath(root, p);
        vector<int> path_q = getPath(root, q);
        int res = root->val;
        for (int i = 0; i < path_p.size() && i < path_q.size(); i++) {
            if (path_p[i] == path_q[i]) res = path_p[i];
            else break;
        }
        return res;
    }
};
// 时间复杂度 O(n)，空间复杂度 O(n)

// --------------------------- 递归 一次遍历 --------------------------------------
class Solution {
public:
    int lowestCommonAncestor(TreeNode* root, int p, int q) {
        if (!root) return -1;
        if (p <= root->val && q >= root->val || p >= root->val && q <= root->val)
            return root->val;
        if (p < root->val && q < root->val)
            return lowestCommonAncestor(root->left, p, q);
        else
            return lowestCommonAncestor(root->right, p, q);
    }
};
// 时间复杂度 O(n)，空间复杂度 O(n)
