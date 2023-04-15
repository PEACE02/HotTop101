// ---------------- 动态规划 ---------------------------------- 
#include <vector>
class Solution {
public:
    /**
     * 
     * @param m int整型 
     * @param n int整型 
     * @return int整型
     */
    int uniquePaths(int m, int n) {
        vector<vector<int> > dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
// 时间复杂度 O(mn)，空间复杂度 O(mn) 

// ---------------- 递归 -----------------------------------------

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) return 1;
        return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    }
}; 
// 时间复杂度 O(mn)，空间复杂度 O(m + n) 

// ---------------- 组合数学 --------------------------------------- 
class Solution {
public:
    int uniquePaths(int m, int n) {
        // C(m - 1, m + n - 2) = (m + n - 2)! / (m - 1)! / (n - 1)!
        int smaller = m < n ? m : n;
		int larger = n > m ? n : m;
        long res = 1;   // 避免 res * () 的结果溢出
        for (int i = 1; i < smaller; i++) {
            // *= 会先除再乘，两个 int 相除要转为浮点数处理
            res = res * (larger + i - 1) / i;
        }
        return res; // (int) res 隐式转换
    }
};
// 时间复杂度 O(min(m, n))，空间复杂度 O(1) 
