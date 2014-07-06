class Solution {
    public:
        string getPermutation(int n, int k) {
            string permutation;
            bool used[n];
            memset((void*)used, false, sizeof(bool)*n);
            for(int i = 0; i != n; ++i){
                int count = 0, index = 0, factorial = 1;
                for(int j = 1; j <= n-i-1; ++j){
                    factorial *= j;
                }
                int v = (k-1)/factorial + 1; 
                for(index = 0; index != n; ++index){
                    if(used[index] == false) count ++;
                    if(count == v) break;
                }
                used[index] = true;
                permutation.push_back('0'+index+1);
                k = (k-1) % factorial + 1;
            }
            return permutation;
        }
};
