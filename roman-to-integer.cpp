class Solution {
    public:
        int romanToInt(string s) {
            map<char, int> mapRoman;
            mapRoman['I'] = 1;
            mapRoman['V'] = 5;
            mapRoman['X'] = 10;
            mapRoman['L'] = 50;
            mapRoman['C'] = 100;
            mapRoman['D'] = 500;
            mapRoman['M'] = 1000;

            int res = 0, symbol = 1;

            for(int i = s.size() - 1; i >= 0; --i){
                if(i < s.size() - 1){
                    if(mapRoman[s[i]] >= mapRoman[s[i+1]]) symbol = 1;
                    else symbol = -1;
                }
                res += (symbol * mapRoman[s[i]]);
            }
            return res;       
        }
};
