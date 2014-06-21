class Solution {
    public:
        int singleNumber(int A[], int n) {
            int result = 0;
            for(int i = 0; i != 32; ++i){
                int sum = 0, x = 1 << i;
                for(int j = 0; j != n; ++j){
                    if(A[j] & x) sum ++;
                }
                result |= (sum % 3) << i;
            }
            return result;
        }
};
