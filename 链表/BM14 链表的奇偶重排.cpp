/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
// ---------------------- ˫ָ�� 1 ----------------------------- 
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        auto* odd = new ListNode(-1);
        auto* even = new ListNode(-1);
        ListNode *_odd = odd, *_even = even;
        for (int i = 1; head; i++) {
            if (i % 2) {
                _odd->next = head;
                _odd = _odd->next;
            } else {
                _even->next = head; 
                _even = _even->next;
            }
            head = head->next;
        }
        _odd->next = even->next;
        _even->next = nullptr;
        return odd->next;
    }
};
// ʱ�临�Ӷ� O(n)���ռ临�Ӷ� O(1)

// ---------------------- ˫ָ�� 2 ----------------------------- 
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return nullptr;
        ListNode *odd = head, *even = head->next;
        ListNode* evenHead = even;
        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};
// ʱ�临�Ӷ� O(n)���ռ临�Ӷ� O(1)
