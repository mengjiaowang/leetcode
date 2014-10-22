class Solution {
    public:
        int longestValidParentheses(string s) {
            int length = 0;
            if(s.size() < 2) return length;

            int ** matrix = new int*[s.size()];
            for(int i = 0; i != s.size(); ++i){
                matrix[i] = new int[s.size()];
                memset((void*)matrix[i], 0, sizeof(int)*s.size());
            }

            for(int j = 1; j != s.size(); ++j){
                for(int i = j - 1; i >= 0; --i){
                    if((j - i) % 2 == 0) continue;
                    if(s[i] == '(' && s[j] == ')' && (j - i == 1 || matrix[i+1][j-1] == 1)){
                        matrix[i][j] = 1;
                        if(j - i > length) length = j - i;
                    }
                    else{
                        for(int k = i + 1; k < j - 1; ++k){
                            if(matrix[i][k] == 1 && matrix[k+1][j] == 1){
                                matrix[i][j] = 1;
                                if(j - i > length) length = j - i;
                                break;
                            }
                        }
                    }
                }
            }

            for(int i = 0; i != s.size(); ++i){
                delete []matrix[i];
            }
            delete []matrix;
            return length+1;
        }
};
