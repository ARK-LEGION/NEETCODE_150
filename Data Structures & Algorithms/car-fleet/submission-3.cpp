class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> v;
        int n = position.size();
        for (int i=0; i<n; i++){
            v.push_back({position[i], speed[i]});
        }
        sort(v.begin(), v.end());
        for (int i=0; i<n; i++){
            position[i] = v[i].first;
            speed[i] = v[i].second;
        }
        vector<double> t(n);
        for (int i=0; i<n; i++){
            t[i] = ((double)target - (double)position[i]) / ((double) speed[i]);
        }
        int ans=0;
        stack<int> st;
        vector<int> nge(n,-1);
        for (int i=n-1; i>=0; i--){
            while(!st.empty() && t[i]>t[st.top()]){
                st.pop();
            }
            if (!st.empty())nge[i] = st.top();
            st.push(i);
        }

        for (int i=n-1;i>=0;i--){
            int nxt = nge[i];
            if (nxt==-1) ans++;
        }
        return ans;
    }
};
