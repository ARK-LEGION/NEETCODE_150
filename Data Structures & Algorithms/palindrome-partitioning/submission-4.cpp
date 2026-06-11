class Solution {
public:
    void helper(int i, vector<string>& cur, string& s, vector<vector<string>>& ans, vector<vector<int>>& isPalindrome){
        int n = s.size();
        if (i >= n){
            ans.push_back(cur);
            return;
        }
        
        for (int k = i; k < n; k++){
            if (isPalindrome[i][k]){
                cur.push_back(s.substr(i, k - i + 1));
                helper(k + 1, cur, s, ans, isPalindrome);
                cur.pop_back(); 
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<int>> isPalindrome(n, vector<int>(n,0));
for (int i = n - 1; i >= 0; i--) {
    isPalindrome[i][i] = 1; // Single characters
    for (int j = i + 1; j < n; j++) {
        if (s[i] == s[j]) {
            isPalindrome[i][j] = (i + 1 <= j - 1) ? isPalindrome[i + 1][j - 1] : 1;
        } else {
            isPalindrome[i][j] = 0;
        }
    }
}
        vector<vector<string>> ans;
        vector<string> cur;
        helper(0,cur,s,ans,isPalindrome);
        return ans;
    }
};
