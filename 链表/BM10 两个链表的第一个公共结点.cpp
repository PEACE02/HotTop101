/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
Ҫ�󣺿ռ临�Ӷ� O(1)��ʱ�临�Ӷ� O(n)
*/

// -------------------- ˫ָ�� ------------------------------------------
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
// ʱ�临�Ӷ� O(m+n)���ռ临�Ӷ� O(1) 
