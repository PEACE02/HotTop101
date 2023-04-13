/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/

//-------------------- ���� ------------------------- 
class Solution {
  public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        if (!pHead1) return pHead2;
        if (!pHead2) return pHead1;
		// һ�㴴��������������һ������ͷ��㣬Ҳ���ڱ���
		// ��Ϊ����ÿһ����㶼��һ��ǰ����㡣
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
// ʱ�临�Ӷ� O(m+n)���ռ临�Ӷ� O(1)

//-------------------- �ݹ� ------------------------- 
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
// ʱ�临�Ӷ� O(m+n)���ռ临�Ӷ� O(m+n) 
