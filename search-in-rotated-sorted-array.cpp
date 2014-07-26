class Solution {
    public:
        int search(int A[], int n, int target) {
            if(n == 0) return -1;
            int start = findStart(A, n);
            if(start == 0){
                return binarySearch(A, 0, n - 1, target);
            }
            else{
                int index = binarySearch(A, 0, start - 1, target);
                if(index != -1) return index;
                return binarySearch(A, start, n - 1, target);
            }
        }

        int findStart(int A[], int n){
            if(n < 2) return 0;
            int start = 0, end = n - 1;
            while(end - start > 1){
                int mid = (start + end)/2;
                if(A[mid] > A[start] && A[mid] < A[end]) return start;
                else if(A[mid] > A[start] && A[mid] > A[end]) start = mid;
                else if(A[mid] < A[start] && A[mid] < A[end]) end = mid;
            }
            if(A[start] < A[end]) return start;
            else return end;
        }

        int binarySearch(int A[], int start, int end, int target){
            while(start <= end){
                int mid = (start + end)/2;
                if(A[mid] == target) return mid;
                else if(A[mid] > target) end = mid - 1;
                else if(A[mid] < target) start = mid + 1;
            }
            return -1;
        }
};
