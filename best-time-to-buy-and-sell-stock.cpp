class Solution {
    public:
        int maxProfit(vector<int> &prices) {
            int res = 0;
            for(int i = 0; i != prices.size(); ++i){
                for(int j = 0; j < i; ++j){
                    int profit = prices[i] - prices[j];
                    if(profit > res) res = profit;
                }
            }
            return res;
        }
};
