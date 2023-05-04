/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */
// -------------------- ͷ�巨���� ----------------------------- 
class Solution {
public:
    /**
     * 
     * @param head ListNode�� 
     * @param m int���� 
     * @param n int���� 
     * @return ListNode��
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // �Ӹ���ͷ
        auto* res = new ListNode(-1);
        res->next = head;
        ListNode* pre = res;
        for (int i = 1; i < m; i++) {
            pre = pre->next;
        }
        ListNode* cur = pre->next;
        for (int i = m; i < n; i++) {
            ListNode* nex = cur->next;
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
        }
        return res->next;
    }
};
// ʱ�临�Ӷ� O(n)���ռ临�Ӷ� O(1)

// --------------------- �ݹ� -------------------------------------- 
class Solution {
public:
    ListNode* temp = nullptr;	// ��¼�� n + 1 ���ڵ� 
    ListNode* reverse(ListNode* head, int n) {
        if (n == 1) {
            temp = head->next;
            return head;
        }
        ListNode* node = reverse(head->next, n - 1);
        head->next->next = head;
        head->next = temp;
        return node;
    }

    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == 1)
            return reverse(head, n);
        ListNode* node = reverseBetween(head->next, m - 1, n - 1);
        head->next = node;
        return head;
    }
};
// ʱ�临�Ӷ� O(n)���ռ临�Ӷ� O(n)
