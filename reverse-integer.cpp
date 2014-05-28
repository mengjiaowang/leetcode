class Solution {
    public:
        int reverse(int x) {
            bool negative = false;
            int result = 0;
            if(x < 0){ negative = true; x = x * (-1);}
            while(x != 0){
                int d = x % 10;
                result = result * 10 + d;
                x = x / 10;
            }
            if(negative == true) return result * (-1);
            else return result;
        }
};
