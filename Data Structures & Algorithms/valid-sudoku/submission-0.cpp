class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row[9];
        unordered_set<char> col[9];
        unordered_set<char> box[9];
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                char ch=board[i][j];
                if(ch=='.') continue;
                int b=3*(i/3)+(j/3);
                if(row[i].count(ch) || col[j].count(ch) || box[b].count(ch)){
                    return false;
                }
                row[i].insert(ch);
                col[j].insert(ch);
                box[b].insert(ch);
            }
        }
        return true;
    }
};
