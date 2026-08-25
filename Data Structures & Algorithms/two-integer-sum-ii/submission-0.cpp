class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> sum;
        int start=0;
        int end=numbers.size()-1;
        while(start<end){
            int ans=(numbers[start]+numbers[end]);
            if(ans==target){
                sum.push_back(start+1);
                sum.push_back(end+1);
                break;
            }
            else if(ans>target){
                end--;
            } else {
                start++;
            }
        }
        return sum;
    }
};
