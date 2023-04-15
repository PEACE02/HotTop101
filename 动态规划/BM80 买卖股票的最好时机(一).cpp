// ----------------------- ��̬�滮 ----------------------------------------------------------------
class Solution {
public:
    /**
     * 
     * @param prices int����vector 
     * @return int����
     */
    int maxProfit(vector<int>& prices) {
        vector<pair<int, int> > dp(prices.size(), make_pair(0, 0));
        dp[0].first = 0;            // ��һ�첻�ֹɣ�����Ϊ 0
        dp[0].second = -prices[0];  // ��һ��ֹɣ�����Ϊ -prices[0]
        for (int i = 1; i < prices.size(); i++) {
            // �� i �첻�ֹɵ����棺���ܵ� i - 1 ���û�гֹɣ�Ҳ���ܵ� i - 1 ��ֹɣ��ڵ� i ������
            dp[i].first = max(dp[i - 1].first, dp[i - 1].second + prices[i]);
            // �� i ��ֹɵ����棺���ܵ� i - 1 ��ͳֹɣ�Ҳ���ܵ� i - 1 ��û�гֹɣ��� i ������
            dp[i].second = max(dp[i - 1].second, -prices[i]);
        }
        return dp[prices.size() - 1].first;     // ���һ�첻�ֹ�
    }
};
// ʱ�临�Ӷ� O(n)���ռ临�Ӷ� O(n) 

// ----------------------- ̰�� -------------------------------- 
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
// ʱ�临�Ӷ� O(n)���ռ临�Ӷ� O(1) 
