class Solution {
    public:

        vector<vector<int> > combinationSum2(vector<int> &num, int target) {
            sort(num.begin(), num.end());
            vector<vector<int> > result;
            vector<int> solution;
            combinationHelper(num, solution, result, target, 0);
            sort(result.begin(), result.end());
            vector<vector<int> >::iterator last = unique(result.begin(), result.end());
            result.erase(last, result.end());
            return result;
        }

        void combinationHelper(vector<int> &num, vector<int> &solution, vector<vector<int> > &result, int target, int start) {
            for(int i = start; i != num.size(); ++i){
                if(target == num[i]){
                    solution.push_back(num[i]);
                    result.push_back(solution);
                    solution.pop_back();
                }else if(target > num[i]){
                    solution.push_back(num[i]);
                    combinationHelper(num, solution, result, target-num[i], i+1);
                    solution.pop_back();
                }else return;
            }
        }
};
