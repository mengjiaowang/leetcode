class Solution {
    public:
        int largestRectangleArea(vector<int> &height) {
            stack<int> s;
            int tp, max_area = 0, cur_area = 0;
            int i = 0;
            while(i < height.size()){
                if(s.empty() || height[i] >= height[s.top()]){
                    s.push(i++);
                }else{
                    tp = s.top(); s.pop();
                    cur_area = height[tp] * (s.empty() ? i : i - s.top() - 1);
                    if(cur_area > max_area) max_area = cur_area;
                }
            }

            while(!s.empty()){
                tp = s.top(); s.pop();
                cur_area = height[tp] * (s.empty() ? i : i - s.top() - 1);
                if(cur_area > max_area) max_area = cur_area;
            }

            return max_area;
        }
};
