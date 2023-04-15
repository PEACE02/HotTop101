// ----------------- 双栈法 ------------------ 
#include <stack>
class Solution {
    stack<int> s1;  //  value
    stack<int> s2;  // min value
public:
    void push(int value) {
        s1.push(value);
        if (s2.empty() || s2.top() > value)
            s2.push(value);
        else    // 重复加入栈顶
            s2.push(s2.top()); // !!!
    }
    void pop() {
        s2.pop();
        s1.pop();
    }
    int top() {
        return s1.top();
    }
    int min() {
        return s2.top();
    }
};
