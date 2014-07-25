class Solution {
    public:
        vector<vector<int> > generateMatrix(int n) {
            vector<vector<int> > result;
            if(n == 0) return result;
            result.resize(n);
            for(int i = 0; i != n; ++i){
                result[i].resize(n);
            }
            int start = 0, end = n - 1, num = 1;
            while(start <= end){
                for(int i = start; i <= end; ++i)
                    result[start][i] = num ++;
                for(int i = start + 1; i <= end; ++i)
                    result[i][end] = num ++;
                for(int i = end - 1; i >= start; --i)
                    result[end][i] = num ++;
                for(int i = end - 1; i >= start + 1; --i)
                    result[i][start] = num ++;
                ++start; --end; 
            }
            return result;
        }
};
