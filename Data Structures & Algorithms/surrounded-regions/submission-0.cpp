class Solution {
public:
    int m,n;
    int dr[4]={1,-1,0,0};
    int dc[4]={0,0,1,-1};
    void dfs(vector<vector<char>>& ans,vector<vector<char>>& board,int r,int c){
        ans[r][c]='O';
        for(int k=0;k<4;k++){
            int nr=r+dr[k];
            int nc=c+dc[k];
            if(nr>=0 && nc>=0 && nr<m && nc<n && board[nr][nc]=='O' && ans[nr][nc] == 'X'){
                dfs(ans,board,nr,nc);
            }
        }
        return;
    }
    void solve(vector<vector<char>>& board) {
        m=board.size();
        n=board[0].size();
        vector<vector<char>> ans;
        ans.assign(m,vector<char>(n,'X'));
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                dfs(ans,board,i,0);
            }
        }
        for(int i=0;i<n;i++){
            if(board[0][i]=='O'){
                dfs(ans,board,0,i);
            }
        }
        for(int i=0;i<m;i++){
            if(board[i][n-1]=='O'){
                dfs(ans,board,i,n-1);
            }
        }
        for(int i=0;i<n;i++){
            if(board[m-1][i]=='O'){
                dfs(ans,board,m-1,i);
            }
        }
        board=ans;
    }
};
