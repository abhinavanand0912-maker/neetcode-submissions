class Solution {
public:
    string multiply(string num1, string num2) {
        int n=num1.size();
        int m=num2.size();
        vector<int> ans(n+m,0);
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int k = (num1[i] - '0') * (num2[j] - '0');
                ans[i + j + 1] += k;
            }
        }
        for(int i=n+m-1;i>0;i--){
            if(ans[i]>=10){
                int rem=ans[i]%10;
                int carry=ans[i]/10;
                ans[i-1]=carry+ans[i-1];
                ans[i]=rem;
            }
        }
        int i=0;
        while (i < n + m - 1 && ans[i] == 0) i++;
        string result="";
        while(i<ans.size()){
            result+=ans[i]+'0';
            i++;
        }
        return result;
    }
};
