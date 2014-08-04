class Solution {
    public:
        int ladderLength(string start, string end, unordered_set<string> &dict) {
            if(start == end) return 2;
            queue<string> q; q.push(start);
            int depth = 1, layerCount = 1, nextLayerCount = 0;
            unordered_set<string> visited;
            while(!q.empty()){
                string cur = q.front(); q.pop();
                layerCount --;
                unordered_set<string>::iterator iter;
                for(iter = dict.begin(); iter != dict.end(); iter++){
                    if(checkTransformation(cur, *iter)){
                        if(cur == end) return depth;
                        if(checkTransformation(cur, end)) return depth + 1;
                        if(visited.find(*iter) == visited.end()){
                            q.push(*iter); 
                            nextLayerCount ++;
                            visited.insert(*iter);
                        }
                    }
                }
                if(layerCount == 0) {
                    depth ++;
                    layerCount = nextLayerCount;
                    nextLayerCount = 0;
                }
            }
            return 0;
        }

        bool checkTransformation(const string &word1, const string &word2){
            int count = 0;
            for(int i = 0; i != word1.size(); ++i){
                if(word1[i] != word2[i]){
                    count ++;
                }
            }
            if(count == 1) return true;
            else return false;
        }
};
