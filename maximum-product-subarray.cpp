class Solution {
    public:
        int maxProduct(int A[], int n) {
            if(n == 0) return 0;
            int max = A[0];
            int *p = new int[n];
            for(int i = 0; i != n; ++i){
                for(int j = i; j != n; ++j){
                    if(j == i) p[j] = A[j];
                    else p[j] = p[j-1]*A[j];
                    if(p[j]>max) max = p[j];
                }
            }
            delete p;
            return max;
        }
};
