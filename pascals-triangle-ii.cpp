class Solution {
    public:
        vector<int> getRow(int rowIndex) {
            int numRows = rowIndex + 1;
            vector<vector<int> > res;
            vector<int> firstRow; firstRow.push_back(1); res.push_back(firstRow);
            for(int i = 1; i != numRows; ++i){
                vector<int> row; row.reserve(i+1); row.push_back(1);
                for(int j = 1; j < i; ++j){
                    row.push_back(res[i-1][j]+res[i-1][j-1]);
                }
                row.push_back(1); res.push_back(row);
            }
            return res[rowIndex];        
        }
};
