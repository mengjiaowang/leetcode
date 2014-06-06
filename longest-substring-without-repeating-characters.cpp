class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int maxLength = 0;
            std::set<char> substring;
            for(int i = 0; i != s.size(); ++i){
                for(int j = i; j != s.size(); ++j){
                    if(substring.find(s[j]) != substring.end()){
                        if(substring.size() > maxLength){
                            maxLength = substring.size();
                            substring.clear();
                            break;
                        } 
                        else substring.insert(s[j]);
                    }
                }
            }
            return maxLength;
        }
};
