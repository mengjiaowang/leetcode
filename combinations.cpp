class Solution {
    public:
        vector<vector<int> > combine(int n, int k) {
            vector<vector<int> > result;
            vector<int> assist;
            combine(n, k, 1, result, assist);
            return result;
        }

        void combine(int n, int k, int start, 
                vector<vector<int> >&result, 
                vector<int> &assist)
        {
            if(k == 0){
                result.push_back(assist);
                return;
            }
            vector<int> tmp = assist;
            for(int i = start; i <= n-k+1; ++i){
                tmp.push_back(i);
                combine(n, k - 1, i + 1, result, tmp);
                tmp.pop_back();
            }
        }
};
