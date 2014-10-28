class Solution {
    public:
        vector<int> findSubstring(string S, vector<string> &L) {
            vector<int> result;
            if(L.size() == 0) return result;
            int length = L[0].size();
            unordered_map<string, int> dict, cur;
            unordered_map<string, int>::iterator ifind1;
            unordered_map<string, int>::iterator ifind2;
            for(int i = 0; i != L.size(); ++i){
                ifind1 = dict.find(L[i]);
                if(ifind1 == dict.end()) dict[L[i]] = 1;
                else ifind1->second ++;
            }
            for(int i = 0; i != S.size() - L.size()*length + 1; ++i){
                int j = 0;
                for(j = 0; j != L.size(); ++j){
                    string tmp = S.substr(i + j*length, length);
                    ifind1 = dict.find(tmp);
                    if(ifind1 == dict.end()) break;
                    ifind2 = cur.find(tmp);
                    if(ifind2 == cur.end()) cur[tmp] = 1;
                    else{
                        ifind2->second ++;
                        if(ifind2->second > ifind1->second) break;
                    }
                }
                if(j == L.size()) result.push_back(i);
                cur.clear();
            }
            return result;
        }
};
