class Solution {
    public:
        double pow(double x, int n) {
            double res = 1;
            bool flag = false;
            if(n < 0){
                n = (-1)*n;
                flag = true;
            }

            while(n != 0){
                if(n % 2 != 0) res = res * x;
                x = x * x;
                n = n/2;
            }

            if(flag == false)
                return res;
            else return 1/res;
        }
};
