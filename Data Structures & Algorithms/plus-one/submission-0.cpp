class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n= digits.size();
        vector<int> ans(n);
        int carry=1;
        for (int i=n-1; i>=0; i--){
            ans[i] = digits[i]+carry;
            if (ans[i]>=10){
                ans[i]%=10;
                carry = 1;
            }
            else carry=0;
        }
        if (carry==1){
            ans.insert(ans.begin(), 1);
        }
        return ans;
    }
};
