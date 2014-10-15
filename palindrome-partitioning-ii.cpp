class Solution {
    public:
        int minCut(string s) {
            if(s.size() == 0) return 0;
            int minCuts = s.size();
            int *cuts = new int[s.size()+1];
            bool **matrix = new bool*[s.size()];
            for(int i = 0; i != s.size(); ++i){
                matrix[i] = new bool[s.size()];
                memset((void*)matrix[i], false, sizeof(bool)*s.size());
            }

            for(int i = 0; i != s.size()+1; ++i){
                cuts[i] = s.size() - i;
            }

            for(int i = s.size()-1; i >= 0; --i){
                for(int j = i; j != s.size(); ++j){
                    if((j - i < 2 || matrix[i+1][j-1] == true) && s[i] == s[j]){
                        matrix[i][j] = true;
                        cuts[i] = min(cuts[i], cuts[j+1]+1);
                    }
                }
            }

            minCuts = cuts[0]-1;
            delete cuts;
            for(int i = 0; i != s.size(); ++i){
                delete matrix[i];
            }
            delete matrix;
            return minCuts;
        }
};
