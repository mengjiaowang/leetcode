class Solution {
    public:
        vector<int> findSubstring(string S, vector<string> &L) {
            vector<int> result;
            if(L.size() == 0) return result;
            int size = L.size() * L[0].size();
            unordered_map<string, int> dict;
            unordered_map<string, int>::iterator iter;
            for(int i = 0; i != L.size(); ++i){
                iter = dict.find(L[i]);
                if(iter != dict.end()){
                    iter->second += 1;
                }
                else{
                    dict[L[i]] = 1;
                }
            }
            int i = 0, j = 0;
            for(i = 0; i < S.size() - size + 1; ++i){
                for(j = 0; j != L.size(); ++j){
                    string sub = S.substr(i+j*L[0].size(), L[0].size());
                    iter = dict.find(sub);
                    if(iter == dict.end()){
                        break;
                    }
                    else{
                        iter->second -= 1;
                    }
                }
                if(j == L.size()){
                    bool flag = false;
                    for(iter = dict.begin(); iter != dict.end(); iter++){
                        if(iter->second != 0){
                            flag = true; break;
                        }
                    }
                    if(flag == false) result.push_back(i);
                }
                dict.clear();
                for(int i = 0; i != L.size(); ++i){
                    iter = dict.find(L[i]);
                    if(iter != dict.end()){
                        iter->second += 1;
                    }
                    else{
                        dict[L[i]] = 1;
                    }
                }

            }
            return result;
        }
};
