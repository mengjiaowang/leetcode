class Solution {
    public:
        string addBinary(string a, string b) {
            int i = a.length() - 1, j = b.length() - 1;
            string res; 
            bool flag = false;

            while(i >= 0 && j >= 0){
                if(a[i] == '0' && b[j] == '0' && flag == false)
                    res.push_back('0');
                else if(a[i] == '0' && b[j] == '0' && flag == true){
                    res.push_back('1'); flag = false;
                }
                else if(a[i] == '0' && b[j] == '1' && flag == false)
                    res.push_back('1');
                else if(a[i] == '0' && b[j] == '1' && flag == true)
                    res.push_back('0');
                else if(a[i] == '1' && b[j] == '0' && flag == false)
                    res.push_back('1');
                else if(a[i] == '1' && b[j] == '0' && flag == true)
                    res.push_back('0');
                else if(a[i] == '1' && b[j] == '1' && flag == false){
                    res.push_back('0'); flag = true;
                }
                else if(a[i] == '1' && b[j] == '1' && flag == true)
                    res.push_back('1');
                i --; j --;
            }
            while(i >= 0){
                if(a[i] == '0' && flag == false)
                    res.push_back('0');
                else if(a[i] == '0' && flag == true){
                    res.push_back('1'); flag = false;
                }
                else if(a[i] == '1' && flag == false)
                    res.push_back('1');
                else if(a[i] == '1' && flag == true)
                    res.push_back('0');
                i --;
            }
            while(j >= 0){
                if(b[j] == '0' && flag == false)
                    res.push_back('0');
                else if(b[j] == '0' && flag == true){
                    res.push_back('1'); flag = false;
                }
                else if(b[j] == '1' && flag == false)
                    res.push_back('1');
                else if(b[j] == '1' && flag == true)
                    res.push_back('0');
                j --;
            }
            if(flag == true)
                res.push_back('1');
            std::reverse(res.begin(), res.end());
            return res;
        }
};
