class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int>> a;
        for (int i=0; i<n; i++)a.push_back({nums[i],i});
        sort(a.begin(), a.end());
        int i=0, j=n-1;
        while (i<j){
            if(a[i].first+a[j].first>target) j--;
            else if (a[i].first+a[j].first<target) i++;
            else return {min(a[i].second,a[j].second),max(a[i].second,a[j].second)};
        }
        return {-1,-1};
    }
};
