class Solution {
    public:
        int trap(int A[], int n) {
            int left = 0, right = n - 1;
            int height = 0, area = 0;
            while(left < right){
                if(A[left] < A[right]){
                    height = height > A[left] ? height : A[left];
                    area += height - A[left];
                    left ++;
                }else{
                    height = height > A[right] ? height : A[right];
                    area += height - A[right];
                    right --;
                }
            }
            return area;
        }
};
