class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int maxLength = 0;
            int substring[256];

            memset((void*)substring, 0, 256*4);

            for(int i = 0; i != s.size(); ++i)
            {
                for(int j = i; j != s.size(); ++j)
                {
                    if(substring[s[j]] == 1)
                    {
                        int length = 0;
                        for(int k = 0; k != 256; ++ k)
                        {
                            if(substring[k]) length ++;
                        }
                        if(length > maxLength) maxLength = length;
                        memset(substring, 0, 256*4);
                        break;
                    }
                    else
                    {
                        substring[s[j]] = 1;
                    }
                }
            }
            int length = 0;
            for(int k = 0; k != 256; ++ k)
            {
                if(substring[k]) length ++;
            }
            if(length > maxLength) maxLength = length;            
            return maxLength;
        }
};
