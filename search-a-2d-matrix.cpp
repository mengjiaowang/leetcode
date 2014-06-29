ass Solution {
    public:
        bool searchMatrix(vector<vector<int> > &matrix, int target) {
            int numRows = matrix.size();
            if(numRows == 0) return false;
            int numColumns = matrix[0].size();
            int start = 0, end = numRows*numColumns - 1;
            while(start <= end){
                int mid = start - (start - end)/2;
                int row = mid / numColumns;
                int column = mid % numColumns;
                if(matrix[row][column] == target)
                    return true;
                else if(matrix[row][column] > target)
                    end = mid - 1;
                else
                    start = mid + 1;
            }
            return false;
        }
};
