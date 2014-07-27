class Solution {
    public:
        int atoi(const char *str) {
            int n = strlen(str);
            long long res = 0, factor = 1, i = n - 1;
            if(n > 0){
                while(i >= 0){
                    if(isdigit(str[i])){
                        res += (str[i]-'0') * factor;
                        factor *= 10;
                    }else if(str[i] == '-' || str[i] == '+' || str[i] == ' '){
                        char chr = str[i];
                        i--;
                        while(str[i] == ' ' && i >= 0) --i;
                        if(i == -1){
                            if(chr == '-') res *= -1;
                        }
                        else{
                            res = 0; factor = 1; i++;
                        };
                    }
                    else{
                        res = 0; factor = 1;
                    } 
                    --i;
                }
            }
            int max = std::numeric_limits<int>::max();
            int min = std::numeric_limits<int>::min();
            if(res > max) return max;
            if(res < min) return min;
            return res;
        }
};
