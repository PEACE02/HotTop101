/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// ---------------------- ��ת���� ------------------------------- 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        ListNode *pre = nullptr, *cur = head;
        while (cur) {
            ListNode* nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        return pre;
    }
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        if (!head1) return head2;
        if (!head2) return head1;
        head1 = reverseList(head1);
        head2 = reverseList(head2);
        auto* res = new ListNode(-1);
        int carry = 0;
        while (head1 || head2 || carry) {
            int val1 = head1 ? head1->val : 0;
            int val2 = head2 ? head2->val : 0;
            int temp = val1 + val2 + carry;
            ListNode* nex = res->next;
            res->next = new ListNode(temp % 10);
            res->next->next = nex;
            carry = temp / 10;
            if (head1) head1 = head1->next;
            if (head2) head2 = head2->next;
        }
        return res->next;
    }
};
// ʱ�临�Ӷ� O(max(m,n))������ m,n �ֱ�Ϊ��������ĳ��ȣ�
// ��ת����ĸ��Ӷȷֱ�Ϊ O(m),O(n)����ӵĹ���Ϊ O(max(m,n))
// �ռ临�Ӷ� O(1)��û�ж��⸨���ռ䣬���ص����������ڱ�Ҫ�ռ� 
