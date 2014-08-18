class Solution {
    public:
        vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
            sort(candidates.begin(), candidates.end());
            vector<vector<int> > result;
            vector<int> solution;
            combinationHelper(candidates, solution, result, target, 0);
            return result;
        }

        void combinationHelper(vector<int> &candidates, vector<int> &solution, vector<vector<int> > &result, int target, int start) {
            for(int i = start; i != candidates.size(); ++i){
                if(target == candidates[i]){
                    solution.push_back(candidates[i]);
                    result.push_back(solution);
                    solution.pop_back();
                }else if(target > candidates[i]){
                    solution.push_back(candidates[i]);
                    combinationHelper(candidates, solution, result, target-candidates[i], i);
                    solution.pop_back();
                }else return;
            }
        }
};
