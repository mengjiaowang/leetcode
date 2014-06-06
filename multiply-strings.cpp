class Solution {
    public:
        string multiply(string num1, string num2) {

            std::vector<int> res(num1.size() + num2.size(), 0);
            string mul; mul.reserve(num1.size() + num2.size());
            int n = res.size() - 1;

            for(int i = num1.size() - 1; i >= 0; --i){
                int k = num1.size() - i - 1;
                for(int j = num2.size() - 1; j >=0; --j){
                    res[k++] += (num1[i]-'0') * (num2[j] - '0');
                }
            }

            for(int i = 0; i != n; ++i){
                int tmp = res[n];
                res[n] = (res[i] + tmp) / 10;
                res[i] = (res[i] + tmp) % 10;
            }

            while(res[n] == 0 && n >= 0) n --;

            for(int i = n; i >= 0; --i){
                mul.push_back((char)('0' + res[i]));
            }

            if(mul.size() == 0)
                mul = "0";
            return mul;
        }
};
