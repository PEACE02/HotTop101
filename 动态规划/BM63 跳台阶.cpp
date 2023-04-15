// ��쳲���������һ�� 

// ---------------------- �ݹ� ---------------------------------
class Solution {
public:
    int jumpFloor(int number) {
        if (number <= 2) return number;
        return jumpFloor(number - 1) + jumpFloor(number - 2);
    }
};
// ʱ�临�Ӷ� O(2^n)���ռ临�Ӷ� O(n) 

// ---------------------- ��̬�滮 ---------------------------- 
#include <vector>
class Solution {
public:
    int jumpFloor(int number) {
        vector<int> dp(number, 0);
        dp[0] = 1; dp[1] = 2;
        for (int i = 2; i < number; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[number - 1];
    }
};
// ʱ�临�Ӷ� O(n)���ռ临�Ӷ� O(n) 

// ------------------ ���� / ���仯���� -----------------------
class Solution {
public:
    int jumpFloor(int number) {
        if (number <= 2) return number;
        int a = 1, b = 2, c = a + b;
        for (int i = 3; i < number; i++) {
            a = b, b = c, c = a + b;
        }
        return c;
    }
};
// ʱ�临�Ӷ� O(n)���ռ临�Ӷ� O(1) 
