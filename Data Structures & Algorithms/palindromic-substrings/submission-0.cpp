class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int cnt=0;
        vector<vector<int>> isPalindrome(n,vector<int>(n,0));
        for(int i=0; i<n; i++) isPalindrome[i][i]=1;
        for(int i=1; i<n; i++){
            for (int j=i-1; j>=0; j--){
                if (s[i]==s[j]){
                    if (j+1<=i-1)isPalindrome[j][i] = isPalindrome[j+1][i-1];
                    else isPalindrome[j][i]=1;
                    if (isPalindrome[j][i]==1){
                        cnt++;
                    }
                }
            }
        }   
        return cnt+n;     
    }
};
