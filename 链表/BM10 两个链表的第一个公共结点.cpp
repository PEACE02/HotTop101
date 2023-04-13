/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
要求：空间复杂度 O(1)，时间复杂度 O(n)
*/

// -------------------- 双指针 ------------------------------------------
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode* p = pHead1;
		ListNode* q = pHead2;
		while (p != q) {
			p = p ? p->next : pHead2;
			q = q ? q->next : pHead1;
		}
		return p;
    }
};
// 时间复杂度 O(m+n)，空间复杂度 O(1) 
