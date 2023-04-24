/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
// ------------------ �ݹ� ---------------------------- 
class Solution {
public:
    void postorder(vector<int>& res, TreeNode* root) {
        if (!root) return;
        // ������������Ҹ�
        postorder(res, root->left);
        postorder(res, root->right);
        res.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
       vector<int> res;
       postorder(res, root);
       return res; 
    }
};
// ʱ�临�Ӷ� O(n)��n Ϊ�������ڵ�ĸ������������нڵ� 
// �ռ临�Ӷ� O(n)�������¶�������Ϊ�����ݹ�ջ���Ϊ n 

// ------------------ ����ջ -----------------------
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* pre = nullptr;
        while (root || !st.empty()) {
            while (root) {  // �ҵ�����ڵ�
                st.push(root);
                root = root->left;
            }
            TreeNode* node = st.top();
            st.pop();
            // ����ýڵ�û���ҽڵ㣬�����ҽڵ��Ѿ����ʹ�
            if (!node->right || node->right == pre) {
                res.push_back(node->val);
                pre = node;     // ��¼Ϊ�ѷ���
            } else {
                st.push(node);  // ��ѹ��ȥ
                root = node->right; // ȥ������
            }
        }
        return res;
    }
};
// ʱ�临�Ӷ� O(n)��n Ϊ�������ڵ�������������нڵ� 
// �ռ临�Ӷ� O(n)������ջ�ռ����Ϊ�������нڵ��� 
