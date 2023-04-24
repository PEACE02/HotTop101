/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */
 
// ----------------------------- �ݹ� ------------------------------- 
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
// ʱ�临�Ӷ� O(n)������ n Ϊ�������Ľڵ������������ö����� 
// �ռ临�Ӷ� O(n)�������£���������Ϊ�����ݹ�ջ������Ϊ n

// -------------------------- ��α��� ----------------------------
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q; // �����Ƚ��ȳ�
        q.push(root);
        int depth = 0;
        while (!q.empty()) {
            int count = q.size();   // �ò�ڵ���
            // �����ò����нڵ�
            for (int i = 0; i < count; i++) {
                TreeNode* node = q.front();
                q.pop();
                // ����һ�����нڵ����
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            depth++;
        }
        return depth;
    }
}; 
// ʱ�临�Ӷ� O(n)������ n Ϊ�������Ľڵ�������������������
// �ռ临�Ӷ� O(n)���������е�����Ϊ n 
