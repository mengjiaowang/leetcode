class Solution {
    public:
        int totalNQueens(int n) {
            int *arr = new int[n];
            int count = 0;
            place(arr, n, 0, count);
            delete arr;
            return count;
        }

        bool check(int *arr, int n, int k, int i){
            for(int j = 0; j != k; ++j){
                if(arr[j] == i || abs(j-k) == abs(arr[j]-i))
                    return false;
            }
            return true;
        }

        void place(int *arr, int n, int k, int &count){
            if(k == n){
                ++count;
                return;
            }
            else{
                for(int i = 0; i != n; ++i){
                    if(check(arr, n, k, i)){
                        arr[k] = i;
                        place(arr, n, k+1, count);
                    }
                }
            }
        }
};
