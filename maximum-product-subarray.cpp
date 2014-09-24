class Solution {
    public:
        int maxProduct(int A[], int n) {
            if(n == 0) return 0;
            int pos = 0, neg = 0, ans = A[0];

            for(int i = 0; i != n; ++i){
                if(A[i] > 0){
                    if(pos > 0) pos = pos*A[i];
                    else pos = A[i];
                    neg = neg*A[i];
                }
                else if(A[i] < 0){
                    int tmp = neg;
                    if(pos > 0) neg = pos*A[i];
                    else neg = A[i];
                    pos = tmp * A[i];
                }
                else if(A[i] == 0){
                    pos = 0;
                    neg = 0;
                }
                if(pos > 0 || A[i] == 0)
                    ans = max(ans, pos);
            }
            return ans;
        }
};
