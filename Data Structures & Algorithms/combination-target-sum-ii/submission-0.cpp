class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    void solve(vector<int>& candidates, int target,int idx,int n){
        if(target==0) {
            ans.push_back(curr);
            return;
        }
        for(int i=idx;i<n;i++){
            if(i>idx && candidates[i]==candidates[i-1]){
                continue;
            }
            if(candidates[i]>target){
                break;
            }
            curr.push_back(candidates[i]);
            solve(candidates,target-candidates[i],i+1,n);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int n=candidates.size();
        solve(candidates,target,0,n);
        return ans;
    }
};
