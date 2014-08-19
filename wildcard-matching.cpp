class Solution {
    public:
        bool isMatch(const char *s, const char *p) {
            if(*p == '\0') return *p == *s;
            if(*p == '?') return isMatch(++s, ++p);
            else if(*p == '*'){
                while(*p == '*') ++p;
                for(p; *s != '\0'; ++s){
                    if(isMatch(s, p) == true) return true;
                }
                return *p == '\0';
            }
            else return *p == *s && isMatch(++s, ++p);
        }
};
