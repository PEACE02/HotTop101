/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 * ���ף��ռ临�Ӷ� O(1)��ʱ�临�Ӷ� O(n)
 */

// ���ǲ���Ӳ���һ���ռ临�Ӷȸ��ߵġ��������� 

// ------------- ����ɾ�� -------------------------- 
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
// �ռ临�Ӷ� O(1)��ʱ�临�Ӷ� O(n)
