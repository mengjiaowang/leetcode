class Solution {
    public:
        int maxProfit(vector<int> &prices) {
            int max = 0;
            for(int i = 0; i != prices.size(); ++i){
                int profit = maxProfit(prices, 0, i) + maxProfit(prices, i + 1, prices.size()-1);
                if(profit > max) max = profit;
            }
            return max;
        }

        int maxProfit(vector<int> &prices, int start, int end){
            if(end - start < 1) return 0;
            int max = 0;
            for(int i = start + 1; i <= end; ++i){
                if(prices[i] > prices[start]){
                    max = max > prices[i] - prices[start] ? max : prices[i] - prices[start];
                }
                else{
                    int profit = maxProfit(prices, i, end);
                    if(profit > max) max = profit;
                }
            }
            return max;
        }
};
