class Solution {
    public:
        bool search(int A[], int n, int target) {
            int l = 0, r = n - 1;
            while(l <= r){
                int m = l + (r-l)/2;
                if(A[m] == target) return true;
                else if(A[l] < A[m]){ // left part is sorted
                    if(A[l] <= target && target < A[m]) r = m - 1;
                    else l = m + 1;
                }
                else if(A[m] < A[r]){ // right part is sorted
                    if(A[m] < target && target <= A[r]) l = m + 1;
                    else r = m - 1;
                }
                else{
                    if(A[l] == target) return true;
                    else l++;
                };
            }
            return false;
        }
};
