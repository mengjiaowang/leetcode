class Solution {
    public:
        vector<vector<int> > threeSum(vector<int> &num) {
            vector<vector<int> > result;
            set<vector<int> > dup;
            sort(num.begin(), num.end());
            for(int i = 0; i != num.size(); ++i){
                int start = 0, end = num.size() - 1;
                if(start == i) ++start;
                if(end == i) --end;
                while(start < end){
                    if(num[start] + num[end] == num[i]*-1){
                        vector<int> tmp;
                        tmp.push_back(num[start]);
                        tmp.push_back(num[end]);
                        tmp.push_back(num[i]);
                        sort(tmp.begin(), tmp.end());
                        if(dup.find(tmp) == dup.end()){
                            result.push_back(tmp);
                            dup.insert(tmp);
                        }
                        ++start;
                        if(start == i) ++start;
                        --end;
                        if(end == i) --end;
                    }
                    else if(num[start] + num[end] < num[i]*-1){
                        ++start;
                        if(start == i) ++start;
                    }
                    else{
                        --end;
                        if(end == i) --end;
                    }
                }
            }
            return result;
        }
};
