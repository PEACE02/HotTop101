/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */
// -------------------------- �ݹ� --------------------------
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
// ʱ�临�Ӷ� O(n)���������������� 
// �ռ临�Ӷ� O(n)��������������Ϊ�����ݹ�ջ���Ϊ n

// --------------------- ����ջ������ȱ��� ---------------------------------------
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        // ����ջ������ȱ�������¼����Ӧ�ڵ��·����
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
// ʱ�临�Ӷ� O(n)����������������
// �ռ临�Ӷ� O(n) �� O(tree_height)�������¶�����Ϊ��������ջ�ռ��СΪ n 
