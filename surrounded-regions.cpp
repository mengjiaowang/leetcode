class Solution {
    public:
        void solve(vector<vector<char> > &board) {
            int height = board.size();
            if(height == 0) return;
            int width = board[0].size();
            if(height == 1 || width == 1) return;

            bool *visited = new bool[height*width];
            memset((void*)visited, false, sizeof(bool)*height*width);
            queue<int> q;
            for(int i = 0; i != height; ++i) {
                if(board[i][0] == 'O'){
                    int index = i*width;
                    q.push(index); 
                    visited[index] = true;
                }
            }
            for(int i = 0; i != height; ++i){
                if(board[i][width-1] == 'O') {
                    int index = i*width+width-1; 
                    q.push(index);
                    visited[index] = true;
                }
            }
            for(int i = 1; i < width - 1; ++i) {
                if(board[0][i] == 'O'){
                    int index = i;
                    q.push(index);
                    visited[index] = true;
                }
            }
            for(int i = 1; i < width - 1; ++i){
                if(board[height-1][i] == 'O'){
                    int index = (height - 1)*width+i;
                    q.push(index);
                    visited[index] = true;
                }
            }
            while(!q.empty())
            {
                int i = q.front()/width;
                int j = q.front()%width;
                if(i-1 > 0 && visited[(i-1)*width+j] == false && board[i-1][j] == 'O'){
                    visited[(i-1)*width+j] = true; q.push((i-1)*width+j);
                }
                if(i+1 < height && visited[(i+1)*width+j] == false && board[i+1][j] == 'O'){
                    visited[(i+1)*width+j] = true; q.push((i+1)*width+j);
                }
                if(j-1 > 0 && visited[i*width+j-1] == false && board[i][j-1] == 'O'){
                    visited[i*width+j-1] = true; q.push(i*width+j-1);
                }
                if(j+1 < width && visited[i*width+j+1] == false && board[i][j+1] == 'O'){
                    visited[i*width+j+1] = true; q.push(i*width+j+1);
                }
                q.pop();
            }

            for(int i = 0; i != height; ++i){
                for(int j = 0; j != width; ++j){
                    if(visited[i*width+j]==false && board[i][j] == 'O') board[i][j] = 'X';
                }
            }
        }
};
