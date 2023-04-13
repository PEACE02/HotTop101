/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/

// ---------stack or vector 构造链表----------
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
//时间复杂度 O(n)，空间复杂度 O(n)

// -------------反转链表----------------------
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
// 时间复杂度 O(n)，空间复杂度 O(1)
 
