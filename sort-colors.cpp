class Solution {
    public:
        void sortColors(int A[], int n) {
            int numRed = 0, numWhite = 0, numBlue = 0;
            for(int i = 0; i != n; ++i){
                if(A[i] == 0) numRed ++;
                else if(A[i] == 1) numWhite ++;
                else if(A[i] == 2) numBlue ++;
            }
            int count = 0;
            while(numRed--) A[count++] = 0;
            while(numWhite--) A[count++] = 1;
            while(numBlue--) A[count++] = 2;
        }
};
