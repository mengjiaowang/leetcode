class Solution {
    public:
        int maximalRectangle(vector<vector<char> > &matrix) {
            vector<vector<int> > vertical, horizontal;
            int max = 0;
            vertical.resize(matrix.size()); horizontal.resize(matrix.size());
            for(int i = 0; i != matrix.size(); ++i){
                vertical[i].resize(matrix[i].size());
                horizontal[i].resize(matrix[i].size());
            }
            for(int i = 0; i != matrix.size(); ++i){
                for(int j = 0; j != matrix[i].size(); ++j){
                    int s = 0;
                    if(matrix[i][j] == '0'){
                        vertical[i][j] = 0; horizontal[i][j] = 0;
                    }
                    else{
                        if(i == 0 && j == 0){
                            vertical[i][j] = 1; horizontal[i][j] = 1;
                            s = 1;
                        }else if(i == 0 && j != 0){
                            horizontal[i][j] = horizontal[i][j-1] + 1;
                            vertical[i][j] = 1;
                            s = horizontal[i][j];
                        }else if(i != 0 && j == 0){
                            vertical[i][j] = vertical[i-1][j] + 1;  
                            horizontal[i][j] = 1;
                            s = vertical[i][j];
                        }else{
                            horizontal[i][j] = horizontal[i][j-1] + 1;
                            vertical[i][j] = vertical[i-1][j] + 1;
                            s = vertical[i][j] * horizontal[i][j];
                        }
                    }
                    if(s > max) max = s;
                }
            }
            return max;
        }
};
