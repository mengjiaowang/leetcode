class Solution {
    public:
        string minWindow(string S, string T)
        {
            if(S.empty() || T.empty()) return "";
            unordered_map<char, int> m;
            unordered_map<char, int>::iterator iter;
            for(int i = 0; i != T.size(); ++i){
                iter = m.find(T[i]);
                if(iter != m.end()){
                    iter->second = iter->second + 1;
                }else{
                    m[T[i]] = 1;
                }
            }
            int minLen = std::numeric_limits<int>::max();
            int minIndex = 0, i = -1, j = 0;
            int count = T.size();
            int size = S.size();
            while(i < size && j < size){
                if(count != 0){
                    ++i;
                    iter = m.find(S[i]);
                    if(iter != m.end()){
                        iter->second = iter->second - 1;
                        if(iter->second >= 0) count --;
                    }
                }else{
                    if(minLen > i - j + 1){
                        minLen = i - j + 1;
                        minIndex = j;
                    }
                    iter = m.find(S[j]);
                    if(iter != m.end()){
                        iter->second = iter->second + 1;
                        if(iter->second > 0) count ++;
                    }
                    ++j;
                }
            }
            if(minLen == std::numeric_limits<int>::max())
                return "";
            else
                return S.substr(minIndex, minLen);
        }
};
