class Solution {
    public:
        int maxArea(vector<int> &height) {
            int max = 0;
            for(int i = 0; i != height.size(); ++i){
                for(int j = i + 1; j < height.size(); ++j){
                    int s = (j-i)*std::abs(height[j]-height[i]);
                    if(s > max) max = s;
                }
            }
            return max;
        }
};
