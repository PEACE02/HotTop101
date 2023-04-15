// ----------------------- 动态规划 ----------------------------------------------------------------
class Solution {
public:
    /**
     * 
     * @param prices int整型vector 
     * @return int整型
     */
    int maxProfit(vector<int>& prices) {
        vector<pair<int, int> > dp(prices.size(), make_pair(0, 0));
        dp[0].first = 0;            // 第一天不持股，收益为 0
        dp[0].second = -prices[0];  // 第一天持股，收益为 -prices[0]
        for (int i = 1; i < prices.size(); i++) {
            // 第 i 天不持股的收益：可能第 i - 1 天就没有持股，也可能第 i - 1 天持股，在第 i 天卖出
            dp[i].first = max(dp[i - 1].first, dp[i - 1].second + prices[i]);
            // 第 i 天持股的收益：可能第 i - 1 天就持股，也可能第 i - 1 天没有持股，第 i 天买入
            dp[i].second = max(dp[i - 1].second, -prices[i]);
        }
        return dp[prices.size() - 1].first;     // 最后一天不持股
    }
};
// 时间复杂度 O(n)，空间复杂度 O(n) 

// ----------------------- 贪心 -------------------------------- 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int min_price = prices[0], max_profit = 0;
        for (const int price : prices) {
            min_price = min(min_price, price);
            max_profit = max(max_profit, price - min_price);
        }
        return max_profit;
    }
};
// 时间复杂度 O(n)，空间复杂度 O(1) 
