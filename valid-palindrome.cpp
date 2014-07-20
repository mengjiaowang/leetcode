class Solution {
    public:
        bool isPalindrome(string s) {
            int start = 0, end = s.size() - 1;
            while(start <= end){
                while(!isalnum(s[start]) && start <= end) start ++;
                while(!isalnum(s[end]) && start <= end) end --;
                if(start <= end && tolower(s[start]) == tolower(s[end])){
                    ++ start; -- end;
                }
                else if(start <= end && tolower(s[start]) != tolower(s[end])){
                    return false;
                }
                else return true;
            }
            return true;
        }
};
