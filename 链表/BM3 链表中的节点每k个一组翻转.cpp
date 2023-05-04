/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */
// ---------------------- 递归 -------------------------- 
class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* tail = head;
        for (int i = 0; i < k; i++) {
            if (!tail) return head;     // 不反转
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
// 时间复杂度 O(n)，空间复杂度 O(n/k)

// ---------------------- 栈 --------------------------- 
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
// 时间复杂度 O(n)，空间复杂度 O(k)

// --------------------- 模拟遍历 ------------------------
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
// 时间复杂度 O(n)，空间复杂度 O(1) 
