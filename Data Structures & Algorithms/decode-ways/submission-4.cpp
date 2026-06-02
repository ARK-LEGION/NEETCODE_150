class Solution {
public:
    int numDecodings(string s) {
        int  n = s.size();
        vector<int> dp(n);
        dp[0]=(s[0]!='0' ? 1 : 0);
        if (n==1) return dp[0];
        if (dp[0]!=0){
            if (s[1]=='0') {
                if (s[0]<='2')dp[1]=1;
            }
            else{
                if (s[0]=='1')dp[1]=2;
                else if (s[0]=='2') {
                    if (s[1]<='6') dp[1]=2;
                    else dp[1]=1;
                }
                else dp[1]=1;
            }
        }
        for (int i=2; i<n; i++){
            if (s[i]!='0'){
                dp[i] = dp[i-1];
                if (s[i-1]=='1'){
                    dp[i]+=dp[i-2];
                }else if (s[i-1]=='2'){
                    if (s[i]<='6') dp[i]+=dp[i-2];
                }
            }
            else{
                dp[i] = ((s[i-1]!='0' && s[i-1]<='2')? dp[i-2] : 0);
            }
            cout<<dp[i];
        }
        return dp[n-1];
    }
};
