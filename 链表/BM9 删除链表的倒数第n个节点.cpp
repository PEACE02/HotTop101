/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */
// ----------------------- 双指针 ----------------------- 
class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto* res = new ListNode(-1);
        res->next = head;
        ListNode *fast = head, *slow = res;
        while (n--) fast = fast->next;
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return res->next;
    }
};
// 时间复杂度 O(n)，空间复杂度 O(1) 

// --------------------- 长度统计 --------------------------
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        auto* res = new ListNode(-1);
        res->next = head;
        ListNode* p = res->next;
        while (p) {
            length++;
            p = p->next;
        }
        p = res;
        for (int i = 0; i < length - n; i++) {
            p = p->next;
        }
        p->next = p->next->next;
        return res->next;
    }
};
// 时间复杂度 O(n)，空间复杂度 O(1) 
