/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/

//-------------------- 迭代 ------------------------- 
class Solution {
  public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        if (!pHead1) return pHead2;
        if (!pHead2) return pHead1;
		// 一般创建单链表，都会设一个虚拟头结点，也叫哨兵，
		// 因为这样每一个结点都有一个前驱结点。
        auto* head = new ListNode(-1);
		ListNode* cur = head;
        while (pHead1 && pHead2) {
            if (pHead1->val <= pHead2->val) {
                cur->next = pHead1;
                pHead1 = pHead1->next;
            } else {
                cur->next = pHead2;
                pHead2 = pHead2->next;
            }
			cur = cur->next;
        }
		cur->next = pHead1 ? pHead1 : pHead2;
		return head->next;
    }
};
// 时间复杂度 O(m+n)，空间复杂度 O(1)

//-------------------- 递归 ------------------------- 
class Solution {
  public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        if (!pHead1) return pHead2;
        if (!pHead2) return pHead1;
		if (pHead1->val <= pHead2->val) {
			pHead1->next = Merge(pHead1->next, pHead2);
			return pHead1;
		} else {
			pHead2->next = Merge(pHead1, pHead2->next);
			return pHead2;
		}
    }
};
// 时间复杂度 O(m+n)，空间复杂度 O(m+n) 
