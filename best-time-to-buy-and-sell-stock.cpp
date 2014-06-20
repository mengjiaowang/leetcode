class Solution {
    public:
        int maxProfit(vector<int> &prices) {
            return maxProfit(prices, 0);
        }

        int maxProfit(vector<int> & prices, int start){
            int max = 0;
            if(prices.size() - start < 2) return max;
            int minPrice = prices[start];
            for(int i = 1+start; i != prices.size(); ++i){
                if(prices[i] > minPrice) max = max > (prices[i] - minPrice) ? max:(prices[i] - minPrice);
                else if(prices[i] < minPrice){
                    int profit = maxProfit(prices, i);
                    max = max > profit ? max : profit; 
                    return max;
                }
            }
            return max;
        }
};
