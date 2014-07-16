class Solution {
    public:
        bool canJump(int A[], int n) {
            if(n == 0) return true;
            bool *flag = new bool[n];
            memset((void*)flag, false, sizeof(bool)*n);
            flag[n-1] = true;
            for(int i = n - 1; i >=0; i --){
                if(A[i] >= n - i){flag[i] = true; continue;}
                for(int j = i + 1; j <= i + A[i]; ++j){
                    if(flag[j] == true){flag[i] = true; break;}
                }
            }
            return flag[0];
        }
};
