class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<bool> ans(3);
        for(int i=0;i<triplets.size();i++){
            if(triplets[i][0] > target[0] || triplets[i][1] > target[1] ||triplets[i][2] > target[2]) {
                continue;
            }
            if(triplets[i][0]==target[0] && ans[0]==false){
                ans[0]=true;
            }
            if(triplets[i][1]==target[1] && ans[1]==false){
                ans[1]=true;
            }
            if(triplets[i][2]==target[2] && ans[2]==false){
                ans[2]=true;
            }
        }
        return ans[0] && ans[1] && ans[2];
    }
};
