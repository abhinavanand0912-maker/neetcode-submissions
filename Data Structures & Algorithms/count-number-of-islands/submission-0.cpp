class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    count++;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vis[i][j]=true;
                    while(!q.empty()){
                        auto [r,c]=q.front();
                        q.pop();
                        for(int k=0;k<4;k++){
                            int nr=r+dr[k];
                            int nc=c+dc[k];
                            if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]=='1' && !vis[nr][nc]){
                                vis[nr][nc]=true;
                                q.push({nr,nc});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};
