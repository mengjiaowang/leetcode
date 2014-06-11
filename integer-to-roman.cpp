class Solution {
    public:
        string intToRoman(int num) {
            string map[4][10] = {{"I","II","III","IV","V","VI","VII","VIII","IX","X"},
                {"X","XX","XXX","XL","L","LX","LXX","LXXX","XC","C"},
                {"C","CC","CCC","CD","D","DC","DCC","DCCC","CM","M"},
                {"M","MM","MMM"}};
            int count = 0;
            vector<string> resVec; string res = "";
            while(num != 0){
                int digit = num % 10;
                if(digit != 0) resVec.push_back(map[count][digit-1]);
                count ++;
                num /= 10;
            }
            for(int i = resVec.size() - 1; i >= 0; --i){
                res += resVec[i];
            }
            return res;
        }
};
