class Solution {
    public:
        double pow(double x, int n) {
            double res = 1;
            bool flag = false;
            if(n < 0){
                n = (-1)*n;
                flag = true;
            }

            res = positivePow(x, n);

            if(flag == false)
                return res;
            else return 1/res;
        }

        double positivePow(double x, int n){
            if(n == 0) return 1;
            else if(n == 1) return x;
            else if(n % 2 == 1){
                double tmp = positivePow(x,n/2);
                return x*tmp*tmp;
            }
            else{
                double tmp = positivePow(x,n/2);
                return tmp*tmp;            
            }
        }
};
