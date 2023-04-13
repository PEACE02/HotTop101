/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/

// ---------stack or vector ��������----------
#include <stack>
class Solution {
  public:
    ListNode* ReverseList(ListNode* pHead) {
        if (!pHead) return nullptr;
        stack<ListNode*> st;
        ListNode* p = pHead;
        while (p) {
            st.push(p);
            p = p->next;
        }
        pHead = p = st.top();
		st.pop();
        while (!st.empty()) {
			p->next = st.top();
			st.pop();
            p = p->next;
        }
        p->next = nullptr;
        return pHead;
    }
};
//ʱ�临�Ӷ� O(n)���ռ临�Ӷ� O(n)

// -------------��ת����----------------------
#include <stack>
class Solution {
  public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* pre =nullptr;
		ListNode* cur = pHead;
		ListNode* nex = nullptr;
		while (cur) {
			nex = cur->next;
			cur->next = pre;
			pre = cur;
			cur = nex;
		}
		return pre;
	}
};
// ʱ�临�Ӷ� O(n)���ռ临�Ӷ� O(1)
 
