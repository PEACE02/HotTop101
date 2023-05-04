/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */
// ----------------------- 直接比较删除 ------------------------ 
class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        auto* res = new ListNode(-1);
        res->next = head;
        ListNode* cur = res;
        while (cur->next && cur->next->next) {
            if (cur->next->val == cur->next->next->val) {
                int temp = cur->next->val;
                while (cur->next && cur->next->val == temp)
                    cur->next = cur->next->next;
            } else
                cur = cur->next;
        }
        return res->next;
    }
};
// 时间复杂度 O(n)，空间复杂度 O(1)

// -------------------- 哈希表 ------------------------------
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        unordered_map<int, int> mp;     // val, count
        ListNode* p = head;
        while (p) {
            mp[p->val]++;
            p = p->next;
        }
        auto* res = new ListNode(-1);
        res->next = head;
        p = res;
        while (p->next) {
            if (mp[p->next->val] != 1)
                p->next = p->next->next;
            else
                p = p->next;
        }
        return res->next;
    }
};
// 时间复杂度 O(n)，空间复杂度 O(n)
