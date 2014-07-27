class Solution {
    public:
        double pow(double x, int n) {
            double res = 1;
            bool flag = false;
            if(n < 0){
                n = (-1)*n;
                flag = true;
            } 
            for(int i = 0; i != n; ++i){
                res *= x;
            }
            if(flag == false)
                return res;
            else return 1/res;
        }
};
