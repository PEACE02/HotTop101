// --------------------- 动态规划 -------------------------
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        vector<int> dp(array.size(), 0);
        int max_sum = dp[0] = array[0];
        for (int i = 1; i < array.size(); i++) {
            dp[i] = max(dp[i - 1] + array[i], array[i]);
            max_sum = max(max_sum, dp[i]);
        }
        return max_sum;
    }
}; 
// 时间复杂度 O(n)，空间复杂度 O(n) 

// ------------------- 动态规划的空间优化 -----------------
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int max_sum = array[0];
        int dp = array[0];
        for (int i = 1; i < array.size(); i++) {
            dp = max(dp + array[i], array[i]);
            max_sum = max(max_sum, dp);
        }
        return max_sum;
    }
};
// 时间复杂度 O(n)，空间复杂度 O(1) 
