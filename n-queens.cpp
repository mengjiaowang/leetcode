class Solution {
    public:
        vector<vector<string> > solveNQueens(int n) {
            vector<vector<string> > results;
            if(n == 0) return results;
            int *arr = new int[n];
            int count = 0;
            place(arr, n, 0, results);
            delete arr;
            return results;
        }

        bool check(int *arr, int n, int k, int i){
            for(int j = 0; j != k; ++j){
                if(arr[j] == i || abs(j-k) == abs(arr[j]-i))
                    return false;
            }
            return true;
        }

        void place(int *arr, int n, int k, vector<vector<string> > &results){
            if(k == n){
                vector<string> tmp;
                for(int i = 0; i != n; ++i){
                    string s(n, '.');
                    s[arr[i]] = 'Q';
                    tmp.push_back(s);
                }
                results.push_back(tmp);
                return;
            }
            else{
                for(int i = 0; i != n; ++i){
                    if(check(arr, n, k, i)){
                        arr[k] = i;
                        place(arr, n, k+1, results);
                    }
                }
            }
        }
};
