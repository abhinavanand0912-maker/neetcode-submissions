class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    void solve(vector<int>& nums,int n,vector<int>& vis){
        if(curr.size()==n){
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<n;i++){
            if(vis[i]==1) continue;
            else {
                curr.push_back(nums[i]);
                vis[i]=1;
                solve(nums,n,vis);
                curr.pop_back();
                vis[i]=0;
            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int> vis(n,0);
        solve(nums,n,vis);
        return ans;
    }
};
