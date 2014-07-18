class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
            int m = obstacleGrid.size(); if(m == 0) return 0;
            int n = obstacleGrid[0].size();

            int ** sum = new int*[m];
            for(int i = 0; i != m; ++i){
                sum[i] = new int[n];
                memset((void*)sum[i], 0, sizeof(int)*n);
            }
            for(int i = 0; i != m ; ++i){
                for(int j = 0; j != n; ++j){
                    if(i == 0 && j == 0) {
                        if(obstacleGrid[i][j] != 1) sum[i][j] = 1;
                    }
                    else if(i == 0 && j != 0){
                        if(obstacleGrid[i][j-1] != 1 && obstacleGrid[i][j] != 1){
                            sum[i][j] = sum[i][j-1];
                        }
                    } 
                    else if(i != 0 && j == 0){
                        if(obstacleGrid[i-1][j] != 1 && obstacleGrid[i][j] != 1){
                            sum[i][j] = sum[i-1][j];
                        }
                    } 
                    else{
                        if(obstacleGrid[i][j-1] != 1 && obstacleGrid[i][j] != 1){
                            sum[i][j] += sum[i][j-1];
                        }
                        if(obstacleGrid[i-1][j] != 1 && obstacleGrid[i][j] != 1){
                            sum[i][j] += sum[i-1][j];
                        }
                    }
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
