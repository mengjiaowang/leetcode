class Solution {
    public:
        string convert(string s, int nRows)
        {
            if(nRows == 1) return s;
            string result;
            result.reserve(s.size());
            int index = 0;
            while(index < s.size()){
                result.push_back(s[index]);
                index += (nRows+nRows-2);
            }

            for(int i = 1; i != nRows-1; ++i){
                index = i;
                while(index < s.size()){
                    result.push_back(s[index]);
                    int tmpIndex = index + (2*(nRows-i-1));
                    if(tmpIndex < s.size())
                        result.push_back(s[tmpIndex]);
                    index += (nRows+nRows-2);
                }
            }

            index = nRows - 1;
            while(index < s.size()){
                result.push_back(s[index]);
                index += (nRows+nRows-2);
            }
            return result;
        }
};
