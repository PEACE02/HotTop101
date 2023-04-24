/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
// ------------------------ 递归 ---------------------------------- 
class Solution {
public:
    bool isSymmetrical(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return true;
        // else 只有一个节点为空 或 节点值不同
        if (!root1 || !root2 || root1->val != root2->val)
            return false;
        return isSymmetrical(root1->left, root2->right) &&
               isSymmetrical(root1->right, root2->left);
    }
    bool isSymmetrical(TreeNode* pRoot) {
        if (!pRoot) return true;
        return isSymmetrical(pRoot->left, pRoot->right);
    }
};
// 时间复杂度 O(n)，遍历整个二叉树 
// 空间复杂度 O(n)，最坏情况下，二叉树化为链表，递归栈深度为 n
// 根节点为链表中间节点：node->left-> ... ->root-> ... root->right 

// ------------------ 对称层次遍历 --------------------------
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot) {
        if (!pRoot) return true;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(pRoot->left);
        q2.push(pRoot->right);
        while (!q1.empty() && !q2.empty()) {
            TreeNode* left = q1.front();
            TreeNode* right = q2.front();
            q1.pop();
            q2.pop();
            if (!left && !right) continue;
            if (!left || !right || left->val != right->val)
                return false;
            q1.push(left->left);
            q1.push(left->right);
            q2.push(right->right);
            q2.push(right->left);
        }
        return true;
    }
};
// 时间复杂度 O(n)，遍历整个二叉树 
// 空间复杂度 O(n)，两个辅助队列的最大空间为 n 
