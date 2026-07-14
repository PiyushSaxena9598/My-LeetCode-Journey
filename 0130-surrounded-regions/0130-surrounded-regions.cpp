class Solution {
public:
    int r, c;
    int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, 1, -1};

    bool valid(int i, int j){
        return i >= 0 && i < r && j >= 0 && j < c;
    }

    void solve(vector<vector<char>>& board) {

        r = board.size();
        c = board[0].size();

        queue<pair<int,int>> q;

        // First row
        for(int j = 0; j < c; j++){
            if(board[0][j] == 'O'){
                q.push({0, j});
                board[0][j] = '#';
            }
        }

        // First column
        for(int i = 0; i < r; i++){
            if(board[i][0] == 'O'){
                q.push({i, 0});
                board[i][0] = '#';
            }
        }

        // Last row
        for(int j = 1; j < c; j++){
            if(board[r-1][j] == 'O'){
                q.push({r-1, j});
                board[r-1][j] = '#';
            }
        }

        // Last column
        for(int i = 1; i < r; i++){
            if(board[i][c-1] == 'O'){
                q.push({i, c-1});
                board[i][c-1] = '#';
            }
        }

        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++){
                int ni = i + row[k];
                int nj = j + col[k];

                if(valid(ni, nj) && board[ni][nj] == 'O'){
                    board[ni][nj] = '#';
                    q.push({ni, nj});
                }
            }
        }

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};