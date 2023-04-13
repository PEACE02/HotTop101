/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

// -------------- 数组复制双指针（相撞指针）-------------------
#include <vector>
class Solution {
public:
    /**
     * @param head ListNode类 the head
     * @return bool布尔型
     */
    bool isPail(ListNode* head) {
        vector<int> nums;
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }
        for (int i = 0, j = nums.size() - 1; i <= j; i++, j--)
            if (nums[i] != nums[j]) return false;
        return true;
    }
};
// 时间复杂度 O(n)，空间复杂度 O(n) 

// ------------- 长度法找中点 --------------------------------
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    bool isPail(ListNode* head) {
        int n = 0;
        ListNode* p = head;
        while (p) {
            n++;
            p = p->next;
        }
        n /= 2;
        p = head;
        while (n--) p = p->next;
        p = reverse(p);
        ListNode* q = head;
        while (p) {
            if (p->val != q->val) break;
            p = p->next;
            q = q->next;
        }
        return !p;
    }
};
// 时间复杂度 O(n)，空间复杂度 O(1) 

// ----------- 双指针找中点 ---------------------------------
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* pre = nullptr;
        while (head) {
            ListNode* next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
    
    bool isPail(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow = reverse(slow);
        fast = head;
        while (slow) {
            if (fast->val != slow->val) break;
            fast = fast->next;
            slow = slow->next;
        }
        return !slow;
    }
};
// 时间复杂度 O(n)，空间复杂度 O(1) 

// --------- 栈逆序（全链表逆序或后半链表逆序） -----------------
#include <stack>
class Solution {
public:
    bool isPail(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        stack<int> st;
        while (slow) {
            st.push(slow->val);
            slow = slow->next;
        }
        slow = head;
        while (!st.empty()) {
            if (slow->val != st.top()) break;
            st.pop();
            slow = slow->next;
        }
        return st.empty();
    }
};
// 时间复杂度 O(n)，空间复杂度 O(n) 
