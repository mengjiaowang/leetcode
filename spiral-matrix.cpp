class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int> > &matrix) {
            vector<int> result;
            if(matrix.size() == 0) return result;
            int numx = matrix.size(), numy = matrix[0].size(); 
            spiralOrder(matrix, 0, numx - 1, 0, numy - 1, result);
            return result;
        }

        void spiralOrder(vector<vector<int> > &matrix, int istart, int iend,
                int jstart, int jend, vector<int> &result){
            if(istart > iend || jstart > jend) return;
            else if(istart == iend){
                for(int j = jstart; j <= jend; ++j) result.push_back(matrix[istart][j]);
            }
            else if(jstart == jend){
                for(int i = istart; i <= iend; ++i) result.push_back(matrix[i][jstart]);
            }
            else{
                for(int j = jstart; j <= jend; ++j) result.push_back(matrix[istart][j]);
                for(int i = istart+1; i <= iend; ++i) result.push_back(matrix[i][jend]);
                for(int j = jend - 1; j >= jstart; --j) result.push_back(matrix[iend][j]);
                for(int i = iend - 1; i >= istart+1; --i) result.push_back(matrix[i][jstart]);
                spiralOrder(matrix, istart+1, iend-1, jstart+1, jend-1, result);
            }
        }
};
