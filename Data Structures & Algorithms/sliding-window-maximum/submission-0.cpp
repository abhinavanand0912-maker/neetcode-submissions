class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> maxm;
        int maxi=INT_MIN;
        int idx=0;
        for(int i=0;i<k;i++){
            if(maxi<nums[i]){
                maxi=nums[i];
                idx=i;
            }
        }
        maxm.push_back(maxi);
        for(int i=k;i<n;i++){
            if(idx >= i - k + 1) { 
                if(nums[i] > nums[idx]) idx = i;
            } else{
                idx=i-k+1;
                for(int j=idx+1;j<=i;j++){
                    if(nums[j] > nums[idx]) idx = j;
                }
            }
            maxm.push_back(nums[idx]);
            
        }
        return maxm;
    }
};
