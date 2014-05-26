#include<vector>

class Solution {
    public:
        void reverseWords(string &s) {
            string rs;
            for(int i = s.length() - 1; i >=0; i --)
            {
                while(i>=0 && s[i]==' ') i--;
                if(i<0) break;
                if(!rs.empty()) rs.push_back(' ');
                string t;
                while(i >=0 && s[i] != ' ') t.push_back(s[i--]);
                std::reverse(t.begin(), t.end());
                rs.append(t);
            }
            s = rs;

        }
};
