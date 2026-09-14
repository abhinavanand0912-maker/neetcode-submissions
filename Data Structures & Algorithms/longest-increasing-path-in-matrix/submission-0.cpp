class Solution {
public:
    int m,n;
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>& matrix,int r,int c){
        if (dp[r][c] != -1) return dp[r][c];
        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};
        int ans=1;
        for(int k=0;k<4;k++){
            int nr=r+dr[k];
            int nc=c+dc[k];
            if(nr>=0 && nc>=0 && nr<m && nc<n && matrix[nr][nc]>matrix[r][c]){
                ans=max(ans,1 + dfs(matrix, nr, nc));
            }
        }
        dp[r][c] = ans;
        return ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
        dp.assign(m,vector<int>(n,-1));
        int ans=0;
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                ans=max(ans,dfs(matrix,r,c));
            }
        }
        return ans;
    }
};
