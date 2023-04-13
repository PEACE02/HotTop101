/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *
 * 要求：空间复杂度 O(1)，时间复杂度 O(n)
 */
 
 // ------------ 快慢指针 ---------------- 
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
// 时间复杂度 O(n)，空间复杂度 O(1)

// ----------- 哈希表 -------------------
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
// 时间复杂度 O(n)，空间复杂度 O(n)
