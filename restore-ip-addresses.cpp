class Solution {
    public:
        vector<string> restoreIpAddresses(string s) {
            vector<string> result;
            if(s.size() < 4 || s.size() > 12) return result;
            for(int i = 0; i != s.size() - 2 && i != 3; ++i){
                for(int j = i + 1; j != s.size() - 1 && j != i + 4; ++j){
                    for(int k = j + 1; k != s.size() && k != j + 4; ++k){
                        int firstLen = i - 0 + 1;
                        int secondLen = j - i;
                        int thirdLen = k - j;
                        int forthLen = s.size() - k - 1;
                        if(firstLen < 4 && secondLen < 4 && thirdLen < 4 && forthLen < 4 && forthLen > 0){
                            int first = atoi(s.substr(0, firstLen).c_str());
                            if(first > 255) continue;
                            int second = atoi(s.substr(firstLen, secondLen).c_str());
                            if(second > 255) continue;
                            int third = atoi(s.substr(firstLen+secondLen, thirdLen).c_str());
                            if(third > 255) continue;
                            int forth = atoi(s.substr(firstLen+secondLen+thirdLen, forthLen).c_str());
                            if(forth > 255) continue;

                            if(firstLen > 1 && s[0] == '0') continue;
                            if(secondLen > 1 && s[firstLen] == '0') continue;
                            if(thirdLen > 1 && s[firstLen+secondLen] == '0') continue;
                            if(forthLen > 1 && s[firstLen+secondLen+thirdLen] == '0') continue;

                            string tmp = s.substr(0, firstLen) + "." + s.substr(firstLen, secondLen) + "." +
                                s.substr(firstLen+secondLen, thirdLen) + "." + s.substr(firstLen+secondLen+thirdLen, forthLen);
                            result.push_back(tmp);
                        }
                    }
                }
            }
            return result;
        }
};
