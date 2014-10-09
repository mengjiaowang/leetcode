class Solution {
    public:
        vector<vector<int> > threeSum(vector<int> &num) {
            vector<vector<int> > result;
            sort(num.begin(), num.end());
            for(int i = 0; i != num.size(); ++i){
                if(i != 0 && num[i] == num[i-1]) continue;
                int start = i + 1, end = num.size() - 1;
                while(start < end){
                    if(start != i + 1 && num[start] == num[start-1]){
                        ++start;
                        continue;
                    }
                    int sum = num[start] + num[end];
                    if(sum == num[i]*-1){
                        vector<int> tmp;
                        tmp.push_back(num[start]);
                        tmp.push_back(num[end]);
                        tmp.push_back(num[i]);
                        sort(tmp.begin(), tmp.end());
                        result.push_back(tmp);
                        ++start;
                        --end;
                    }
                    else if(sum < num[i]*-1){
                        ++start;
                    }
                    else{
                        --end;
                    }
                }
            }
            return result;
        }
};
