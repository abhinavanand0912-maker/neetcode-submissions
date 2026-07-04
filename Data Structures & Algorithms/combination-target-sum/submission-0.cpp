class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    void solve(vector<int>& nums, int target,int idx){
        if(target==0){
            ans.push_back(curr);
            return;
        }
        if(idx==nums.size()) return;
        for(int i=idx;i<nums.size();i++){
            if(target-nums[i]>=0){
                curr.push_back(nums[i]);
                solve(nums,target-nums[i],i);
                curr.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        solve(nums,target,0);
        return ans;
    }
};
