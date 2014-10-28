class Solution {
    public:
        bool isScramble(string s1, string s2) {
            return helper(s1, 0, s1.size() - 1, s2, 0, s2.size()-1);
        }

        bool helper(string &s1, int start1, int end1, string &s2, int start2, int end2){
            if((end1-start1) != (end2-start2)) return false;
            int n = end1 - start1;
            bool flag = true;
            for(int i = 0; i != n; ++i){
                if(s1[start1+i] != s2[start2+i]){
                    flag = false;
                    break;
                }
            }
            if(flag == true) return true;
            for(int i = 1; i < n - 1; ++i){
                if(helper(s1, start1, start1+i, s2, start2, start2+i) && 
                        helper(s1, start1+i, end1,   s2, start2+i, end2)) return true;
                if(helper(s1, start1, start1+i, s2, start2+n-i, end2) && 
                        helper(s1, start1+i, end1,   s2, start2, start2+n-1)) return true;
            }
            return false;        
        }
};
