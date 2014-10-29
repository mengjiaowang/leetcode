class Solution {
    public:
        int maximalRectangle(vector<vector<char> > &matrix) {
            if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
            int nRow = matrix.size();
            int nCol = matrix[0].size();
            int max = 0;
            vector<int> H(nCol+1, 0);
            for(int row = 0; row != nRow; ++row){
                stack<int> s;
                for(int i = 0; i != nCol + 1; ++i){
                    if(i < nCol){
                        if(matrix[row][i] == '1') H[i] ++;
                        else H[i] = 0;
                    }
                    if(s.empty() || H[s.top()] <= H[i]) s.push(i);
                    else{
                        while(!s.empty() && H[s.top()] > H[i]){
                            int t = s.top(); s.pop();
                            int area = H[t] * (s.empty() ? i : i - s.top() - 1);
                            if(area > max) max = area;
                        }
                    }
                    s.push(i);
                }
            }
            return max;
        }
};
