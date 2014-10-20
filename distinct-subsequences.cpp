class Solution {
    public:
        int numDistinct(string S, string T) {
            if(T.size() == 0) return 1;
            if(S.size() < T.size()) return 0;
            int count = 0;
            for(int i = 0; i != S.size(); ++i){
                if(T[0] == S[i]){
                    count += numDistinct(S.substr(i+1), T.substr(1));
                }
            }
            return count;
        }
};
