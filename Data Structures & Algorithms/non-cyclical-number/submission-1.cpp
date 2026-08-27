class Solution {
public:
    int  sum(int n){
        int k=0;
        while(n>0){
            int r=n%10;
            k+=r*r;
            n=n/10;

        }
        return k;
    }
    bool isHappy(int n) {
        if(n<=0) return false;
        unordered_set<int> st;
        while (n != 1) {
            if (st.count(n))
                return false;
            st.insert(n);
            n = sum(n);
        }
        return true;
    }
};
