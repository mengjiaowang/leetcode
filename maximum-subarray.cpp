class Solution {
    public:
        int maxSubArray(int A[], int n) {
            if(n <= 0) return 0;
            int maxSum = A[0], maxEnding = A[0];
            for(int i = 1; i != n; ++i){
                if(maxEnding < 0) maxEnding = A[i];
                else maxEnding += A[i];
                if(maxSum < maxEnding) maxSum = maxEnding;
            }
            return maxSum;
        }
};
