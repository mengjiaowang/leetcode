class Solution {
    public:
        int numDecodings(string s) {
            if(s.size() == 0) return 0;
            if(s[0] == '0') return 0;
            for(int i = 0; i != s.size(); ++i){
                if(s[i] < '0' || s[i] > '9') return 0;
            }
            vector<int> ways(s.size()+1,0);
            ways[0] = 1;
            ways[1] = 1;
            for(int i = 2; i <= s.size(); ++i){
                int v1 = s[i-1] - '0';
                int v2 = (s[i-1] - '0') + 10 * (s[i-2] - '0');
                if(v1 != 0) ways[i] += ways[i-1];
                if(v2 > 9 && v2 <= 26) ways[i] += ways[i-2];
            }
            return ways[s.size()];
        }
};
