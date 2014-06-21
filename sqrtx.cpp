class Solution {
    public:
        int sqrt(int x) {
            double res = 1;
            for(int i = 0; i != 1000; ++i){
                res = 0.5 * (res + x/res);
            }
            return (int)res;
        }
};
