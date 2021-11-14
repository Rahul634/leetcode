class Solution {
public:
    bool backtracking(vector<vector<char>> &board, int row, int col, string word, int pos) {
        if(pos == word.length()) return true;
        if(row >= board.size() || row < 0 || col < 0 || col >= board[0].size() || board[row][col] !=word[pos]) return false;
        char temp = board[row][col];
        board[row][col] = '*';
        if(backtracking(board, row, col+1, word, pos+1) || backtracking(board, row, col-1, word, pos+1) || backtracking(board, row+1, col, word, pos+1)
          || backtracking(board, row-1, col, word, pos+1)) return true;
        board[row][col] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int pos = 0;
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(word[0] == board[i][j]){
                    if(backtracking(board, i, j, word, pos) == true) return true;
                }
            }
        }
        return false;
    }
};