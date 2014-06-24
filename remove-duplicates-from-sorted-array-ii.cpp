class Solution {
    public:
        int removeDuplicates(int A[], int n) {
            if(n < 3) return n;
            int i = 0, removed = 0;
            while(i < n - removed){
                int j = i + 1;
                while(A[i] == A[j] && j < n - removed) j++;
                if(j - i < 3) i = j;
                else
                {
                    int tmp = j;
                    if(j < n - removed){
                        for(int k = i + 2; j < n - removed; ++ k, ++ j){
                            A[k] = A[j];
                        }
                    }
                    removed += tmp - i - 2;
                    i = i + 2;
                }
            }
            return i;
        }
};
