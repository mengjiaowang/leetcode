// http://yucoding.blogspot.com/2013/02/leetcode-question-123-wildcard-matching.html
class Solution {
    public:
        bool isMatch(const char *s, const char *p) {
            const char *star = NULL;
            const char *ss = s;
            while(*s){
                if(*s == *p || *p == '?'){ ++s; ++p; continue;}
                if(*p == '*'){ star = p++; ss = s; continue;}
                if(star){ p = star + 1; s = ++ss; continue;}
                return false;
            }
            while(*p == '*') ++p;
            return !*p;
        }
};
