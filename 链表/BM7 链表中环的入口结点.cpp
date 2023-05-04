/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
// ----------------------- 哈希 ------------------------------
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
// 时间复杂度 O(n)，空间复杂度 O(n) 


// ---------------------- 快慢指针 ------------------------ 
class Solution {
public:
    // 检查是否有环，返回快慢指针相遇的节点
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
// 时间复杂度 O(n)，空间复杂度 O(1) 
