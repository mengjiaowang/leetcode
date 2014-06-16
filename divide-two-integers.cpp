class Solution {
    public:
        int divide(int dividend, int divisor) {
            int sign = 1;
            if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) sign = -1;
            unsigned int a = dividend > 0 ? dividend : dividend * (-1);
            unsigned int b = divisor  > 0 ? divisor  : divisor  * (-1);
            unsigned int d = b, i = 0, res = 0;
            unsigned int nums[32];
            while(d <= a && d > 0){
                nums[i++] = d;
                d = d << 1;
            }
            i --;
            while(a >= b){
                if(a >= nums[i]){
                    a = a - nums[i];
                    res += (1 << i);
                }
                i--;
            }
            return res*sign;
        }
};

