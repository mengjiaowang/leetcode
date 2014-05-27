class Solution {
    public:
        void merge(int A[], int m, int B[], int n) {
            if(n == 0) return;
            for(unsigned int i = 0; i != m; ++i)
            {
                A[m + n - 1 - i] = A[m - 1 - i];
            }
            unsigned int startA = n, startB = 0, index = 0;
            while(startA != (m + n) && startB != n){
                if(A[startA] <= B[startB]){
                    A[index] = A[startA]; ++ startA; ++ index;
                }else{
                    A[index] = B[startB]; ++ startB; ++ index;
                }
            }
            while(startA != (m + n)){
                A[index] = A[startA]; ++ startA; ++index;
            }
            while(startB != n){
                A[index] = B[startB]; ++ startB; ++ index;
            }
        }
};
