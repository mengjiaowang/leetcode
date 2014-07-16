class Solution {
    public:
        bool isInterleave(string s1, string s2, string s3) {
            if(s1.size() + s2.size() != s3.size()) return false;
            bool ** flag = new bool*[s1.size()+1];
            for(int i = 0; i != s1.size()+1; ++i){
                flag[i] = new bool[s2.size()+1];
                memset((void*)flag[i], false, (s2.size()+1)*sizeof(bool));
            }
            flag[0][0] = true;
            for(int i = 0; i != s1.size() + 1; ++i){
                for(int j = 0; j != s2.size() + 1; ++j){
                    if(j > 0 && i == 0) flag[i][j] = flag[i][j-1] & (s2[j-1] == s3[i+j-1]);
                    if(i > 0 && j == 0) flag[i][j] = flag[i-1][j] & (s1[i-1] == s3[i+j-1]);
                    if(i > 0 && j > 0){
                        flag[i][j] = (flag[i][j-1] & (s2[j-1] == s3[i+j-1])) || (flag[i-1][j] & (s1[i-1] == s3[i+j-1]));
                    }
                }
            }
            bool result = flag[s1.size()][s2.size()];
            for(int i = 0; i != s1.size()+1; ++i){
                delete flag[i];
            }
            delete flag;
            return result;
        }
};
