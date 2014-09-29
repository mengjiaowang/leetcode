class Solution {
    public:
        int longestConsecutive(vector<int> &num) {
            map<int,int> m;
            for(int i = 0; i != num.size(); ++i){
                m[num[i]] = 1;
            }
            map<int,int>::iterator i;
            for(i = m.begin(); i != m.end(); ++i){
                if(m.find(i->first-1) != m.end()){
                    m[i->first] = m[i->first-1]+1;
                }
            }
            int max = 0;
            for(i = m.begin(); i != m.end(); ++i){
                if(i->second > max) max = i->second;
            }
            return max;
        }
};
