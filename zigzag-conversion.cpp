class Solution {
    public:
        string convert(string s, int nRows)
        {
            if(nRows == 1) return s;
            string result;
            result.reserve(s.size());
            for(int i = 0; i != nRows; ++i){
                int index = i;
                while(index < s.size()){
                    result.push_back(s[index]);
                    if(i != 0 && i != nRows-1){
                        int tmpIndex = index + (2*(nRows-i-1));
                        if(tmpIndex < s.size())
                            result.push_back(s[tmpIndex]);
                    }
                    index += (nRows+nRows-2);
                }
            }
            return result;
        }
};
