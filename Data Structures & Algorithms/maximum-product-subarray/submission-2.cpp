class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int p=0;
        int i=0;
        if (n==1 && nums[0]<0) return nums[0];
        bool f=false;
        int maxi=nums[0];
        for (int i=1;i<n; i++){
            maxi=max(maxi,nums[i]);
            if (nums[i]*nums[i-1]>0){
                f=true;
                break;
            }
        }
        if (!f && maxi==0) return 0;
        while (i<n){
            while (i<n && nums[i]==0) i++;
            int j=i;
            int cur=1;
            int f1=0, f2=0;
            while (j<n && nums[j]!=0){
                if(nums[j]<0 && f1==0) f1 = cur*nums[j];
                cur*=nums[j];
                if (nums[j]<0) f2 = cur/nums[j];
                j++;
            }
            j--;
            if (cur>0)p =max(p,cur);
            else{
                int num1 = max(cur/f1 , f2);
                p= max(p,num1);
            }
            i=j+1;
        }
        return p;
    }
};
