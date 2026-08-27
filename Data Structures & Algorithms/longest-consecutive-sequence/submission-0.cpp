class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int ans=0;
        for(int x : st){
            if(!st.count(x-1)){
                int curr=x;
                int cnt=1;
                while(st.count(curr+1)){
                    curr++;
                    cnt++;
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};
