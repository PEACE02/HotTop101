/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */
// -------------------- 头插法迭代 ----------------------------- 
class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param m int整型 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // 加个表头
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
// 时间复杂度 O(n)，空间复杂度 O(1)

// --------------------- 递归 -------------------------------------- 
class Solution {
public:
    ListNode* temp = nullptr;	// 记录第 n + 1 个节点 
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
// 时间复杂度 O(n)，空间复杂度 O(n)
