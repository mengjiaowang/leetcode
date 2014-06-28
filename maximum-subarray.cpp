ass Solution {
    public:
        int maxSubArray(int A[], int n) {
            int maxSum = std::numeric_limits<int>::min();
            for(int i = 0; i != n; ++ i){
                int sum = 0;
                for(int j = i; j != n; ++j){
                    sum += A[j];
                }
                if(sum > maxSum) maxSum = sum;
            }
            return maxSum;
        }
};
