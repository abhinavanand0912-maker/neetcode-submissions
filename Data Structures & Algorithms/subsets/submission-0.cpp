class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    void solve(vector<int>& nums,int n,int idx){
        ans.push_back(curr);
        for(int i=idx;i<n;i++){
            curr.push_back(nums[i]);
            solve(nums,n,i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        solve(nums,n,0);
        return ans;
    }
};
