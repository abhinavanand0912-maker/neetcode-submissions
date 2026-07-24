class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int index, int r, int c){
        if(index==word.size()) return true;
        if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size()) return false;
        if(board[r][c]!=word[index]) return false;
        char temp = board[r][c];
        board[r][c] = '#';

        bool found = dfs(board, word, index+1, r+1, c) ||
                     dfs(board, word, index+1, r-1, c) ||
                     dfs(board, word, index+1, r, c+1) ||
                     dfs(board, word, index+1, r, c-1);
        board[r][c] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(dfs(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }
};
