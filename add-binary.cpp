class Solution {
    public:
        string addBinary(string a, string b) {
            string::size_type m, n, max; 
            m = a.size(); n = b.size();
            max = (m > n) ? m : n;
            int carry = 0; string res;
            res.reserve(max + 1);

            for(string::size_type i = 0; i != max; ++i){
                int p = (i < m) ? a[m - 1 - i] - '0' : 0;
                int q = (i < n) ? b[n - 1 - i] - '0' : 0;
                int tmp = p + q + carry;
                carry = tmp >> 1;
                if(tmp & 1) res.push_back('1');
                else res.push_back('0');
            }
            if(carry) res.push_back('1');

            std::reverse(res.begin(), res.end());
            return res;
        }
};
