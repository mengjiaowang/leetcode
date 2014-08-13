// solution from blogpost http://blog.csdn.net/linhuanmars/article/details/19873463
//
class Solution {
    public:
        vector<string> generateParenthesis(int n)
        {
            vector<string> res;
            if(n <= 0) return res;
            string item;
            helper(n, n, item, res);
            return res;
        }

        void helper(int l, int r, string item, vector<string> &res){
            if(r < l) return;
            if(r == 0 && l == 0){
                res.push_back(item);
            }
            if(l > 0) helper(l-1,r,item+"(",res);
            if(r > 0) helper(l,r-1,item+")",res);
        }
};
