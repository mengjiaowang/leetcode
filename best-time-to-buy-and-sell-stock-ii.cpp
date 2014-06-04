class Solution {
    public:
        int maxProfit(vector<int> &prices) {
            if(prices.size() <= 1) return 0;
            int profit = 0, i = 0, j = 1;
            for(; j != prices.size(); i ++, j ++){
                if(prices[j] > prices[i]) profit += (prices[j] - prices[i]);
            }
            return profit;
        }
};
