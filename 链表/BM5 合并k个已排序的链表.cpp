/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// ------------------------ �������� -------------------------------
/**
 * 1. ������������ڵ㣬����ֵ���������У�ʱ�� O(n) 
 * 2. ����������ʱ�� O(nlogn)
 * 3. ������Ԫ�������������ʱ�� O(n) 
 */
// ʱ�临�Ӷ� O(nlogn)���ռ临�Ӷ� O(n) 

// ------------------------ ˳��鲢 ----------------------------------------- 
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
// ʱ�临�Ӷ� O(n^2)���ռ临�Ӷ� O(1) 

// -------------------------- ���ֹ鲢���ݹ� ---------------------------------------- 
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
// ʱ�临�Ӷ� O(nlogk)���ռ临�Ӷ� O(logk)��k = lists.size() 

// ---------------------- ���ֹ鲢������ ----------------------------------
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
        if (k % 2) {            // k > 2 �� k Ϊ�������ϲ��������
            lists[k - 2] = merge(lists[k - 2], lists[k - 1]);
            k--;
        }
        while (bias < k) {      // k Ϊż���� k >= 2
            for (int i = 0; i + bias < k; i += bias * 2) {
                lists[i] = merge(lists[i], lists[i + bias]);
            }
            bias *= 2;
        }
        return lists[0];
    }
};
// ʱ�临�Ӷ� O(nlogk)���ռ临�Ӷ� O(1)��k = lists.size() 

// ---------------------------- ���ȶ��� -------------------------------- 
class Solution {
public:
    struct cmp {
        bool operator() (ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // С����
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        // ������������ĵ�һ��Ԫ��
        for (auto& list : lists) {
            // ��Ϊ�������С����
            if (list) pq.push(list);
        }
        // ��һ����ͷ
        auto* res = new ListNode(-1);
        ListNode* head = res;
        while (!pq.empty()) {
            // ȡ����С��Ԫ��
            ListNode* temp = pq.top();
            pq.pop();
            // ����
            head->next = temp;
            head = head->next;
            // ÿ��ȡ������ĺ�һ��Ԫ�ؼ���С����
            if (temp->next) pq.push(temp->next);
        }
        return res->next;
    }
};
// ʱ�临�Ӷ� O(nlogk)��ÿ�μ������ȶ���������Ҫ O(logk)
// �ռ临�Ӷ� O(k)�����ȶ��еĴ�С���Ϊ k 
