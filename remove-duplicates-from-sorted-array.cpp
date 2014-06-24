class Solution {
    public:
        int removeDuplicates(int A[], int n) {
            if(n < 2) return n;
            int i = 0, j = 0;
            while(j != n){
                while(A[i] == A[j] && j != n) ++j;
                if(j - i == 1) ++i;
                else{
                    ++i; A[i] = A[j];
                }
            }
            return i;
        }
};
