class Solution {
    public:
        bool isValidSudoku(vector<vector<char> > &board) {
            int flag [9];

            for(int i = 0; i != 9; ++i){
                memset((void*)flag, 0, 4*9);
                for(int j = 0; j != 9; ++j){
                    if(board[i][j] >= '1' && board[i][j] <= '9'){
                        if(flag[board[i][j]-'1'] == 1) return false;
                        else flag[board[i][j]-'1'] = 1;
                    }
                }
            }

            for(int i = 0; i != 9; ++i){
                memset((void*)flag, 0, 4*9);
                for(int j = 0; j != 9; ++j){
                    if(board[j][i] >= '1' && board[j][i] <= '9'){
                        if(flag[board[j][i]-'1'] == 1) return false;
                        else flag[board[j][i]-'1'] = 1;
                    }
                }
            }       

            for(int starti = 0; starti != 9; starti += 3){
                for(int startj = 0; startj != 9; startj += 3){
                    memset((void*)flag, 0, 4*9);
                    for(int i = starti; i != starti + 3; ++i){
                        for(int j = startj; j != startj + 3; ++j){
                            if(board[j][i] >= '1' && board[j][i] <= '9'){
                                if(flag[board[j][i]-'1'] == 1) return false;
                                else flag[board[j][i]-'1'] = 1;
                            }   
                        }
                    }
                }
            }
            return true;
        }
};
