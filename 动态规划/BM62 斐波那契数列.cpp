// -------------------- 递归 ------------------------- 
class Solution {
public:
    int Fibonacci(int n) {
        if (n <= 2) return 1;
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
};
// 时间复杂度 O(2^n)，每个递归会调用两个递归
// 空间复杂度 O(n)，递归栈的最大深度 

// ------------------ 动态规划 ----------------------
#include <vector>
class Solution {
public:
    int Fibonacci(int n) {
        if (n <= 2) return 1;
        vector<int> f(n, 0);
        f[0] = f[1] = 1;
        for (int i = 2; i < n; i++)
            f[i] = f[i - 1] + f[i - 2];
        return f[n - 1];
    }
};
// 时间复杂度 O(n)，空间复杂度 O(n)

// -------------------- 迭代 -------------------------- 
class Solution {
public:
    int Fibonacci(int n) {
        if (n <= 2) return 1;
        int a = 0, b = 1, c = 1;
        for (int i = 2; i < n; i++) {
            a = b; b = c; c = a + b;
        }
        return c;
    }
};
// 时间复杂度 O(n)，空间复杂度 O(1)
