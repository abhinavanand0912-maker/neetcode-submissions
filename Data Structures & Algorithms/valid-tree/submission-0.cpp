class Solution {
public:
    bool dfs(int node,int parent,vector<vector<int>>& adj,vector<bool>& vis){
        vis[node]=true;
        for(int neigh : adj[node]){
            if(neigh==parent) continue;
            if(vis[neigh]) return false;
            if(!dfs(neigh,node,adj,vis)) return false;
        }
        return true;

    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;
        vector<vector<int>> adj(n);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> vis(n,false);
        if(!dfs(0,-1,adj,vis)){
            return false;
        }
        for(bool v : vis){
            if(!v) return false;
        }
        return true;
    }
};
