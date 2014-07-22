class Solution {
    public:
        int largestRectangleArea(vector<int> &height) {
            int area = 0;
            for(int i = 0; i != height.size(); ++i){
                int start = i, end = i;
                while(start - 1 >= 0 && height[start-1] >= height[i]) start --;
                while(end + 1 < height.size() && height[end+1] >= height[i]) end ++;
                int s = (end - start + 1) * height[i];
                if(s > area) area = s;
            }
            return area;
        }
};
