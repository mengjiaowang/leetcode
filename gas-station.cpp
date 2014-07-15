class Solution {
    public:
        int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
            int n = gas.size();
            for(int i = 0; i != gas.size(); ++i){
                int count = n, j = i, left = 0;
                while(count > 0){
                    left += gas[j] - cost[j];
                    if(left < 0) break;
                    ++j;--count;
                    if(j == n) j = 0;
                }
                if(j == i && left >= 0) return i;
            }
            return -1;
        }
};
