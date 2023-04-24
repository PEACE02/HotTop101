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
// ------------------------ �ݹ� ---------------------------------- 
class Solution {
public:
    bool isSymmetrical(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return true;
        // else ֻ��һ���ڵ�Ϊ�� �� �ڵ�ֵ��ͬ
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
// ʱ�临�Ӷ� O(n)���������������� 
// �ռ临�Ӷ� O(n)�������£���������Ϊ�����ݹ�ջ���Ϊ n
// ���ڵ�Ϊ�����м�ڵ㣺node->left-> ... ->root-> ... root->right 

// ------------------ �ԳƲ�α��� --------------------------
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
// ʱ�临�Ӷ� O(n)���������������� 
// �ռ临�Ӷ� O(n)�������������е����ռ�Ϊ n 
