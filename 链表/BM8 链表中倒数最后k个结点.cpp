/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 *
 * Ҫ�󣺿ռ临�Ӷ� O(n)��ʱ�临�Ӷ� O(n)
 * ���ף��ռ临�Ӷ� O(1)��ʱ�临�Ӷ� O(n)
 */
 
// ------------------- ջ������������ ------------------------------------------
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     * 
     * @param pHead ListNode�� 
     * @param k int���� 
     * @return ListNode��
     */
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        if (!pHead || !k) return nullptr;
        stack<ListNode*> st;
        ListNode* p = pHead;
        while (p) {
            st.push(p);
            p = p->next;
        }
        if (st.size() < k) return nullptr;
        ListNode* first = st.top();
        st.pop();
        // first->next = nullptr;
        while (--k) {
            p = st.top();
            st.pop();
            p->next = first;
            first = p;
        }
        return first;
    }
};
// ʱ�临�Ӷ� O(n)���ռ临�Ӷ� O(n)

// --------------- ȫ�����ٱ��� ---------------------
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        if (!pHead || !k) return nullptr;
        int len = 0;
        ListNode* p = pHead;
        while (p) {
            len++;
            p = p->next;
        }
        if (len < k) return nullptr;
        int t = len - k;
        p = pHead;
        while (t--)
            p = p->next;
        return p;
    }
};
// ʱ�临�Ӷ� O(n)���ռ临�Ӷ� O(1)

// --------------------- ����ָ�� --------------------------
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        if (!pHead || !k) return nullptr;
        ListNode* fast = pHead;
        while (fast && --k)
            fast = fast->next;
        if (!fast) return nullptr;
        // ���� --k ��������Ϊ�˱��������Ⱥ�kֵ��ͬ�����
        fast = fast->next;
        ListNode* slow = pHead;
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
// ʱ�临�Ӷ� O(n)���ռ临�Ӷ� O(1)

