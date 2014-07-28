class Solution {
    public:
        int jump(int A[], int n) {
            if(n == 0) return 0;
            vector<int> steps(n, numeric_limits<int>::max());
            int farthest = 0;
            steps[0] = 0;
            for(int i = 0; i != n; ++i){
                if(A[i] + i <= farthest) continue;
                for(int j = 0; j != A[i]; ++j){
                    if(i + j + 1 < n && steps[i] + 1 < steps[i+j+1]) steps[i+j+1] = steps[i] + 1; 
                }
                farthest = A[i] + i;
            }
            if(steps[n-1] == numeric_limits<int>::max()) steps[n-1] = 0;
            return steps[n-1];
        }
};
