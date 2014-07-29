class Solution {
    public:
        int minDistance(string word1, string word2) {
            if(word1.size() == 0) return word2.size();
            if(word2.size() == 0) return word1.size();
            vector<vector<int> > num;
            num.resize(word1.size()+1);
            for(int i = 0; i != word1.size() + 1; ++i){
                num[i].resize(word2.size() + 1);   
            }
            for(int i = 0; i != word1.size() + 1; ++i){
                num[i][0] = i;
            }
            for(int j = 0; j != word2.size() + 1; ++j){
                num[0][j] = j;
            }

            for(int i = 1; i != word1.size() + 1; ++i){
                for(int j = 1; j != word2.size() + 1; ++j){
                    int ins = num[i-1][j] + 1;
                    int del = num[i][j-1] + 1;
                    int rep = num[i-1][j-1];
                    if(word1[i-1] != word2[j-1]) rep += 1;
                    num[i][j] = min(ins, del, rep);
                }
            }
            return num[word1.size()][word2.size()];
        }

        int min(int a, int b, int c){
            if(a <= b && a <= c) return a;
            else if(b <= a && b <= c) return b;
            else if(c <= a && c <= b) return c;
        }
};
