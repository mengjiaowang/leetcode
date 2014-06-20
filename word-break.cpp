class Solution {
    public:
        bool wordBreak(string s, unordered_set<string> &dict) {
            bool * flag = new bool[s.size()+1];
            memset((void*)flag, false, sizeof(bool)*(s.size()+1));
            flag[0] = true;
            for(int i = 1; i <= s.size(); ++i){
                for(int j = 0; j != i; ++j){
                    if(dict.find(s.substr(j, i-j)) != dict.end() && flag[j] == true)
                    {
                        flag[i] = true;
                        break;
                    }
                }
            }
            bool res = flag[s.size()];
            delete flag;
            return res;
        }
};
