/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
// ----------------------- ��ϣ ------------------------------
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        unordered_set<ListNode*> _set;
        while (pHead) {
            if (_set.count(pHead))
                return pHead;
            _set.insert(pHead);
            pHead = pHead->next;
        }
        return nullptr;
    }
};
// ʱ�临�Ӷ� O(n)���ռ临�Ӷ� O(n) 


// ---------------------- ����ָ�� ------------------------ 
class Solution {
public:
    // ����Ƿ��л������ؿ���ָ�������Ľڵ�
    ListNode* hasCycle(ListNode* head) {
        if (!head) return nullptr;
        ListNode *fast = head, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) return fast;
        }
        return nullptr;
    }
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        ListNode* slow = hasCycle(pHead);
        if (!slow) return nullptr;
        ListNode* fast = pHead;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};
// ʱ�临�Ӷ� O(n)���ռ临�Ӷ� O(1) 
