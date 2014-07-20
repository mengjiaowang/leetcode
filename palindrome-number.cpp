class Solution {
    public:
        bool isPalindrome(int x) {
            if(x < 0) return false;
            if(x < 10) return true;
            int n = ceil(log(x+1)/log(10));
            for(int i = 0; i != n/2; ++i){
                int a = (int)(x/pow(10,i)) % 10;
                int b = (int)(x/pow(10,n-i-1)) % 10;
                if(a != b) return false;
            }
            return true;
        }
};
