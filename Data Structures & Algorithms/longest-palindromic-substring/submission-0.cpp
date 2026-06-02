class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int min_i=0,min_j=0;
        vector<vector<int>> isPalindrome(n,vector<int>(n,0));
        for(int i=0; i<n; i++) isPalindrome[i][i]=1;
        for(int i=1; i<n; i++){
            for (int j=i-1; j>=0; j--){
                if (s[i]==s[j]){
                    if (j+1<=i-1)isPalindrome[j][i] = isPalindrome[j+1][i-1];
                    else isPalindrome[j][i]=1;
                    if (isPalindrome[j][i]==1 && i-j+1>min_i-min_j+1){
                        min_i= i;
                        min_j=j;
                    }
                }
            }
        }

        string ans = s.substr(min_j,min_i-min_j+1);
        return ans;
        
        
    }
};
