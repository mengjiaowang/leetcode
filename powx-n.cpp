class Solution {
    public:
        double pow(double x, int n) {
            double res = 1;
            for(int i = 0; i != n; ++i){
                res *= x;
            }
            return res;
        }
};
