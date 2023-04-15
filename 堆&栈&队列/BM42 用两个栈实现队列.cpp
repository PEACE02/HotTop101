// ------------------ 双栈法 ------------------- 
class Solution
{
public:
    void push(int node) {   // 时间复杂度 O(1)
        stack1.push(node);
    }

    int pop() {             // 时间复杂度 O(n)
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

private:    // 空间复杂度 O(n)
    stack<int> stack1;
    stack<int> stack2;
};
