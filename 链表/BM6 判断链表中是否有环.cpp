/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *
 * Ҫ�󣺿ռ临�Ӷ� O(1)��ʱ�临�Ӷ� O(n)
 */
 
 // ------------ ����ָ�� ---------------- 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                break;
        }
        return fast && fast->next;
    }
};
// ʱ�临�Ӷ� O(n)���ռ临�Ӷ� O(1)

// ----------- ��ϣ�� -------------------
#include <map>
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*, bool> mp;
        while (head) {
            if (mp[head])
                return true;
            mp[head] = true;
            head = head->next;
        }
        return false;
    }
};
// ʱ�临�Ӷ� O(n)���ռ临�Ӷ� O(n)
