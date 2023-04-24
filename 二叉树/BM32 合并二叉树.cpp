/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */
// --------------------------- 递归 ----------------------------- 
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1) return t2;
        if (!t2) return t1;
        TreeNode* merge_node = new TreeNode(t1->val + t2->val);
        merge_node->left = mergeTrees(t1->left, t2->left);
        merge_node->right = mergeTrees(t1->right, t2->right);
        return merge_node;
    }
};
// 时间复杂度 O(min(m,n))，m、n分别为两个树的节点数，
// 当一个树访问完时自然就连接上另一个树的节点了 
// 空间复杂度 O(min(m,n))，递归深度同时间，只访问了小树的节点数

// -------------------------- 层次遍历 --------------------------------
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1) return t2;
        if (!t2) return t1;
        TreeNode* head = new TreeNode(t1->val + t2->val);
        queue<TreeNode*> q, q1, q2;
        q.push(head);
        q1.push(t1);
        q2.push(t2);
        while (!q1.empty() && !q2.empty()) {
            TreeNode* node = q.front();
            TreeNode* node1 = q1.front();
            TreeNode* node2 = q2.front();
            q.pop();
            q1.pop();
            q2.pop();
            TreeNode *left1 = node1->left, *right1 = node1->right;
            TreeNode *left2 = node2->left, *right2 = node2->right;
            if (left1 || left2) {
                if (left1 && left2) {
                    node->left = new TreeNode(left1->val + left2->val);
                    q.push(node->left);
                    q1.push(left1);
                    q2.push(left2);
                } else {
                    node->left = left1 ? left1 : left2;
                }
            }
            if (right1 || right2) {
                if (right1 && right2) {
                    node->right = new TreeNode(right1->val + right2->val);
                    q.push(node->right);
                    q1.push(right1);
                    q2.push(right2);
                } else {
                    node->right = right1 ? right1 : right2;
                }
            }
        }
        return head;
    }
}; 
// 时间复杂度 O(min(m,n))，空间复杂度 O(min(m,n))
