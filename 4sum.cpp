class Solution {
    public:
        vector<vector<int> > fourSum(vector<int> &num, int target) {
            vector<vector<int> > result;
            sort(num.begin(), num.end());
            for(int i = 0; i != num.size(); ++i){
                if(i != 0 && num[i] == num[i-1]) continue;
                for(int j = i + 1; j != num.size(); ++j){
                    if(j != i + 1 && num[j] == num[j-1]) continue;
                    int start = j + 1, end = num.size() - 1;
                    while(start < end){
                        if(start != j + 1 && num[start] == num[start-1]){
                            start ++;
                            continue;
                        }
                        int sum = num[i] + num[j] + num[start] + num[end];
                        if(sum == target){
                            vector<int> tmp;
                            tmp.push_back(num[i]);
                            tmp.push_back(num[j]);
                            tmp.push_back(num[start]);
                            tmp.push_back(num[end]);
                            result.push_back(tmp);
                            start ++;
                            end --;
                        }else if(sum < target){
                            start++;
                        }else if(sum > target){
                            end --;
                        }
                    }
                }
            }
            return result;
        }
};
