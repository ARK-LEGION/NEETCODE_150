class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        string y="0";
        if (num2==y || num1==y) return "0";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        vector<int> a(n+m+2,0);
        for (int i=0; i<n;i++){
            for (int j=0; j<m; j++){
                int v = (num1[i]-'0')*(num2[j]-'0') + a[i+j];
                a[i+j] = v%10;
                a[i+j+1] += v/10;
            }
        }
        int start = m+n+1;
        while (a[start]==0 && start>=0) start--;
        string ans="";
        for (int i=start; i>=0; i--) ans+=(a[i]+'0');
        return ans;
    }
};
