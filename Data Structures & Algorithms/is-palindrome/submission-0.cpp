class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int j=n-1;
        for (int i=0; i<=j; i++){
            if (s[i]>='A' && s[i]<='Z'){
                s[i] = (char)tolower(s[i]);
            }
            if (s[j]>='A' && s[j]<='Z'){
                s[j] = (char)tolower(s[j]);
            }
            if (!((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))) continue;
            while (j>=i && !((s[j]>='a' && s[j]<='z')|| (s[j]>='A' && s[j]<='Z') || (s[j]>='0' && s[j]<='9'))){
                s[j] = (char)tolower(s[j]);
                j--;
            }
            s[j] = (char)tolower(s[j]);
            if (s[i]!=s[j]) return false;
            j--;
        }
        return true;
    }
};
