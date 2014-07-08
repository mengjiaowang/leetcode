class Solution {
    public:

        vector<string> letterCombinations(string digits) {
            vector<string> result;
            vector<string> mapping = {"","","abc","def","ghi","jkl","mno","pqrs", "tuv", "wxyz"};
            string path = "";
            dfs(digits, path, result, mapping);
            return result;
        }

        void dfs(string &digits, string &path, vector<string> &result, vector<string> & mapping){
            if(digits.size() == 0){
                result.push_back(path); return;
            }
            int size = mapping[digits[0]-'0'].size();
            for(int i = 0; i != size; ++i){
                path.push_back(mapping[digits[0]-'0'][i]);
                string str = digits.substr(1);
                dfs(str, path, result, mapping);
                path.pop_back();
            }
        }
};
