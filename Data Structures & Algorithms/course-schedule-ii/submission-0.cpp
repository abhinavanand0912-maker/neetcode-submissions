class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto &p: prerequisites){
            int a=p[0];
            int b=p[1];
            graph[b].push_back(a);
            indegree[a]++;
        }
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
                ans.push_back(i);
            }
        }
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            for(auto neigh : graph[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    ans.push_back(neigh);
                    q.push(neigh);
                }
            }
        }
        if(ans.size() == numCourses) return ans;
        return {};
    }
};
