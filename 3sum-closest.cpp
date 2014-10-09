class Solution {
    public:
        int threeSumClosest(vector<int> &num, int target) {
            sort(num.begin(), num.end());
            int mindiff = std::numeric_limits<int>::max();
            int result = 0;
            for(int i = 0; i != num.size(); ++i){
                if(i != 0 && num[i] == num[i-1]) continue;
                int start = i + 1, end = num.size() - 1;
                while(start < end){
                    if(start != i + 1 && num[start] == num[start-1]){
                        ++start;
                        continue;
                    }
                    int sum = num[start] + num[end] + num[i];
                    int diff = std::abs(sum - target);
                    if(diff == 0){
                        return sum;
                    }
                    else if(diff < mindiff){
                        mindiff = diff; result = sum;
                    }

                    if(sum - target > 0) --end;
                    else ++start;
                }
            }
            return result;
        }
};
