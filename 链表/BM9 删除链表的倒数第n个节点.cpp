/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */
// ----------------------- ˫ָ�� ----------------------- 
class Solution {
public:
    /**
     * 
     * @param head ListNode�� 
     * @param n int���� 
     * @return ListNode��
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
// ʱ�临�Ӷ� O(n)���ռ临�Ӷ� O(1) 

// --------------------- ����ͳ�� --------------------------
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
// ʱ�临�Ӷ� O(n)���ռ临�Ӷ� O(1) 
