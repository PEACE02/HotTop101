// -------------------- �ݹ� ------------------------- 
class Solution {
public:
    int Fibonacci(int n) {
        if (n <= 2) return 1;
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
};
// ʱ�临�Ӷ� O(2^n)��ÿ���ݹ����������ݹ�
// �ռ临�Ӷ� O(n)���ݹ�ջ�������� 

// ------------------ ��̬�滮 ----------------------
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
// ʱ�临�Ӷ� O(n)���ռ临�Ӷ� O(n)

// -------------------- ���� -------------------------- 
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
// ʱ�临�Ӷ� O(n)���ռ临�Ӷ� O(1)
