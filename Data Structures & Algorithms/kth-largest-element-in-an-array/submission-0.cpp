class Solution {
public:
    int partition(int left,vector<int>& nums,int right){
        int pivot=nums[right];
        int i=left;
        for(int j=left;j<right;j++){
            if(nums[j]>pivot){
                swap(nums[i],nums[j]);
                i++;
            }
        }
        swap(nums[i],nums[right]);
        return i;    
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size()-1;
        int left=0;
        int right=n;
        int target=k-1;
        while(left<=right){
            int pi=partition(left,nums,right);
            if(pi==target) return nums[pi];
            else if(pi>target) right=pi-1;
            else left=pi+1;
        }
        return 0;

    }
};
