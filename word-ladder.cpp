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

                for(int i = 0; i != cur.size(); ++i){
                    for(char j = 'a'; j < 'z'; ++j){
                        if(cur[i] == j) continue;
                        string tmp = cur; tmp[i] = j;
                        if(tmp == end) return depth + 1;
                        if(dict.find(tmp) != dict.end()){
                            q.push(tmp);
                            dict.erase(tmp);
                            ++nextLayerCount;
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

};
