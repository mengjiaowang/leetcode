class Solution {
    public:
        vector<int> searchRange(int A[], int n, int target) {
            vector<int> result;
            result.push_back(-1);
            result.push_back(-1);
            int index = binarySearch(A, 0, n - 1, target);
            if(index == -1) return result;
            result[0] = index; result[1] = index;
            int start = 0, end = index - 1;
            int preindex = 0;
            while(preindex != -1 && start <= end){
                preindex = binarySearch(A, start, end, target);
                if(preindex != -1){
                    result[0] = preindex;
                    end = preindex - 1;
                }
            }
            start = index + 1, end = n - 1;
            int postindex = 0;
            while(postindex != -1 && start <= end){
                postindex = binarySearch(A, start, end, target);
                if(postindex != -1){
                    result[1] = postindex;
                    start = postindex + 1;
                }
            }
            return result;
        }

        int binarySearch(int A[], int start, int end, int target){
            while(start <= end){
                int mid = (start+end)/2;
                if(A[mid] == target) return mid;
                else if(A[mid] > target) end = mid - 1;
                else start = mid + 1;
            }
            return -1;
        }
};
