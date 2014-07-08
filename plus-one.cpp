class Solution {
    public:
        vector<int> plusOne(vector<int> &digits) {
            vector<int> res; int flag = 1;
            for(int i = digits.size() - 1; i >= 0; --i){
                int tmp = digits[i] + flag;
                if(tmp < 10) {res.push_back(tmp); flag = 0;}
                else {res.push_back(tmp-10); flag = 1;}
            }
            if(flag == 1) res.push_back(1);
            reverse(res.begin(), res.end());
            return res;
        }
};
