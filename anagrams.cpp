class Solution {
    public:
        vector<string> anagrams(vector<string> &strs) {
            unordered_map<string, int> store;
            unordered_set<int> visited;
            vector<string> results;
            for(int i = 0; i != strs.size(); ++i){
                string sorted = strs[i];
                sort(sorted.begin(), sorted.end());
                unordered_map<string, int>::iterator iter = store.find(sorted);
                if(iter != store.end()){
                    if(visited.find(iter->second) == visited.end()){
                        results.push_back(strs[iter->second]);
                        visited.insert(iter->second);
                    }
                    if(visited.find(i) == visited.end()){
                        results.push_back(strs[i]);
                        visited.insert(i);
                    }
                }else{
                    store[sorted] = i;
                }
            }
            return results;
        }
};
