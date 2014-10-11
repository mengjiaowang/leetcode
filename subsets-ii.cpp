class Solution {
    public:
        vector<vector<int> > subsetsWithDup(vector<int> &S) {
            vector<vector<int> > result;
            vector<int> path;
            sort(S.begin(), S.end());
            dfs(S, S.begin(), path, result);
            return result;
        }

        void dfs(vector<int> &S, vector<int>::iterator begin, vector<int> &path, vector<vector<int> > &result){
            result.push_back(path);
            for(vector<int>::iterator i = begin; i != S.end(); i++){
                if(i != begin && *i == *(i-1)) continue;
                path.push_back(*i);
                dfs(S, i+1, path, result);
                path.pop_back();
            }
        }
};
