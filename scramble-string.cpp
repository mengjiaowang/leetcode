class Solution {
    public:
        bool isScramble(string s1, string s2) {
            if(s1.size() != s2.size()) return false;
            int n = s1.size();
            vector<vector<vector<bool> > > dp(n+1,
                vector<vector<bool> >(n, vector<bool>(n, false)));
            for(int len = 1; len != n + 1; ++len){
                for(int i = 0; i != n - len + 1; ++i){
                    for(int j = 0; j != n - len + 1; ++j){
                        if(len == 1) dp[len][i][j] = (s1[i] == s2[j]);
                        else{
                            for(int k = 1; k < len; ++k){
                                if(dp[k][i][j] && dp[len-k][i+k][j+k] ||
                                   dp[k][i][j+len-k] && dp[len-k][i+k][j]){
                                    dp[len][i][j] = true;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            return dp[n][0][0];
        }
};
