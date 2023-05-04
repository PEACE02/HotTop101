/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */
// ------------------ ���鸨������ --------------------
class Solution {
public:
    /**
     * 
     * @param head ListNode�� the head node
     * @return ListNode��
     */
    ListNode* sortInList(ListNode* head) {
        vector<int> list;
        ListNode* p = head;
        while (p) {
            list.push_back(p->val);
            p = p->next;
        }
        sort(list.begin(), list.end());
        p = head;
        for (int val : list) {
            p->val = val;
            p = p->next;
        }
        return head;
    }
};
// ʱ�临�Ӷ� O(nlogn)��sort()һ��Ϊ�Ż���Ŀ�������
// �ռ临�Ӷ� O(n) 

// ------------------- �鲢���� ---------------------------
class Solution {
public:
    ListNode* merge(ListNode* head1, ListNode* head2) {
        if (!head1) return head2;
        if (!head2) return head1;
        auto* res = new ListNode(-1);
        ListNode* p = res;
        while (head1 && head2) {
            if (head1->val <= head2->val) {
                p->next = head1;
                head1 = head1->next;
            } else {
                p->next = head2;
                head2 = head2->next;
            }
            p = p->next;
        }
        p->next = head1 ? head1 : head2;
        return res->next;
    }
    ListNode* sortInList(ListNode* head) {
        // �������Ϊ�ջ�ֻ��һ��Ԫ��
        if (!head || !head->next) return head;
        ListNode *left = head, *mid = head->next, *right = head->next->next;
        while (right && right->next) {
            left = left->next;
            mid = mid->next;
            right = right->next->next;
        }
        left->next = nullptr;
        return merge(sortInList(head), sortInList(mid));
    }
}; 
// ʱ�临�Ӷ� O(nlogn)��ÿ���������Ҫ��������ȫ��Ԫ�أ����Ϊ O(n)�� 
// ÿ���ϲ����ǽ�ͬ��������������ϲ������ҲΪ O(n)��һ���� O(logn) �㣬
// ��˸��Ӷ�Ϊ O((n + n) * logn) = O(nlogn)
// �ռ临�Ӷ�Ϊ O(logn)���ݹ�ջ������Ϊ���εݹ����ȣ�logn ��
