class Solution {
    public:

        bool isInterleave(string s1, string s2, string s3) {
            return isInterleave(s1, 0, s2, 0, s3, 0);
        }

        bool isInterleave(string &s1, int index1, string &s2, int index2, string &s3, int index3) {
            if(index1 == s1.size() && index2 == s2.size() && index3 == s3.size())
                return true;

            bool first = false, second = false;
            if(index1 < s1.size() && index3 < s3.size() && s1[index1] == s3[index3]){
                first = isInterleave(s1, index1+1, s2, index2, s3, index3+1);
            }
            if(index2 < s2.size() && index3 < s3.size() && s2[index2] == s3[index3]){
                second = isInterleave(s1, index1, s2, index2+1, s3, index3+1);
            }
            return first | second;
        }

};
