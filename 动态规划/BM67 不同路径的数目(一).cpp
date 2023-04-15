// ---------------- ��̬�滮 ---------------------------------- 
#include <vector>
class Solution {
public:
    /**
     * 
     * @param m int���� 
     * @param n int���� 
     * @return int����
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
// ʱ�临�Ӷ� O(mn)���ռ临�Ӷ� O(mn) 

// ---------------- �ݹ� -----------------------------------------

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) return 1;
        return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    }
}; 
// ʱ�临�Ӷ� O(mn)���ռ临�Ӷ� O(m + n) 

// ---------------- �����ѧ --------------------------------------- 
class Solution {
public:
    int uniquePaths(int m, int n) {
        // C(m - 1, m + n - 2) = (m + n - 2)! / (m - 1)! / (n - 1)!
        int smaller = m < n ? m : n;
		int larger = n > m ? n : m;
        long res = 1;   // ���� res * () �Ľ�����
        for (int i = 1; i < smaller; i++) {
            // *= ���ȳ��ٳˣ����� int ���ҪתΪ����������
            res = res * (larger + i - 1) / i;
        }
        return res; // (int) res ��ʽת��
    }
};
// ʱ�临�Ӷ� O(min(m, n))���ռ临�Ӷ� O(1) 
