/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// ------------------------ 辅助数组 -------------------------------
/**
 * 1. 遍历所有链表节点，并将值加入数组中，时间 O(n) 
 * 2. 对数组排序，时间 O(nlogn)
 * 3. 将数组元素重新组成链表，时间 O(n) 
 */
// 时间复杂度 O(nlogn)，空间复杂度 O(n) 

// ------------------------ 顺序归并 ----------------------------------------- 
class Solution {
public:
    ListNode* merge(ListNode* head1, ListNode* head2) {
        if (!head1) return head2;
        if (!head2) return head1;
        auto* res = new ListNode(INT_MIN);
        ListNode* p = res;
        while (head1 && head2) {
            if (head1->val <= head2->val) {
                p->next = head1;
                head1 = head1->next;
            } else {
                p->next = head2;
                head2 = head2->next;
            }
            p = p->next;
        }
        p->next = head1 ? head1 : head2;
        return res->next;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        auto* res = new ListNode(INT_MIN);
        for (ListNode* list : lists) {
            merge(res, list);
        }
        return res->next;
    }
};
// 时间复杂度 O(n^2)，空间复杂度 O(1) 

// -------------------------- 二分归并：递归 ---------------------------------------- 
class Solution {
public:
    ListNode* merge2Lists(ListNode* head1, ListNode* head2) {
        if (!head1) return head2;
        if (!head2) return head1;
        auto* res = new ListNode(-1);
        ListNode* p = res;
        while (head1 && head2) {
            if (head1->val <= head2->val) {
                p->next = head1;
                head1 = head1->next;
            } else {
                p->next = head2;
                head2 = head2->next;
            }
            p = p->next;
        }
        p->next = head1 ? head1 : head2;
        return res->next;
    }
    ListNode* divideMerge(vector<ListNode *> &lists, int left, int right) {
        if (left > right) return nullptr;
        else if (left == right) return lists[left];
        int mid = (left + right) / 2;
        return merge2Lists(divideMerge(lists, left, mid), divideMerge(lists, mid + 1, right));
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        return divideMerge(lists, 0, lists.size() - 1);
    }
};
// 时间复杂度 O(nlogk)，空间复杂度 O(logk)，k = lists.size() 

// ---------------------- 二分归并：迭代 ----------------------------------
class Solution {
public:
    ListNode* merge(ListNode* head1, ListNode* head2) {
        if (!head1) return head2;
        if (!head2) return head1;
        auto* res = new ListNode(INT_MIN);
        ListNode* p = res;
        while (head1 && head2) {
            if (head1->val <= head2->val) {
                p->next = head1;
                head1 = head1->next;
            } else {
                p->next = head2;
                head2 = head2->next;
            }
            p = p->next;
        }
        p->next = head1 ? head1 : head2;
        return res->next;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) return nullptr;
        if (lists.size() == 1) return lists[0];
        int bias = 1, k = lists.size();
        if (k % 2) {            // k > 2 且 k 为奇数，合并最后两个
            lists[k - 2] = merge(lists[k - 2], lists[k - 1]);
            k--;
        }
        while (bias < k) {      // k 为偶数且 k >= 2
            for (int i = 0; i + bias < k; i += bias * 2) {
                lists[i] = merge(lists[i], lists[i + bias]);
            }
            bias *= 2;
        }
        return lists[0];
    }
};
// 时间复杂度 O(nlogk)，空间复杂度 O(1)，k = lists.size() 

// ---------------------------- 优先队列 -------------------------------- 
class Solution {
public:
    struct cmp {
        bool operator() (ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // 小顶堆
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        // 遍历所有链表的第一个元素
        for (auto& list : lists) {
            // 不为空则加入小顶堆
            if (list) pq.push(list);
        }
        // 加一个表头
        auto* res = new ListNode(-1);
        ListNode* head = res;
        while (!pq.empty()) {
            // 取出最小的元素
            ListNode* temp = pq.top();
            pq.pop();
            // 连接
            head->next = temp;
            head = head->next;
            // 每次取出链表的后一个元素加入小顶堆
            if (temp->next) pq.push(temp->next);
        }
        return res->next;
    }
};
// 时间复杂度 O(nlogk)，每次加入优先队列排序需要 O(logk)
// 空间复杂度 O(k)，优先队列的大小最大为 k 
