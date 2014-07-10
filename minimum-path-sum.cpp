class Solution {
    public:
        int minPathSum(vector<vector<int> > &grid) {
            int res = 0, n = grid.size();
            if(n == 0) return res;
            int m = grid[0].size();
            int * sum = new int[n*m];

            for(int i = 0; i != n; ++i){
                for(int j = 0; j != m; ++j){
                    if(i == 0 && j == 0) sum[i*m+j] = 0;
                    else if(i == 0 && j != 0) sum[i*m+j] = sum[i*m+j-1];
                    else if(i != 0 && j == 0) sum[i*m+j] = sum[(i-1)*m+j];
                    else sum[i*m+j] = sum[(i-1)*m+j] < sum[i*m+j-1] ? sum[(i-1)*m+j] : sum[i*m+j-1];
                    sum[i*m+j] += grid[i][j];
                }
            }
            res = sum[n*m-1];
            delete sum;
            return res;
        }
};
