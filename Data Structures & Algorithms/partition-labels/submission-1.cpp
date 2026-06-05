class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<pair<int, int>> x(26,{-1,-1});
        for (int i=0; i<n; i++){
            if (x[s[i]-'a'].first==-1){
                x[s[i]-'a'].first=i;
                x[s[i]-'a'].second=i;
            }
            else{
                x[s[i]-'a'].second=i;
            }
        }
        vector<pair<int,int>> temp;
        for (int i=0; i<26; i++){
            if (x[i].first!=-1){
                temp.push_back(x[i]);
            }
        }
        sort(temp.begin(), temp.end());
        int i=0;
        n=temp.size();
        vector<int> ans;
        while (i<n){
            int maxi=temp[i].second;
            int j=i;
            while (j<n && temp[j].first<=maxi) maxi=max(maxi,temp[j].second),j++;
            j--;
            ans.push_back(maxi-temp[i].first+1);
            i=j+1;
        }
        return ans;
    }
};
