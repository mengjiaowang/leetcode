class Solution {
    public:
        int longestValidParentheses(string s) {
            int length = 0;
            if(s.size() == 0) return length;
            int *arr = new int[s.size()];
            memset((void*)arr, 0, sizeof(int)*s.size());

            for(int i = 1; i != s.size(); ++i){
                if(s[i] == '('') continue;
                int j = i - arr[i-1] - 1;
                if(j >= 0 && s[j] == '(''){
                    arr[i] = arr[i-1] + 2;
                    if(j > 0) {
                        arr[i] += arr[j-1];
                    }
                    length = max(length, arr[i]);
                }
                }
                delete []arr;
                return length;
        }
};
