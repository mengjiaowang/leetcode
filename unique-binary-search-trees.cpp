class Solution {
    public:
        int numTrees(int n) {
            int res [n+1]; 
            memset(res, 0, 4*(n+1));
            res[0] = 1;
            for(int j = 1; j != n + 1; ++j){
                for(int i = 1; i != j + 1; ++i){
                    res[j] += res[j-i]*res[i-1];       
                }
            }
            return res[n];
        }
};
