class Solution {
    public:

        vector<string> wordBreak(string s, unordered_set<string> &dict) {
            vector<string> result;
            vector<vector<int> > index;
            index.resize(s.size() + 1);
            index[0].push_back(0);

            for(int i = 1; i <= s.size(); ++i){
                for(int j = 0; j != i; ++j){
                    string substr = s.substr(j, i-j);
                    if(index[j].size() != 0 && dict.find(substr) != dict.end()){
                        index[i].push_back(j);
                    }
                }
            }

            string tmp;
            dfs(s, index, s.size(), tmp, result);
            return result;
        }

        void dfs(string &s, vector<vector<int> > &index, int end, string &tmp, vector<string> &result){
            if(end == 0){
                reverse(tmp.begin(), tmp.end());
                result.push_back(tmp.substr(1));
                return;
            }
            for(int i = 0; i != index[end].size(); ++i){
                string substr = s.substr(index[end][i], end - index[end][i]);
                reverse(substr.begin(), substr.end());
                string str = tmp + substr + " ";
                dfs(s, index, index[end][i], str, result);
            }
        }


};
