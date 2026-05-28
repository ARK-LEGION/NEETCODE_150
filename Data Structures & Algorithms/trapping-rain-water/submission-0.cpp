class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int i=0, j=n-1;
        int m1=0, m2=0;
        int ans=0;
        while (i<j){
            if (height[i]<height[j]){
                m1=max(m1,height[i]);
                ans+=min(m1,height[j])-height[i];
                i++;

            }
            else{
                m2 = max(m2,height[j]);
                ans+=min(m2,height[i])-height[j];
                j--;
            }   
        }
        return ans;
    }
};
