class Solution {
    public:
        void appendSpace(string &str, int num)
        {
            for(int i = 0; i != num; ++i) str.push_back(' ');
        }

        string fitLine(vector<string> &words, int start, int end, int length, int L, bool fitleft)
        {
            int space = L - length;
            int word = end - start + 1;
            if(word == 1)
            {
                string tmp = words[start];
                appendSpace(tmp, space);
                return tmp;
            }
            else
            {
                string tmp(words[start]);
                if(fitleft == false)
                {
                    int div = space/(word-1);
                    int rem = space%(word-1);
                    for(int i = 0; i != word - 1; ++i)
                    {
                        if(rem == 0) appendSpace(tmp, div);
                        else
                        {
                            appendSpace(tmp, div+1);
                            rem --;
                        }
                        tmp.append(words[start+i+1]);
                    }
                }
                else
                {
                    for(int i = 0; i != word - 1; ++i)
                    {
                        tmp.push_back(' ');
                        tmp.append(words[start+i+1]);
                    }
                    appendSpace(tmp, space-word+1);
                }
                return tmp;
            }
        }

        vector<string> fullJustify(vector<string> &words, int L)
        {
            vector<string> result;
            if(words.size() == 0)
            {
                string tmp;
                appendSpace(tmp, L);
                result.push_back(tmp);
                return result;
            }
            int start = 0, cur = 0;
            int length = 0;
            while(cur < words.size())
            {
                length += words[cur].size();
                if(length + cur - start <= L) ++cur;
                else
                {
                    result.push_back(fitLine(words, start, cur-1, length-words[cur].size(), L, false));
                    length = 0;
                    start = cur;
                }
            }
            result.push_back(fitLine(words, start, cur-1, length, L, true));

            return result;
        }
};
