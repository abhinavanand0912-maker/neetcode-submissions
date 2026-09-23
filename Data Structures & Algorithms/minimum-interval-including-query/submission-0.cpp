class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(),intervals.end());
        vector<pair<int,int>> q;
        for(int i=0;i<queries.size();i++){
            q.push_back({queries[i],i});
        }
        sort(q.begin(),q.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> ans(queries.size(),-1);
        int i=0;
        for (auto &[query, index] : q){
        while(i<intervals.size() && intervals[i][0]<=query){
            int start=intervals[i][0];
            int end=intervals[i][1];
            int size=end-start+1;
            pq.push({size,end});
            i++;
        }
        while(!pq.empty() && pq.top().second<query){
            pq.pop();
        }
        if(!pq.empty()){
            ans[index]=pq.top().first;
        }
        }
        return ans;
    }
};
