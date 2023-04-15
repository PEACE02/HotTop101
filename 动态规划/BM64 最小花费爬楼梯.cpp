// -------------------------------- 动态规划 ------------------------------------ 
#include <vector>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param cost int整型vector 
     * @return int整型
     */
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 1, 0);
        for (int i = 2; i <= cost.size(); i++)
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        return dp[cost.size()];
    }
};
// 时间复杂度 O(n)，空间复杂度 O(n) 
