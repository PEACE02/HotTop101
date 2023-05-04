/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */
// ---------------------- �ݹ� -------------------------- 
class Solution {
public:
    /**
     * 
     * @param head ListNode�� 
     * @param k int���� 
     * @return ListNode��
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* tail = head;
        for (int i = 0; i < k; i++) {
            if (!tail) return head;     // ����ת
            tail = tail->next;
        }
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur != tail) {
            ListNode* nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        head->next = reverseKGroup(tail, k);
        return pre;
    }
};
// ʱ�临�Ӷ� O(n)���ռ临�Ӷ� O(n/k)

// ---------------------- ջ --------------------------- 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto* res = new ListNode(-1);
        ListNode* p = res;
        stack<ListNode*> st;
        while (true) {
            ListNode* temp = head;
            for (int i = 0; i < k; i++) {
                if (!head) break;
                st.push(head);
                head = head->next;
            }
            if (st.size() < k) {
                p->next = temp;
                break;
            }
            while (!st.empty()) {
                p->next = st.top();
                st.pop();
                p = p->next;
            }
        }
        return res->next;
    }
}; 
// ʱ�临�Ӷ� O(n)���ռ临�Ӷ� O(k)

// --------------------- ģ����� ------------------------
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto* res = new ListNode(-1);
        ListNode* p = res;
        ListNode* tail = head;
        while (true) {
            ListNode* _head = tail;
            int i = 0;
            for (; i < k; i++) {
                if (!tail) break;
                tail = tail->next;
            }
            if (i < k) {
                p->next = _head;
                break;
            }
            ListNode* pre = nullptr;
            ListNode* cur = _head;
            while (cur != tail) {
                ListNode* nex = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nex;
            }
            p->next = pre;
            p = _head;
        }
        return res->next;
    }
}; 
// ʱ�临�Ӷ� O(n)���ռ临�Ӷ� O(1) 
