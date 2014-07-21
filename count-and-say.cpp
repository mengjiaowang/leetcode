class Solution {
    public:
        string countAndSay(int n) {
            string res = "1";
            for(int i = 1; i != n; ++i){
                string tmp;
                for(int j = 0; j != res.size(); ++j){
                    int count = 1;
                    while(j+1 != res.size() && res[j] == res[j+1]){ ++count; ++j;}
                    tmp.push_back(count+'0');
                    tmp.push_back(res[j]);
                }
                res = tmp;
            }
            return res;
        }
};
