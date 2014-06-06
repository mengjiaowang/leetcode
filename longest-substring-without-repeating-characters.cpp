// http://leetcode.com/2011/05/longest-substring-without-repeating-characters.html

#define MAX(a,b) (a) > (b) ? (a) : (b)

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int maxLength = 0, i = 0, j = 0;
            bool map [256] = {false};
            while(j < s.size()){
                if(map[s[j]] == false){
                    map[s[j]] = true;
                    j ++;
                }else{
                    maxLength = MAX(maxLength, j - i);
                    while(s[i] != s[j]){
                        map[s[i]] = false;
                        ++ i;
                    }
                    ++ i;
                    ++ j;
                }
            }
            maxLength = MAX(maxLength, j - i);
            return maxLength;
        }
};
