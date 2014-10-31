class Solution {
    public:
        vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
            vector<vector<string>> result;
            vector<string> path;
            unordered_map<string, vector<string> > map;
            unordered_map<string, int> depth;
            queue<string> q;
            int min = numeric_limits<int>::max();
            depth.insert(pair<string,int>(start, 1));
            dict.insert(end);
            q.push(start);
            while(!q.empty()){
                string word = q.front(); q.pop();
                if(word == end){
                    min = depth[word];
                    continue;
                }
                int d = depth[word] + 1;
                if(d > min) continue;
                for(int i = 0; i != word.size(); ++i){
                    string tmp(word);
                    for(int j = 'a'; j <= 'z'; ++j){
                        tmp[i] = j;
                        if(dict.find(tmp) == dict.end()) continue;
                        unordered_map<string, int>::iterator iter;
                        iter = depth.find(tmp);
                        if(iter == depth.end()){
                            depth.insert(pair<string, int>(tmp, d));
                            q.push(tmp);
                            map.insert(pair<string, vector<string> >(tmp, vector<string>{word}));
                        }else{
                            if(depth[tmp] == d) map[tmp].push_back(word);
                        }
                    }
                }
            }
            if(map.find(end) != map.end()){
                helper(end, min - 1, path, result, map);
            }
            return result;
        }

        void helper(string &end, int depth, vector<string> &path, vector<vector<string>> &result, 
                unordered_map<string, vector<string> > &map) {
            if(depth == 0){
                path.push_back(end);
                result.push_back(path);
                path.pop_back();
                reverse(result.back().begin(), result.back().end());
                return;
            }
            path.push_back(end);
            vector<string> &ref = map[end];
            for(int i = 0; i != ref.size(); ++i){
                helper(ref[i], depth - 1, path, result, map);
            }
            path.pop_back();
        }
};
