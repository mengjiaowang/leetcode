class Solution {
    public:
        bool canJump(int A[], int n) {
            if(n == 0) return true;
            int stop1 = A[0];
            for(int i = 0; i != n && i <= stop1; ++i){
                int stop2 = i + A[i];
                if(stop2 > stop1) stop1 = stop2;
                if(stop1 >= n - 1) return true;
            }
            return false;
        }
};
