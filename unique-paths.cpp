class Solution {
    public:
        int uniquePaths(int m, int n) {
            int ** sum = new int*[m];
            for(int i = 0; i != m; ++i){
                sum[i] = new int[n];
            }
            for(int i = 0; i != m ; ++i){
                for(int j = 0; j != n; ++j){
                    if(i == 0 && j == 0) sum[i][j] = 1;
                    else if(i == 0 && j != 0) sum[i][j] = sum[i][j-1];
                    else if(i != 0 && j == 0) sum[i][j] = sum[i-1][j];
                    else sum[i][j] = sum[i-1][j] + sum[i][j-1];
                }
            }
            int result = sum[m-1][n-1];
            for(int i = 0; i != m; ++i){
                delete sum[i];
            }
            delete sum;
            return result;
        }
};
