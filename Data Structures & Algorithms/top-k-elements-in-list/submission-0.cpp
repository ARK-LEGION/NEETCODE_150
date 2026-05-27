class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        vector<int> temp(2e3 + 1 , 0);
        for  (int i=0; i<n; i++){
            temp[nums[i]+1e3]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for (int i=0; i<=2e3; i++){
            if (temp[i]>0){
                if (pq.size()<k)pq.push({temp[i],i-1e3});
                else{
                    if (temp[i]>pq.top().first){
                        pq.pop();
                        pq.push({temp[i], i-1e3});
                    }
                }
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};