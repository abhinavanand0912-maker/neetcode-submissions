class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int lh=0;
        int rh=n-1;
        int lmax=0;
        int rmax=0;
        int total=0;
        while(lh<rh){
            if(height[lh]<=height[rh]){
                if(lmax>height[lh]){
                    total+=lmax-height[lh];
                } else {
                    lmax=height[lh];
                }
                lh++;
            } else {
                if(rmax>height[rh]){
                    total+=rmax-height[rh];
                } else {
                    rmax=height[rh];
                }
                rh--;
            }
        }
        return total;
    }
};
