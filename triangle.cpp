class Solution {
    public:
        int minimumTotal(vector<vector<int> > &triangle) {
            if(triangle.size() == 0) return 0;
            vector<int> minimumsPre; minimumsPre.resize(triangle.size());
            minimumsPre[0] = triangle[0][0];
            int minimumGlobal = minimumsPre[0];

            for(int i = 1; i != triangle.size(); ++i){
                vector<int> minimums;
                minimums.resize(triangle[i].size());
                for(int j = 0; j <= i; ++j){
                    int minimumLocal = std::numeric_limits<int>::max();
                    if(j > 0) minimumLocal = triangle[i][j] + minimumsPre[j-1] < minimumLocal ? triangle[i][j] + minimumsPre[j-1] : minimumLocal;
                    //if(j+1 < triangle[i-1].size()) minimumLocal = triangle[i][j] + minimumsPre[j+1] < minimumLocal ? triangle[i][j] + minimumsPre[j+1] : minimumLocal;
                    if(j < triangle[i-1].size()) minimumLocal = triangle[i][j] + minimumsPre[j] < minimumLocal ? triangle[i][j] + minimumsPre[j] : minimumLocal;
                    minimums[j] = minimumLocal;
                }
                minimumGlobal = minimums[0];
                for(int j = 0; j != minimums.size(); ++j){
                    minimumsPre[j] = minimums[j];
                    if(minimumGlobal > minimums[j]) minimumGlobal = minimums[j];
                }
            }
            return minimumGlobal;
        }
};
