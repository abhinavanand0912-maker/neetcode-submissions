class Solution {
public:
    void dfs(int node,vector<vector<int>>& adj,vector<bool>& vis){
        vis[node]=true;
        for(auto &p : adj[node]){
            if(!vis[p]) dfs(p,adj,vis);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int count=0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(vis[i]==true) continue;
            else { 
                dfs(i,adj,vis);
                count++;
            }
        }
        return count;
    }
};
