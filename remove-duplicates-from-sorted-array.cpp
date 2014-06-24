ass Solution {
    public:
        int removeDuplicates(int A[], int n) {
            if(n < 2) return n;
            int i = 0, removed = 0;
            while(i < n - removed){
                int j = i + 1;
                while(A[i] == A[j] && j < n - removed) ++j;
                if(j - i < 2) i = j;
                else{
                    int tmp = j;
                    for(int k = i + 1; j < n - removed; ++j, ++k){
                        A[k] = A[j];
                    }
                    removed += tmp - i - 1;
                    i = i + 1;
                }
            }
            return i;
        }
};
