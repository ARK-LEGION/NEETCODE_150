class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m=tasks.size();
        vector<int> freq(26);
        int maxi=0;
        for (int i=0; i<m; i++){
            freq[tasks[i]-'A']++;
            maxi=max(maxi,freq[tasks[i]-'A']);
        }
        int c=0;
        for (int i=0; i<26; i++){
            if (freq[i]==maxi) c++;
        }
        return max((maxi-1)*(n+1) + c, (int)tasks.size());
    }
};
