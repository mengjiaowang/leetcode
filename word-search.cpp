class Solution {
    public:
        bool exist(vector<vector<char> > &board, string word) {
            vector<vector<bool> > visited;
            visited.resize(board.size());
            for(int i = 0; i != board.size(); ++i){
                visited[i].resize(board[i].size());
                std::fill(visited[i].begin(), visited[i].end(), 0);
            }
            return exist(board, visited, word, 0);
        }

        bool exist(vector<vector<char> > &board, vector<vector<bool> > &visited, 
                string &word, int index, int prei = 0, int prej = 0){
            if(index == word.size()) return true;
            if(index == 0){
                for(int i = 0; i != board.size(); ++i){
                    for(int j = 0; j != board[i].size(); ++j){
                        if(visited[i][j] == 0 && board[i][j] == word[index]){
                            visited[i][j] = 1;
                            bool res = exist(board, visited, word, index+1, i, j);
                            if(res == true) return true;
                            visited[i][j] = 0;
                        }
                    }
                }
            }else{
                if(prei - 1 >= 0){
                    if(visited[prei-1][prej] == 0 && board[prei-1][prej] == word[index]){
                        visited[prei-1][prej] = 1;
                        bool res = exist(board, visited, word, index+1, prei-1, prej);
                        visited[prei-1][prej] = 0;
                        if(res == true) return true;
                    }
                }
                if(prei + 1 < board.size()){
                    if(visited[prei+1][prej] == 0 && board[prei+1][prej] == word[index]){
                        visited[prei+1][prej] = 1;
                        bool res = exist(board, visited, word, index+1, prei+1, prej);
                        visited[prei+1][prej] = 0;
                        if(res == true) return true;
                    }                
                }
                if(prej - 1 >= 0){
                    if(visited[prei][prej-1] == 0 && board[prei][prej-1] == word[index]){
                        visited[prei][prej-1] = 1;
                        bool res = exist(board, visited, word, index+1, prei, prej-1);
                        visited[prei][prej-1] = 0;
                        if(res == true) return true;
                    }
                }
                if(prej + 1 < board[prei].size()){
                    if(visited[prei][prej+1] == 0 && board[prei][prej+1] == word[index]){
                        visited[prei][prej+1] = 1;
                        bool res = exist(board, visited, word, index+1, prei, prej+1);
                        visited[prei][prej+1] = 0;
                        if(res == true) return true;
                    }                
                }
            }
            return false;
        }
};
