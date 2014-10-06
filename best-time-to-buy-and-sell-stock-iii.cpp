class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size() < 2) return 0;
        int n = prices.size();
        int low = prices[0], high = prices[n-1], profit = 0;
        vector<int> dp(n, 0);
        for(int i = 1; i != n; ++i){
            low = min(low, prices[i]);
            profit = max(profit, prices[i]-low);
            dp[i] = profit;
        }
        for(int i = n-1; i >=0; --i){
            high = max(high, prices[i]);
            profit = max(profit, high-prices[i]+dp[i]);
        }
        return profit;
    }
};
