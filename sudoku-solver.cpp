class Solution {
    public:
        void solveSudoku(vector<vector<char> > &board) {
            dfs(board, 0); 
            return;
        }

        bool dfs(vector<vector<char> > &board, int pos){
            if(pos == 81) {
                return true;
            };
            int i = pos / 9;
            int j = pos % 9;

            if(board[i][j] == '.'){
                for(char k = '1'; k <= '9'; ++k){
                    board[i][j] = k;
                    if(validBoard(board, i, j) && dfs(board, pos+1)) return true;
                    board[i][j] = '.';
                }
            }
            else{
                if(dfs(board, pos+1)) return true;
            }
            return false;
        }

        bool validBoard(vector<vector<char> > &board, int i, int j){
            for(int k = 0; k != 9; ++k){
                if(board[k][j] == board[i][j] && k != i)  return false;
            }
            for(int k = 0; k != 9; ++k){
                if(board[i][k] == board[i][j] && k != j) return false;
            }
            int r = i/3, c = j/3;
            for(int k = r*3; k != r*3+3; ++k){
                for(int l = c*3; l != c*3+3; ++l){
                    if(board[k][l] == board[i][j] && k != i && l != j) return false;
                }
            }
            return true;
        }

};
