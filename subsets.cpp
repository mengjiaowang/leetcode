class Solution {
    public:
        vector<vector<int> > subsets(vector<int> &S) {
            int n = S.size(), len = 1 << (n + 1) - 1;
            sort(S.begin(), S.end());
            vector<vector<int> > result;
            for(int i = 0; i != len; ++i){
                vector<int> tmp;
                for(int j = 0; j != n; ++j){
                    if(i >> j & 1) tmp.push_back(S[j]);
                }
                result.push_back(tmp);
            }
            return result;
        }
};
