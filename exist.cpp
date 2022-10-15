class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        for(int i =0;i<rows ; i++){
            for(int j =0; j < cols; j++){
                if(dfs(board,word,i,j, 0)) return true;
            }
        }
        return false;
    }

private:
    int rows, cols;
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k){
        if(i>=rows || i<0 || j>=cols || j<0 || board[i][j] != word[k]) 
            return false;
        if(k == word.size()-1) return true;
        board[i][j] = '\0';
        bool res = dfs(board, word, i+1, j, k+1) || dfs(board, word, i-1, j, k+1) || dfs(board, word, i, j+1, k+1) || dfs(board, word, i, j-1, k+1);
        // int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        // for (int q = 0; q < 4; q ++ ) {
        //     int m = i + dx[q], n = j + dy[q];
        //     if (dfs(board, word, m, n, k + 1)) return true;
        // }
        board[i][j] = word[k];
        return res;
    }
};