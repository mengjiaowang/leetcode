class Solution {
    public:
        int numDistinct(string S, string T) {
            int *matrix = new int[T.size()+1];
            memset((void*)matrix, 0, sizeof(int)*(T.size()+1));
            matrix[0] = 1;
            int count = 0;
            for(int i = 1; i != S.size()+1; ++i){
                for(int j = T.size(); j >= 1; --j){
                    if(S[i-1] == T[j-1]){
                        matrix[j] += matrix[j-1];
                    }
                }
            }
            count = matrix[T.size()];
            delete []matrix;
            return count;
        }
};
