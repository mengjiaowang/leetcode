class Solution {
    public:
        string longestPalindrome(string s) {
            bool * dp = new bool[s.size()];
            memset((void*)dp, false, sizeof(bool)*s.size());
            int max = 0, index1 = 0, index2 = 0;

            for(int i = 0; i != s.size(); ++i){
                for(int j = 0; j <= i; ++j){
                    if(((i - j < 2) && s[i] == s[j]) || (dp[j+1] == true && s[i] == s[j])){
                        dp[j] = true;
                        if(i - j + 1 > max) {
                            max = i - j + 1;
                            index1 = j;
                            index2 = i;
                        }
                    }
                    else
                        dp[j] = false;
                }
            }

            delete []dp;
            return s.substr(index1, index2-index1+1);
        }
};
