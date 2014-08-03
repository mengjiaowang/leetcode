class Solution {
    public:
        int maxArea(vector<int> &height) {
            int left = 0, right = height.size() - 1;
            int max = 0;
            while(left < right){
                int area = (right - left) * min(height[left], height[right]);
                if(area > max) max = area;
                if(height[left] > height[right]){
                    right --;
                }else{
                    left ++;
                }
            }
            return max;
        }

        inline int min(int a, int b){
            return a < b ? a : b;
        }
};
