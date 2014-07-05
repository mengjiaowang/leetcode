class Solution {
    public:
        vector<vector<int> > permute(vector<int> &num) {
            vector<vector<int> > result;
            vector<int> permute; permute.reserve(num.size());
            permuteGen(num, 0, permute, result);
            return result;
        }

        void permuteGen(vector<int> &num, int index, vector<int> &permute, vector<vector<int> > &result){
            if(index == num.size()){
                result.push_back(permute);
            }else{
                for(int i = index; i != num.size(); ++i){
                    swap(num[i], num[index]);
                    permute.push_back(num[index]);
                    permuteGen(num, index+1, permute, result);
                    permute.pop_back();
                    swap(num[i], num[index]);
                }
            }
        }

        void swap(int &a, int &b){
            int tmp = a;
            a = b;
            b = tmp;
        }
};
