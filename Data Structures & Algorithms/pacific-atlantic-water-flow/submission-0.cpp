class Solution {
public:
    int m,n;
    int dr[4]={1,-1,0,0};
    int dc[4]={0,0,1,-1};
    void dfs(vector<vector<int>>& heights,vector<vector<bool>>& vis, int r, int c){
        vis[r][c]=true;
        for(int k=0;k<4;k++){
            int nr=r+dr[k];
            int nc=c+dc[k];
            if(nr < 0 || nr >= m ||
               nc < 0 || nc >= n ||
               vis[nr][nc])
                continue;
            if(heights[nr][nc]>=heights[r][c]) {
                dfs(heights,vis,nr,nc);
            }           
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m=heights.size();
        n=heights[0].size();
        vector<vector<bool>> pacific(m,vector<bool>(n,false));
        vector<vector<bool>> atlantic(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            dfs(heights,pacific,i,0);
        }
        for(int i=0;i<n;i++){
            dfs(heights,pacific,0,i);
        }
        for(int i=0;i<m;i++){
            dfs(heights,atlantic,i,n-1);
        }
        for(int i=0;i<n;i++){
            dfs(heights,atlantic,m-1,i);
        }
        vector<vector<int>> ans;
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(pacific[r][c] && atlantic[r][c]){
                    ans.push_back({r,c});
                }
            }
        }
        return ans;
    }
};
