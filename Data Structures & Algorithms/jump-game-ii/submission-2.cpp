class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int j=0;
        vector<int> parent(n);
        parent[0]=-1;
        for (int i=0; i<n; i++){
            while (j<i && j+nums[j]<i){
                j++;
            }
            if (i>0)parent[i]=j;
        }
        int i=n-1;
        int ans=0;
        while(parent[i]!=-1){
            i=parent[i];
            ans++;
        }
        return ans;
    }
};
