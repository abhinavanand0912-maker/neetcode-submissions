class Solution {
public:
    int reverse(int x) {
        int rev=0;
        while(x){
            int r=x%10;
            x=x/10;
            if(INT_MAX/10<rev || (INT_MAX/10==rev && r>7)) return 0;
            if(INT_MIN/10>rev || (INT_MIN/10==rev && r<-8)) return 0;
            rev=rev*10+r;
        }
        return rev;
    }
};
