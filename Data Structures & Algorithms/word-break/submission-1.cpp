class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        int m = wordDict.size();
        vector<int> pre;
        pre.push_back(-1);
        vector<int> dp(n,0);
        for (int i=0; i<n; i++){
            bool f=false;
            for (auto u:pre){
                int start = u+1;
                int end = i;
                int len = end-start+1;
                string str = s.substr(start,len);

                for (auto v:wordDict){
                    if (v==str){
                        f=true;
                        break;
                    }
                }
                if (f) break;
            }
            dp[i]=f;
            if (f) pre.push_back(i);
        }
        return dp[n-1];
    }
};
