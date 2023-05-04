/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */
// ------------------ 数组辅助排序 --------------------
class Solution {
public:
    /**
     * 
     * @param head ListNode类 the head node
     * @return ListNode类
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
// 时间复杂度 O(nlogn)，sort()一般为优化后的快速排序
// 空间复杂度 O(n) 

// ------------------- 归并排序 ---------------------------
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
        // 如果链表为空或只有一个元素
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
// 时间复杂度 O(nlogn)，每级划分最坏需要遍历链表全部元素，因此为 O(n)， 
// 每级合并都是将同级的子问题链表合并，因此也为 O(n)，一共有 O(logn) 层，
// 因此复杂度为 O((n + n) * logn) = O(nlogn)
// 空间复杂度为 O(logn)，递归栈的深度最坏为树形递归的深度，logn 层
