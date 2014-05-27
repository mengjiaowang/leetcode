class Solution {
    public:
        void merge(int A[], int m, int B[], int n) {
            for(int i = m + n - 1; i != -1; --i){
                A[i] = (m != 0 && ( n == 0 || (A[m-1] > B[n-1])))?A[--m]:B[--n];
            }
        }
};
