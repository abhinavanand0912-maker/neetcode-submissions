class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<int>& vis,int k){
        if(vis[k]==1) return true;
        else if(vis[k]==2) return false;
        vis[k]=1;

        for(auto neigh : graph[k]){
            if(dfs(graph,vis,neigh)) return true;
        }
        vis[k]=2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto &p : prerequisites){
            int a=p[0];
            int b=p[1];
            graph[b].push_back(a);
        }
        vector<int> vis(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(dfs(graph,vis,i)) return false;
        }
        return true;

    }
};
