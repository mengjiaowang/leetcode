class Solution {
    public:
        int removeElement(int A[], int n, int elem) {
            int i = 0, j = 0;
            while(j < n){
                while(A[j] == elem && j < n) ++j;
                if(i != j && j < n) A[i++] = A[j++];
                if(i == j && j < n){++i; ++j;}
            }
            return i;
        }
};
