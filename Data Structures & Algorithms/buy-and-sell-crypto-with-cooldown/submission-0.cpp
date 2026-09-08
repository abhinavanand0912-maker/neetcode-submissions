class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold=-prices[0];
        int sold=0;
        int rest=0;
        for(int i=1;i<prices.size();i++){
            int newhold=max(hold,rest-prices[i]);
            int newsold=hold+prices[i];
            int newrest=max(rest,sold);
            hold=newhold;
            sold=newsold;
            rest=newrest;
        }
        return max(sold,rest);
    }
};