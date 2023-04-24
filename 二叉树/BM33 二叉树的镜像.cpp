/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
// ----------------------------- �ݹ� ----------------------------- 
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
// ʱ�临�Ӷ� O(n)��nΪ�������Ľڵ������������нڵ�
// �ռ临�Ӷ� O(n)�������£�������Ϊ�����ݹ�ջ���ֵΪ n 

// ----------------------------- ջ ------------------------------
class Solution {
  public:
    TreeNode* Mirror(TreeNode* pRoot) {
        if (!pRoot) return nullptr;
        stack<TreeNode*> st;
        st.push(pRoot);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            // ��ջ���ҽڵ�
            if (node->left) st.push(node->left);
            if (node->right) st.push(node->right);
            // �������ҽڵ�
            TreeNode* left = node->left;
            node->left = node->right;
            node->right = left;
            // Ҳ�����Ƚ�������ջ
        }
        return pRoot;
    }
};
// ʱ�临�Ӷ� O(n)���ռ临�Ӷ� O(n)
