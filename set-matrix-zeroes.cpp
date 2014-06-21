class Solution {
    public:
        void setZeroes(vector<vector<int> > &matrix) {
            set<int> row, column;
            for(int i = 0; i != matrix.size(); ++i){
                for(int j = 0; j != matrix[i].size(); ++j){
                    if(matrix[i][j] == 0){
                        row.insert(i); column.insert(j);
                    }
                }
            }
            set<int>::iterator iter;
            for(iter = row.begin(); iter != row.end(); iter++){
                for(int i = 0; i != matrix[*iter].size(); ++i){
                    matrix[*iter][i] = 0;
                }
            }
            for(iter = column.begin(); iter != column.end(); iter++){
                for(int j = 0; j != matrix.size(); ++j){
                    matrix[j][*iter] = 0;
                }
            }
        }
};
