class Solution {
    public:
        int findMin(vector<int> &num) {
            int start = 0, end = num.size()-1;
            while(start < end){
                int mid = (start+end)/2;
                if(num[mid] >= num[start] && num[mid] < num[end]) break;
                else if(num[mid] >= num[start] && num[mid] > num[end]) start = mid + 1;
                else if(num[mid] <= num[start] && num[mid] < num[end]) end = mid;
            }
            return num[start];
        }

};
