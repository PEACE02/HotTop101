/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 *
 * 要求：空间复杂度 O(n)，时间复杂度 O(n)
 * 进阶：空间复杂度 O(1)，时间复杂度 O(n)
 */
 
// ------------------- 栈辅助构造链表 ------------------------------------------
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pHead ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        if (!pHead || !k) return nullptr;
        stack<ListNode*> st;
        ListNode* p = pHead;
        while (p) {
            st.push(p);
            p = p->next;
        }
        if (st.size() < k) return nullptr;
        ListNode* first = st.top();
        st.pop();
        // first->next = nullptr;
        while (--k) {
            p = st.top();
            st.pop();
            p->next = first;
            first = p;
        }
        return first;
    }
};
// 时间复杂度 O(n)，空间复杂度 O(n)

// --------------- 全遍历再遍历 ---------------------
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        if (!pHead || !k) return nullptr;
        int len = 0;
        ListNode* p = pHead;
        while (p) {
            len++;
            p = p->next;
        }
        if (len < k) return nullptr;
        int t = len - k;
        p = pHead;
        while (t--)
            p = p->next;
        return p;
    }
};
// 时间复杂度 O(n)，空间复杂度 O(1)

// --------------------- 快慢指针 --------------------------
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        if (!pHead || !k) return nullptr;
        ListNode* fast = pHead;
        while (fast && --k)
            fast = fast->next;
        if (!fast) return nullptr;
        // 上面 --k 和这里是为了避免链表长度和k值相同的情况
        fast = fast->next;
        ListNode* slow = pHead;
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
// 时间复杂度 O(n)，空间复杂度 O(1)

