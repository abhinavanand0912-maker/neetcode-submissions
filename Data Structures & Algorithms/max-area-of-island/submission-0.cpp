class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};
        vector<int> ans;
        int area;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vis[i][j]=true;
                    area=1;
                    while(!q.empty()){
                        auto [r,c]=q.front();
                        q.pop();
                        for(int k=0;k<4;k++){
                            int nr=r+dr[k];
                            int nc=c+dc[k];
                            if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc]==1){
                                area++;
                                q.push({nr,nc});
                                vis[nr][nc]=true;
                            }
                        }
                    }
                    ans.push_back(area);
                }
            }
        }
        int z=0;
        if(ans.size()){
            for(int f : ans){
                z=max(z,f);
            }
        }
        return z;
    }
};