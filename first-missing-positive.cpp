class Solution {
    public:
        int firstMissingPositive(int A[], int n) {
            for(int i = 0; i < n; ++i){
                while(A[i] > 0 && A[i] <= n && A[i] != i+1){
                    if(A[i] == A[A[i]-1]) break;
                    int tmp = A[i], index = A[i]-1;
                    A[i] = A[index];
                    A[index] = tmp;
                }
            }
            for(int i = 0; i < n; ++i){
                if(A[i] != i + 1) return i + 1;
            }
            return n + 1;
        }
};
