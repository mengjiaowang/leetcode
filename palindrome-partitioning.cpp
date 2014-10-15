class Solution {
    public:
        vector<vector<string>> partition(string s) {
            vector<vector<string>> result;
            vector<string> partition;
            dfs(s, partition, result);
            return result;
        }

        void dfs(string &s, vector<string> &partition, vector<vector<string>> &result) {
            if(s.size() == 0){
                result.push_back(partition);
            }
            for(int i = 1; i != s.size()+1; ++i){
                string tmp = s.substr(0, i);
                if(isPalindrome(tmp)){
                    partition.push_back(tmp);
                    string rest = s.substr(i);
                    dfs(rest, partition, result);
                    partition.pop_back();
                }
            }
        }

        bool isPalindrome(string &s){
            if(s.size() <= 1) return true;
            for(int i = 0; i < s.size()/2; ++i){
                if(s[i] != s[s.size()-i-1]) return false;
            }
            return true;
        }
};
