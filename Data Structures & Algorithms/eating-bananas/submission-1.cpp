class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int n=piles.size();
        int right=piles[n-1];
        int left = 1;
        while(left<right){
            int mid=(left+right)/2;
            int k=0;
            for(int i=0;i<n;i++){
                k += ceil((double)piles[i] / mid);  
            }
            if(k<=h) right=mid;
            else left=mid+1;
            
        }
        return left;
    }
};
