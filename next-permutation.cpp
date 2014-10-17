class Solution {
    public:
        void nextPermutation(vector<int> &num) {
            if(num.size() < 2) return;
            int i = num.size() - 1, j = num.size() - 2;
            while(num[j] >= num[j+1] && j >= 0) --j;
            if(j >= 0){
                while(num[i] <= num[j]) --i;
                swap(num[i], num[j]);
            }
            reverse(num.begin()+j+1, num.end());
        }
};
