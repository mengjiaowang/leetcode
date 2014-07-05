class Solution {
    public:
        vector<vector<int> > permuteUnique(vector<int> &num) {
            vector<vector<int> > result;
            vector<int> permute; permute.reserve(num.size());
            sort(num.begin(), num.end());
            permuteGen(num, 0, permute, result);
            return result;
        }

        void permuteGen(vector<int> &num, int index, vector<int> &permute, vector<vector<int> > &result){
            if(index == num.size()){
                result.push_back(permute);
            }else{
                for(int i = index; i != num.size(); ++i){
                    if(i > index && num[i] == num[index]) continue;
                    swap(num[i], num[index]);
                    permute.push_back(num[index]);
                    permuteGen(num, index+1, permute, result);
                    permute.pop_back();
                }
                sort(num.begin()+index, num.end());
            }
        }

        void swap(int &a, int &b){
            int tmp = a;
            a = b;
            b = tmp;
        }
};
