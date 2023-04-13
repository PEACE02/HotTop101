/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 * 进阶：空间复杂度 O(1)，时间复杂度 O(n)
 */

// 倒是不用硬想出一个空间复杂度更高的。。。。。 

// ------------- 遍历删除 -------------------------- 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        ListNode* p = head;
        while (p && p->next) {
            if (p->val != p->next->val) p = p->next;
            else {
                ListNode* temp = p->next;
                p->next = p->next->next;
                delete temp;
            }
        }
        return head;
    }
};
// 空间复杂度 O(1)，时间复杂度 O(n)
