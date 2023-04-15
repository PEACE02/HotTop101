// ------------------ ˫ջ�� ------------------- 
class Solution
{
public:
    void push(int node) {   // ʱ�临�Ӷ� O(1)
        stack1.push(node);
    }

    int pop() {             // ʱ�临�Ӷ� O(n)
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        int res = stack2.top();
        stack2.pop();
        while (!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
        return res;
    }

private:    // �ռ临�Ӷ� O(n)
    stack<int> stack1;
    stack<int> stack2;
};
