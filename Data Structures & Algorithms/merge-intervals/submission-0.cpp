class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int n=intervals.size();
        int start=intervals[0][0];
        int end=intervals[0][1];
        for(int i=0;i<n;i++){
            int newstart=intervals[i][0];
            int newend=intervals[i][1];
            if(newstart<=end){
                end=max(newend,end);
            } else {
                ans.push_back({start,end});
                start=newstart;
                end=newend;
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};
