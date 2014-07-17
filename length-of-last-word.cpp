class Solution {
    public:
        int lengthOfLastWord(const char *s) {
            int n = strlen(s), length = 0;
            if(n == 0) return 0;
            while(s[n-1] == ' ') n --;
            for(int i = n - 1; i >= 0; --i){
                if(s[i] != ' ') length ++;
                else break;
            }
            return length;
        }
};
