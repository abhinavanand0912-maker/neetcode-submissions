class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int, vector<int>>>
> pq;
        for(auto &point : points){
            int x = point[0];
            int y = point[1];
            int d = x*x + y*y;
            pq.push({d, point});
        }
        int cnt=0;
        vector<int> curr; 
        while(cnt!=k){
            curr=pq.top().second;
            cnt++;
            ans.push_back(curr);
            pq.pop();
        }
        return ans;
    }
};
